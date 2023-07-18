// a1_main_sol.cpp

#include "Wordlist.h"

void test_wordlist()
{
    Wordlist wl;
    assert(wl.num_different_words() == 0);
    assert(wl.total_words() == 0);
    assert(wl.is_sorted());
    assert(!wl.contains("hello"));

    wl.add_word("zoo");
    assert(wl.num_different_words() == 1);
    assert(wl.total_words() == 1);
    assert(wl.is_sorted());
    assert(wl.contains("zoo"));
    assert(!wl.contains("hello"));

    wl.add_word("zoo");
    assert(wl.num_different_words() == 1);
    assert(wl.total_words() == 2);
    assert(wl.is_sorted());
    assert(wl.contains("zoo"));
    assert(!wl.contains("hello"));

    wl.add_word("hello");
    assert(wl.num_different_words() == 2);
    assert(wl.total_words() == 3);
    assert(wl.is_sorted());
    assert(wl.contains("zoo"));
    assert(wl.contains("hello"));
    assert(!wl.contains("world"));

    wl.add_word("world");
    assert(wl.num_different_words() == 3);
    assert(wl.total_words() == 4);
    assert(wl.is_sorted());
    assert(wl.contains("zoo"));
    assert(wl.contains("hello"));
    assert(wl.contains("world"));

    wl.add_word("hello");
    assert(wl.num_different_words() == 3);
    assert(wl.total_words() == 5);
    assert(wl.is_sorted());
    assert(wl.contains("zoo"));
    assert(wl.contains("hello"));
    assert(wl.contains("world"));
    assert(!wl.contains("shoe"));

    wl.add_word("zoo");
    assert(wl.num_different_words() == 3);
    assert(wl.total_words() == 6);
    assert(wl.is_sorted());
    assert(wl.contains("zoo"));
    assert(wl.contains("hello"));
    assert(wl.contains("world"));
    assert(!wl.contains("shoe"));

    //cout << wl << endl;
    wl.print_words();
}

// Read words, one at a time from cin, into a Wordlist and print the stats.
void test_read()
{
    Wordlist lst;
    string w;
    while (cin >> w)
    {
        lst.add_word(w);
    }

    lst.print_words();
    cout << endl;
    lst.print_stats();
}

void test_read_file(const string &filename)
{
    cout << "Reading " << filename << " ... " << endl;
    Wordlist lst(filename);
    lst.print_stats();
}

//
// About 350s if run with valgrind and -O3.
//
// ❯ time ./a1_sol < tiny_shakespeare.txt
//
// Number of different words: 25670
// Total number of words: 202651
//
// ________________________________________________________
// Executed in   59.96 secs   fish           external
//    usr time   59.91 secs    0.00 micros   59.91 secs
//    sys time    0.00 secs  441.00 micros    0.00 secs

int main()
{
    test_wordlist();
    // test_read();
    test_read_file("small.txt");
    cout << endl;
    test_read_file("time_machine1.txt");
}

