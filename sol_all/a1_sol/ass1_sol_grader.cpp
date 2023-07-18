// a1_main_sol.cpp

#include "Wordlist.h"

void test_wordlist()
{
    Wordlist wl;
    int num_diff_word_mark = 0, total_word_mark = 0, contain_mark = 0, is_sorted_mark = 0;
    if(!wl.num_different_words() == 0)
    {
    	num_diff_word_mark++;
    }
    if(!wl.total_words() == 0)
    {
    	total_word_mark++;
    }
    if(wl.is_sorted())
    {
    	is_sorted_mark++;
    }
    if(!wl.contains("hello"))
    {
    	contain_mark++;
    }

    wl.add_word("zoo");
    if(wl.num_different_words() == 1)
    {
    	num_diff_word_mark++;
    }
    if(wl.total_words() == 1)
    {
    	total_word_mark++;
    }
    if(wl.is_sorted())
    {
    	is_sorted_mark++;
    }
    if(wl.contains("zoo"))
    {
    	contain_mark++;
    }
    if(!wl.contains("hello"))
    {
    	contain_mark++;
    }

    wl.add_word("zoo");
    if(wl.num_different_words() == 1)
    {
    	num_diff_word_mark++;
    }
    if(wl.total_words() == 2)
    {
    	total_word_mark++;
    }
    if(wl.is_sorted())
    {
    	is_sorted_mark++;
    }
    if(wl.contains("zoo"))
    {
    	contain_mark++;
    }
    if(!wl.contains("hello"))
    {
    	contain_mark++;
    }

    wl.add_word("hello");
    if(wl.num_different_words() == 2)
    {
    	num_diff_word_mark++;
    }
    if(wl.total_words() == 3)
    {
    	total_word_mark++;
    }
    if(wl.is_sorted())
    {
    	is_sorted_mark++;
    }
    if(wl.contains("zoo"))
    {
    	contain_mark++;
    }
    if(wl.contains("hello"))
    {
    	contain_mark++;
    }
    if(!wl.contains("world"))
    {
    	contain_mark++;
    }

    wl.add_word("world");
    if(wl.num_different_words() == 3)
    {
    	num_diff_word_mark++;
    }
    if(wl.total_words() == 4)
    {
    	total_word_mark++;
    }
    if(wl.is_sorted())
    {
    	is_sorted_mark++;
    }
    if(wl.contains("zoo"))
    {
    	contain_mark++;
    }
    if(wl.contains("hello"))
    {
    	contain_mark++;
    }
    if(wl.contains("world"))
    {
    	contain_mark++;
    }

    wl.add_word("hello");
    if(wl.num_different_words() == 3)
    {
    	num_diff_word_mark++;
    }
    if(wl.total_words() == 5)
    {
    	total_word_mark++;
    }
    if(wl.is_sorted())
    {
    	is_sorted_mark++;
    }
    if(wl.contains("zoo"))
    {
    	contain_mark++;
    }
    if(wl.contains("hello"))
    {
    	contain_mark++;
    }
    if(wl.contains("world"))
    {
    	contain_mark++;
    }
    if(!wl.contains("shoe"))
    {
    	contain_mark++;
    }

    wl.add_word("zoo");
    if(wl.num_different_words() == 3)
    {
    	num_diff_word_mark++;
    }
    if(wl.total_words() == 6)
    {
    	total_word_mark++;
    }
    if(wl.is_sorted())
    {
    	is_sorted_mark++;
    }
    if(wl.contains("zoo"))
    {
    	contain_mark++;
    }
    if(wl.contains("hello"))
    {
    	contain_mark++;
    }
    if(wl.contains("world"))
    {
    	contain_mark++;
    }
    if(!wl.contains("shoe"))
    {
    	contain_mark++;
    }

    //cout << wl << endl;
    wl.print_words();
    int total_score = int(num_diff_word_mark/7) * 2 + int(total_word_mark/7)*2 + int(contain_mark/19) * 2 + int(is_sorted_mark/14)* 2;
    cout<<"the total score is:    "<<total_score<<endl;
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

