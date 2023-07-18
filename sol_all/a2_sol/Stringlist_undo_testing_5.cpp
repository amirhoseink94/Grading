// Stringlist_undo_testing.cpp

//
// To help with testing student assignments.
//

#include "Stringlist.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

struct Test
{
    string name;
    Test(const string &name)
        : name(name)
    {
        cout << "Calling " << name << " ..." << endl;
    }

    ~Test()
    {
        cout << "... " << name << " done: all tests passed" << endl;
    }
};

void test_copy_constructor()
{
    Test("test_copy_constructor");

    Stringlist lst;
    lst.insert_back("A");
    lst.insert_back("B");
    lst.insert_back("C");
    assert(lst.to_string() == "{\"A\", \"B\", \"C\"}");
    assert(lst.size() == 3);

    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);

    Stringlist lst2(lst);
    assert(lst2.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);
    assert(!lst2.undo());
}

void test_assignment_operator()
{
    Test("test_assignment_operator");

    Stringlist lst;
    Stringlist lst2;
    lst = lst2;
    assert(lst2.empty());
    assert(!lst2.undo());

    assert(lst.empty());
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_back("A");
    lst.insert_back("B");
    lst.insert_back("C");
    assert(lst.to_string() == "{\"A\", \"B\", \"C\"}");
    assert(lst.size() == 3);

    lst2 = lst;

    assert(lst2.to_string() == "{\"A\", \"B\", \"C\"}");
    assert(lst2.size() == 3);
    assert(lst.undo());

    lst.insert_back("D");
    lst.insert_back("E");
    // cout << lst.to_string() << endl;
    assert(lst.to_string() == "{\"A\", \"B\", \"D\", \"E\"}");
    assert(lst.size() == 4);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\", \"D\"}");
    assert(lst.size() == 3);

    lst2 = lst;

    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);
}

void test_set()
{
    Test("test_set");
    Stringlist lst;
    lst.insert_back("A");
    assert(lst.to_string() == "{\"A\"}");
    lst.set(0, "B");
    assert(lst.to_string() == "{\"B\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_front("A");
    assert(lst.to_string() == "{\"A\"}");
    lst.set(0, "B");
    lst.set(0, "C");
    assert(lst.to_string() == "{\"C\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"B\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
}

void test_insert_before()
{
    Test("test_insert_before");
    Stringlist lst;
    lst.insert_before(0, "A");
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_before(0, "A");
    lst.insert_before(1, "B");
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_before(0, "A"); // {"A"}
    lst.insert_before(1, "B"); // {"A", "B"}
    lst.insert_before(0, "C"); // {"C", "A", "B"}
    lst.insert_before(2, "D"); // {"C", "A", "D", "B"}
    assert(lst.undo());
    assert(lst.to_string() == "{\"C\", \"A\", \"B\"}");
    assert(lst.size() == 3);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());
}

void test_insert_back()
{
    Test("test_insert_back");
    Stringlist lst;
    lst.insert_back("A");
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_back("A");
    lst.insert_back("B");
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());

    lst.insert_back("A");
    lst.insert_back("B");
    lst.insert_back("C");
    assert(lst.to_string() == "{\"A\", \"B\", \"C\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());
}

void test_insert_front()
{
    Test("test_insert_front");
    Stringlist lst;
    lst.insert_front("A");
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_front("A");
    lst.insert_front("B");
    assert(lst.to_string() == "{\"B\", \"A\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());

    lst.insert_front("A");
    lst.insert_front("B");
    lst.insert_front("C");
    assert(lst.to_string() == "{\"C\", \"B\", \"A\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"B\", \"A\"}");
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.undo());
    assert(lst.empty());
}

void test_remove_at()
{
    Test("test_remove_at");
    Stringlist lst;
    lst.insert_back("A");
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    lst.remove_at(0);
    assert(lst.empty());
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);

    lst.insert_back("B");
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);
    lst.remove_at(1);
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);
    lst.remove_at(1);
    lst.remove_at(0);
    assert(lst.empty());
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());
}

void test_remove_all()
{
    Test("test_remove_all");
    Stringlist lst;
    assert(lst.empty());
    lst.remove_all();
    assert(lst.empty());
    assert(lst.undo());
    assert(!lst.undo());

    lst.insert_back("A");
    lst.remove_all();
    assert(lst.empty());
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_back("A");
    lst.insert_back("B");
    lst.remove_all();
    assert(lst.empty());
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);

    lst.insert_back("C");
    assert(lst.to_string() == "{\"A\", \"B\", \"C\"}");
    assert(lst.size() == 3);
    lst.remove_all();
    assert(lst.empty());
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\", \"C\"}");
}

void test_remove_first()
{
    Test("test_remove_first");
    Stringlist lst;
    assert(lst.empty());
    assert(!lst.remove_first("A"));
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_back("A");
    assert(lst.remove_first("A"));
    assert(lst.empty());
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    assert(lst.undo());
    assert(lst.empty());
    assert(!lst.undo());

    lst.insert_back("A");
    assert(!lst.remove_first("B"));
    assert(lst.to_string() == "{\"A\"}");
    assert(lst.size() == 1);
    assert(lst.undo());
    assert(lst.to_string() == "{}");
    assert(lst.size() == 0);
    assert(!lst.undo());

    lst.insert_back("A");
    lst.insert_back("B");
    lst.insert_back("A");
    lst.insert_back("B");
    assert(lst.to_string() == "{\"A\", \"B\", \"A\", \"B\"}");
    assert(lst.size() == 4);
    assert(lst.remove_first("B"));
    assert(lst.to_string() == "{\"A\", \"A\", \"B\"}");
    assert(lst.size() == 3);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\", \"A\", \"B\"}");
    assert(lst.size() == 4);
    assert(lst.remove_first("A"));
    assert(lst.to_string() == "{\"B\", \"A\", \"B\"}");
    assert(lst.size() == 3);
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\", \"A\", \"B\"}");
    assert(lst.size() == 4);
    assert(lst.remove_first("A"));
    assert(lst.remove_first("B"));
    assert(lst.to_string() == "{\"A\", \"B\"}");
    assert(lst.size() == 2);
    assert(lst.undo());
    assert(lst.undo());
    assert(lst.to_string() == "{\"A\", \"B\", \"A\", \"B\"}");
}


int main()
{
    /*test_copy_constructor();
    test_assignment_operator();
    test_set();
    test_insert_before();
    test_insert_back();*/
    test_insert_front();
    /*test_remove_at();
    test_remove_all();
    test_remove_first();*/

    cout << "\nAll Stringlist undo marking tests passed!\n";
} // main
