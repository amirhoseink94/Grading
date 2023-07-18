// Stack_sol.h

#pragma once

#include <cassert>
#include <iostream>

using namespace std;

enum class Action
{
    SET,
    REMOVE,
    INSERT,
    OVERWRITE
};

string quote(const string &s)
{
    return "\"" + s + "\"";
}

struct Setval
{
    Action act;
    int index;
    string value;

    string *arr = nullptr;
    int size;
    int cap;

    string to_string() const
    {
        switch (act)
        {
        case Action::SET:
            return "SET(" + std::to_string(index) + ", " + quote(value) + ")";
        case Action::REMOVE:
            return "REMOVE(" + std::to_string(index) + ")";
        case Action::INSERT:
            return "INSERT(" + std::to_string(index) + ", " + quote(value) + ")";
        case Action::OVERWRITE:
            return "OVERWRITE(" + std::to_string(size) + ", " + std::to_string(cap) + ")";
        default:
            return "UNKNOWN_ACTION";
        }
    }
}; // struct Setval

Setval make_SET(int i, const string &v)
{
    return Setval{Action::SET, i, v, nullptr, -1, -1};
}

Setval make_REMOVE(int i)
{
    return Setval{Action::REMOVE, i, "", nullptr, -1, -1};
}

Setval make_INSERT(int i, const string &v)
{
    return Setval{Action::INSERT, i, v, nullptr, -1, -1};
}

Setval make_OVERWRITE(string *v, int size, int cap)
{
    return Setval{Action::OVERWRITE, -1, "", v, size, cap};
}

ostream &operator<<(ostream &out, const Setval &sv)
{
    return out << sv.to_string();
}

//
// Stack of Setvals.
//

class Stack
{
    struct Node
    {
        Setval act;
        Node *next;
    };

    Node *head;
    int node_count;

    void check_empty() const
    {
        if (empty())
        {
            throw out_of_range("Stack: pop from empty stack");
        }
    }

public:
    //
    // Default constructor: creates an empty stack.
    //
    Stack() : head(nullptr), node_count(0) {}

    //
    // Returns true if the stack is empty, false otherwise.
    //
    bool empty() const { return head == nullptr; }

    //
    // Returns the number of Setvals on the stack.
    //
    int size() const { return node_count; }

    //
    // Puts a Setval on top of the stack.
    //
    void push(const Setval &val)
    {
        head = new Node{val, head};
        node_count++;
    }

    //
    // Removes the Setval on top of the stack. Throws an out_of_range exception
    // if the stack is empty.
    //
    void pop()
    {
        check_empty();
        Node *temp = head;
        head = head->next;
        delete temp;
        node_count--;
    }

    //
    // Return a copy of the Setval on top of the stack. Throws an out_of_range
    // exception if the stack is empty.
    //
    Setval peek() const
    {
        check_empty();
        Setval result = head->act;
        return result;
    }

    //
    // destructor
    //
    ~Stack()
    {
        while (!empty())
        {
            pop();
        }
    }

    //
    // return as string
    //
    string to_string() const
    {
        if (empty())
        {
            return "[empty stack]";
        }
        string s = "[top=";
        Node *p = head;
        while (p != nullptr)
        {
            s += p->act.to_string();
            if (p->next != nullptr)
            {
                s += ", ";
            }
            p = p->next;
        }
        s += "]";
        return s;
    }

}; // class Stack

ostream &operator<<(ostream &out, const Stack &s)
{
    return out << s.to_string();
}
