// a3_sol.cpp

#include "JingleNet.h"
#include "JingleNet_announcer.h"
#include "Queue.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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

// Returns true if s starts with prefix, and false otherwise.
bool starts_with(const string &s, const string &prefix)
{
    return first_word(s) == prefix;
}

void parse_line(const string &line, JingleNet &jnet)
{
    if (starts_with(line, "SEND"))
    {
        string s = strip_first_word(line);
        string sender = first_word(s);
        s = strip_first_word(s);
        Rank rank = to_rank(first_word(s));
        string message = strip_first_word(s);
        Announcement m(sender, rank, message);
        cout << "Sending " << m.to_string() << endl;
        jnet.send(m);
    }
    else if (starts_with(line, "REMOVE_ALL"))
    {
        string sender = strip_first_word(line);
        cout << "Removing all from " << sender << endl;
        jnet.remove_all(sender);
        cout << jnet.to_string() << endl;
    }
    else if (starts_with(line, "PROMOTE_ANNOUNCEMENTS"))
    {
        string sender = strip_first_word(line);
        cout << "Promoting all from " << sender << endl;
        jnet.promote_announcements(sender);
    }
    else if (starts_with(line, "ANNOUNCE"))
    {
        int n = stoi(strip_first_word(line));
        cout << "Announcing " << n << " announcements" << endl;
        jnet.announce(n);
    }
    else
    {
        cout << "Unknown command error: " << line << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    string filename = argv[1];
    cout << "Printing " << filename << " ..." << endl;
    ifstream in(filename);
    string line;
    JingleNet jnet;
    while (getline(in, line))
    {
        parse_line(line, jnet);
    }
} // main
