// test_Queue.cpp

#include "Queue.h"
#include "test.h"
#include <cassert>
#include <fstream>
#include <iostream>

//
// A simple set of tests for checking the correctness of your Queue class.
//
// You can use this, not use this, or modify it any way you like.
//
// WARNING: Keep in mind that just because you pass these tests, or some other
// tests, it does not guarantee that your Queue class is correct. But it does
// help increase confidence that it is correct.
//

void test_Queue1()
{
    Test("test_Queue1");

    Queue q;
    assert(q.size() == 0);
    assert(q.count_user_announcements("greenie") == 0);
    q.remove_all("greenie");
    assert(q.size() == 0);
    assert(q.count_user_announcements("greenie") == 0);

    q.enqueue(Announcement("greenie", Rank::ELF2, "send candy canes"));
    assert(q.size() == 1);
    assert(q.count_user_announcements("greenie") == 1);
    assert(q.count_user_announcements("yumyum") == 0);
    q.remove_all("yumyum");
    assert(q.size() == 1);
    assert(q.count_user_announcements("greenie") == 1);
    assert(q.count_user_announcements("yumyum") == 0);
    q.remove_all("greenie");
    assert(q.size() == 0);
    assert(q.count_user_announcements("greenie") == 0);
    assert(q.count_user_announcements("yumyum") == 0);

    q.enqueue(Announcement("greenie", Rank::ELF2, "send candy canes"));
    assert(q.size() == 1);
    assert(q.count_user_announcements("greenie") == 1);
    assert(q.count_user_announcements("yumyum") == 0);
    assert(q.front() == Announcement("greenie", Rank::ELF2, "send candy canes"));
    q.dequeue();
    assert(q.size() == 0);
    assert(q.count_user_announcements("greenie") == 0);
    assert(q.count_user_announcements("yumyum") == 0);

    q.enqueue(Announcement("greenie", Rank::ELF2, "send candy canes"));
    q.enqueue(Announcement("yumyum", Rank::REINDEER, "peppermint rules"));
    assert(q.size() == 2);
    assert(q.count_user_announcements("greenie") == 1);
    assert(q.count_user_announcements("yumyum") == 1);
    assert(q.front() == Announcement("greenie", Rank::ELF2, "send candy canes"));
    q.dequeue();
    assert(q.size() == 1);
    assert(q.count_user_announcements("greenie") == 0);
    assert(q.count_user_announcements("yumyum") == 1);
    assert(q.front() == Announcement("yumyum", Rank::REINDEER, "peppermint rules"));
    q.dequeue();
    assert(q.size() == 0);
    assert(q.count_user_announcements("greenie") == 0);
    assert(q.count_user_announcements("yumyum") == 0);
    q.remove_all("greenie");
    assert(q.size() == 0);
    assert(q.count_user_announcements("greenie") == 0);
    assert(q.count_user_announcements("yumyum") == 0);

    q.enqueue(Announcement("greenie", Rank::ELF2, "send candy canes"));
    assert(q.size() == 1);

    cout << "all queue tests passed" << endl;
}

// Returns the first word in s.
// e.g. first_word("once upon a time") returns "once"
string first_word(const string &s)
{
    int i = 0;
    while (i < s.size() && s[i] != ' ')
    {
        i++;
    }
    return s.substr(0, i);
}

// Returns the string s with the first word removed.
// e.g. strip_first_word("once upon a time") returns "upon a time"
string strip_first_word(const string &s)
{
    int i = 0;
    while (i < s.size() && s[i] != ' ')
    {
        i++;
    }
    return s.substr(i + 1);
}


void test_Queue2()
{
    Test("test_Queue2");

    Queue q;
    assert(q.size() == 0);

    ifstream infile("send_data.txt");
    string line;
    int count = 0;
    while (getline(infile, line))
    {
        Announcement a(strip_first_word(line));
        q.enqueue(a);
        q.enqueue(a);
        q.enqueue(a);
        q.enqueue(a);
        count += 4;
        assert(q.size() == count);
    }
    cout << "q.size: " << q.size() << endl;
}

int main()
{
    test_Queue1();
    test_Queue2();
}
