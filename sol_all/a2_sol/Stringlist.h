// Stringlist_sol.h

//
// Rules
//
// - Do not delete any methods, or change the signatures of any methods.
// - You can add other methods if you like, either private or public.
// - You can change the implementation of existing methods if necessary. They
//   should still work the same way.
// - Implement undo() using a private stack. Please implement the stack yourself
//   as a singly-linked list. Do not use arrays, vectors, or any other data
//   structure for your stack.
//

#pragma once

#include "Stack_sol.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

constexpr bool DBG = false;

class Stringlist;
ostream &operator<<(ostream &os, const Stringlist &lst);

class Stringlist
{
    int cap;     // capacity
    string *arr; // array of strings
    int sz;      // size

    Stack undo_stack;
    //
    // helper function for throwing out_of_range exceptions
    //
    void bounds_error(const string &s) const
    {
        throw out_of_range("Stringlist::" + s + " index out of bounds");
    }

    //
    // helper function for checking index bounds
    //
    void check_bounds(const string &s, int i) const
    {
        if (i < 0 || i >= sz)
            bounds_error(s);
    }

    //
    // helper function for copying another array of strings
    //
    void copy(const string *other)
    {
        for (int i = 0; i < sz; i++)
        {
            arr[i] = other[i];
        }
    }

