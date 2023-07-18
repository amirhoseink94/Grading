// Wordlist_sol.h

#pragma once

//
// Sample solution for Assignment 1.
//

#include "Wordlist_base.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string quote(const string &s)
{
    return "\"" + s + "\"";
}

class Wordlist : public Wordlist_base
{
    struct Node
    {
        string word;
        int count = 1;
        Node *next = nullptr;
    };

    Node *head = nullptr;
    int num_nodes = 0;

    // Return a pointer to the Node with word w, or a pointer to the node before
    // the word before where w should be inserted. If w should be inserted at
    // the beginning of the list, return nullptr.
    Node *find(const string &w) const
    {
        Node *p = head;
        Node *prev = nullptr;
        while (p != nullptr && p->word < w)
        {
            prev = p;
            p = p->next;
        }
        if (p != nullptr && p->word == w)
        {
            return p;
        }
        return prev;
    }

public:
    // default constructor: creates an empty Wordlist
    Wordlist()
    {
    }

    // Read all the words from the file and add them to the word list.
    Wordlist(const string &filename)
    {
        ifstream infile(filename);
        string word;
        while (infile >> word)
        {
            add_word(word);
        }
    }

    // destructor: delete all nodes
    ~Wordlist()
    {
        Node *p = head;
        while (p != nullptr)
        {
            Node *next = p->next;
            delete p;
            p = next;
        }
    }

    // Returns the number of times w occurs as a word in the list.
    int get_count(const string &w) const
    {
        Node *p = find(w);
        if (p != nullptr && p->word == w)
        {
            return p->count;
        }
        return 0;
    }

    // // Returns true if w is in the word list, false otherwise.
    // bool contains(const string &w) const
    // {
    //     return get_count(w) > 0;
    // }

    // Returns the number of nodes in the list.
    int num_different_words() const
    {
        return num_nodes;
    }

    // Returns the total number of words in the list, i.e. the sum of the node
    // counts.
    int total_words() const
    {
        int total = 0;
        Node *p = head;
        while (p != nullptr)
        {
            total += p->count;
            p = p->next;
        }
        return total;
    }

    // Returns true if the words in the list are in ascending sorted order,
    // false otherwise.
    bool is_sorted() const
    {
        Node *p = head;
        while (p != nullptr && p->next != nullptr)
        {
            if (p->word > p->next->word)
            {
                return false;
            }
            p = p->next;
        }
        return true;
    }

    // Returns a string of the most frequent word in the format "word freq".
    // If there is a tie, return the first word in the list.
    string most_frequent() const
    {
        Node *p = head;
        Node *max = p;
        while (p != nullptr)
        {
            if (p->count > max->count)
            {
                max = p;
            }
            p = p->next;
        }
        return max->word + " " + to_string(max->count);
    }

    // Returns the number of nodes with count 1.
    int num_singletons() const
    {
        int count = 0;
        Node *p = head;
        while (p != nullptr)
        {
            if (p->count == 1)
            {
                count++;
            }
            p = p->next;
        }
        return count;
    }

    // Adds w to the word list. If w is already in the list, then increment its
    // count, otherwise add a new Node at the alphabetically correct location,
    // with count 0.
    void add_word(const string &w)
    {
        Node *p = find(w);
        if (p == nullptr)
        {
            head = new Node{w, 1, head};
            num_nodes++;
        }
        else if (p->word == w)
        {
            p->count++;
        }
        else
        {
            Node *new_word = new Node{w};
            new_word->next = p->next;
            p->next = new_word;
            num_nodes++;
        }
        assert(is_sorted());
    }

    // void print_stats() const
    // {
    //     cout << "Number of different words: " << num_different_words() << endl;
    //     cout << "    Total number of words: " << total_words() << endl;
    //     cout << "       Most frequent word: " << most_frequent() << endl;
    //     cout << "     Number of singletons: " << num_singletons()
    //          << " (" << 100.0 * num_singletons() / num_different_words() << "%)"
    //          << endl;
    // }

    void print_words() const
    {
        Node *p = head;
        int i = 1;
        while (p != nullptr)
        {
            cout << i << ". {" << quote(p->word) << ", " << p->count << "}\n";
            p = p->next;
            i++;
        }
    }

    friend ostream &operator<<(ostream &out, const Wordlist &wl);
}; // class Wordlist

ostream &operator<<(ostream &out, const Wordlist &wl)
{
    Wordlist::Node *p = wl.head;
    int i = 1;
    while (p != nullptr)
    {
        out << i << ". {" << quote(p->word) << ", " << p->count << "}\n";
        p = p->next;
        i++;
    }
    return out;
}