    //
    // helper function for checking capacity; doubles size of the underlying
    // array if necessary
    //
    void check_capacity()
    {
        if (sz == cap)
        {
            cap *= 2;
            string *temp = new string[cap];
            for (int i = 0; i < sz; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
    }

    //
    // Apply Setval to the list.
    //
    // Note that the undo actions call not-undo-able versions of remove_at and
    // insert_before.
    //
    void apply(const Setval &sv)
    {
        switch (sv.act)
        {
        case Action::SET:
            assert(sv.index >= 0 && sv.index < sz);
            arr[sv.index] = sv.value;
            break;
        case Action::REMOVE:
            assert(sv.index >= 0 && sv.index < sz);
            remove_at_no_undo(sv.index);
            break;
        case Action::INSERT:
            assert(sv.index >= 0 && sv.index <= sz);
            insert_before_no_undo(sv.index, sv.value);
            break;
        case Action::OVERWRITE:
            delete[] arr;
            sz = sv.size;
            cap = sv.cap;
            arr = sv.arr;
            break;
        default:
            throw runtime_error("invalid Setval type");
        }
    }

    //
    // Removes the string at the given index; doesn't change the capacity.
    // Doesn't modify the undo stack.
    //
    void remove_at_no_undo(int index)
    {
        check_bounds("remove_at_no_undo", index);
        for (int i = index; i < sz - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        sz--;
    }

    //
    // Insert s before index; if necessary, the capacity of the underlying array
    // is doubled. Doesn't modify the undo stack.
    //
    void insert_before_no_undo(int index, const string &s)
    {
        if (index < 0 || index > sz) // allows insert at end, i == sz
            bounds_error("insert_before_no_undo");
        check_capacity();

        for (int i = sz; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = s;
        sz++;
    }

public:
    //
    // default constructor: makes an empty StringList
    //
    Stringlist()
        : cap(10), arr(new string[cap]), sz(0)
    {
    }

    //
    // Copy constructor: makes a copy of the given StringList.
    //
    // Does **not** copy the undo stack.
    //
    Stringlist(const Stringlist &other)
        : cap(other.cap), arr(new string[cap]), sz(other.sz)
    {
        copy(other.arr);
    }

    //
    // destructor
    //
    ~Stringlist()
    {
        delete[] arr;

        // de-allocate any arrays saved on the undo stack
        while (!undo_stack.empty())
        {
            if (undo_stack.peek().act == Action::OVERWRITE)
            {
                delete[] undo_stack.peek().arr;
            }
            undo_stack.pop();
        }
    }

    void print_debug() const
    {
        cout << "cap: " << cap << endl;
        cout << " sz: " << sz << endl;
        cout << "arr: ";
        for (int i = 0; i < sz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    //
    // Assignment operator: makes a copy of the given StringList.
    //
    // undoable
    //
    // The assignment does **not** copy the undo stack of other. Instead, the
    // current list has its undo stack updated to reflect the changes made by
    // the assignment. For example:
    //
    //     // lst1 == {"a", "b", "c"}
    //     // lst2 == {"d", "e"}
    //
    //     lst2.remove_at(0); // lst2 == {"e"}
    //     lst1 = lst2;       // lst1 == {"e"}
    //
    //     lst2.undo();       // lst2 == {"d", "e"}
    //     lst1.undo();       // lst1 == {"a", "b", "c"}
    //
    Stringlist &operator=(const Stringlist &other)
    {
        if (this != &other)
        {
            // Before deleting the array, we save it on the undo stack.
            undo_stack.push(make_OVERWRITE(arr, sz, cap));
            // delete[] arr;
            cap = other.capacity();
            arr = new string[cap];
            sz = other.size();
            copy(other.arr);
        }
        return *this;
    }

    //
    // Returns the number of strings in the list.
    //
    int size() const { return sz; }

    //
    // Returns true if the list is empty, false otherwise.
    //
    bool empty() const { return size() == 0; }

    //
    // Returns the capacity of the list, i.e. the size of the underlying array.
    //
    int capacity() const { return cap; }

    //
    // Returns the string at the given index.
    //
    string get(int index) const
    {
        check_bounds("get", index);
        return arr[index];
    }

    //
    // Returns the index of the first occurrence of s in the list, or -1 if s is
    // not in the lst.
    //
    int index_of(const string &s) const
    {
        for (int i = 0; i < sz; i++)
        {
            if (arr[i] == s)
            {
                return i;
            }
        }
        return -1;
    }

    //
    // Returns true if s is in the list, false otherwise.
    //
    bool contains(const string &s) const
    {
        return index_of(s) != -1;
    }

    //
    // Sets the string at the given index.
    //
    // undoable
    //
    void set(int index, string value)
    {
        check_bounds("set", index);
        undo_stack.push(make_SET(index, arr[index]));
        arr[index] = value;
    }

    //
    // Insert s before index; if necessary, the capacity of the underlying array
    // is doubled.
    //
    // undoable
    //
    void insert_before(int index, const string &s)
    {
        if (index < 0 || index > sz) // allows insert at end, i == sz
            bounds_error("insert_before");
        check_capacity();

        if (index == 0)
            undo_stack.push(make_REMOVE(0));
        else
            undo_stack.push(make_REMOVE(index));

        insert_before_no_undo(index, s);
    }

    //
    // Appends s to the end of the list; if necessary, the capacity of the
    // underlying array is doubled.
    //
    // undoable
    //
    void insert_back(const string &s)
    {
        insert_before(size(), s);
    }

    //
    // Inserts s at the front of the list; if necessary, the capacity of the
    // underlying array is doubled.
    //
    // undoable
    //
    void insert_front(const string &s)
    {
        insert_before(0, s);
    }

    //
    // Removes the string at the given index; doesn't change the capacity.
    //
    // undoable
    //
    void remove_at(int index)
    {
        check_bounds("remove_at", index);
        undo_stack.push(make_INSERT(index, arr[index]));
        remove_at_no_undo(index);
    }

    //
    // Removes all strings from the list; doesn't change the capacity.
    //
    // undoable
    //
    // When this us undone, *all* removed elements are returned at once.
    //
    void remove_all()
    {
        // Before deleting the array, we save it on the undo stack.
        undo_stack.push(make_OVERWRITE(arr, sz, cap));

        cap = 10;
        arr = new string[cap];
        sz = 0;
    }

    //
    // Removes the first occurrence of s in the list, and returns true. If s is
    // nowhere in the list, nothing is removed and false is returned.
    //
    // undoable
    //
    bool remove_first(const string &s)
    {
        int index = index_of(s);
        if (index == -1)
            return false;
        remove_at(index);
        return true;
    }

    //
    // Removes all occurrences of s in the list, and returns the number of items
    // removed.
    //
    // undoable
    //
    int remove_all(const string &s)
    {
        int count = 0;
        for (int i = 0; i < sz; i++)
        {
            if (arr[i] == s)
            {
                remove_at(i);
                count++;
                i--;
            }
        }
        return count;
    }

    //
    // Undoes the last operation that modified the list. Returns true if a
    // change was undone, false otherwise.
    //
    bool undo()
    {
        if (DBG)
            cout << "----Undo called----\n";
        if (DBG)
            cout << "  Before undo: " << *this << endl;
        if (DBG)
            cout << "   undo stack: " << undo_stack << endl;

        if (undo_stack.empty())
        {
            if (DBG)
                cout << "  Nothing to undo" << endl;
            if (DBG)
                cout << "  After undo: " << *this << endl;
            if (DBG)
                cout << "-------------------\n";
            return false;
        }

        Setval top = undo_stack.peek();
        apply(top);
        undo_stack.pop();

        if (DBG)
            cout << "  After undo: " << *this << endl;
        if (DBG)
            cout << "  undo stack: " << undo_stack << endl;
        if (DBG)
            cout << "-------------------\n";
        
        assert(cap >= sz);
        return true;
    }

    //
    // Returns the current number of undoable operations.
    //
    int num_undoable() const
    {
        cout << "num_undoable called: students don't need to implement this\n";
        return undo_stack.size();
    }

    //
    // Prints contents of the undo stack to cout.
    //
    void print_undo_stack() const
    {
        cout << "print_undo_stack called: students don't need to implement this\n";
        cout << "Stringlist::undo_stack: " << undo_stack << endl;
    }

    //
    // Returns a string representation of the list.
    //
    string to_string() const
    {
        string result = "{";
        for (int i = 0; i < size(); i++)
        {
            if (i > 0)
                result += ", ";
            result += "\"" + get(i) + "\"";
        }
        return result + "}";
    }

}; // class Stringlist

//
// Prints list to in the format {"a", "b", "c"}.
//
ostream &operator<<(ostream &os, const Stringlist &lst)
{
    return os << lst.to_string();
}

//
// Returns true if the two lists are equal, false otherwise.
//
// Does *not* consider any undo information when comparing two Stringlists. All
// that matters is that they have the same strings in the same order.
//
bool operator==(const Stringlist &a, const Stringlist &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a.get(i) != b.get(i))
        {
            return false;
        }
    }
    return true;
}

//
// Returns true if the two lists are not equal, false otherwise.
//
// Does *not* consider any undo information when comparing two Stringlists.
//
bool operator!=(const Stringlist &a, const Stringlist &b)
{
    return !(a == b);
}
