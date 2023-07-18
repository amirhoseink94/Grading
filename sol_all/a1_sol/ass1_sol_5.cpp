// a1_main_sol.cpp

#include "Wordlist.h"
void test_wordlist_all();
void test_wordlist_1();
void test_wordlist_2();
void test_wordlist_3();
void test_wordlist_4();
void test_wordlist_5();
void test_wordlist_6();

void test_read();
void test_read_file(const string &filename);

int main()
{
    /*test_wordlist_1();
    test_wordlist_2();
    test_wordlist_3();
    test_wordlist_4();*/
    test_wordlist_5();
    /*test_wordlist_6();
    // test_read();
    test_read_file("small.txt");
    cout << endl;
    test_read_file("time_machine1.txt");*/
}

void test_wordlist_all()
{
    Wordlist wl;

	// Test Case 1
	cout << "Test case 1:\nJust checking if functions are working with empty Wordlist" << endl;
	assert(wl.num_different_words() == 0);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 0);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(!wl.contains("hello"));
	cout << "Passed!" << endl;
	
	cout << "Test 1 is PASSED!" << endl;
	cout <<"__________________" << endl;

	// Test Case 2
	cout << "Test case 2:\nAdding the world (zoo) then checking the functions, \nchecking for another word (hello) at the end" << endl;
	wl.add_word("zoo");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 1);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 1);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(!wl.contains("hello"));
	cout << "Passed!" << endl;
	
	cout << "Test 2 is PASSED!" << endl;
	cout <<"__________________" << endl;

	// Test Case 3
	cout << "Test case 3:\nAdding another (zoo) then checking the functions, \nchecking for another word (hello) at the end" << endl;
	wl.add_word("zoo");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 1);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 2);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(!wl.contains("hello"));
	cout << "Passed!" << endl;
	
	cout << "Test 3 is PASSED!" << endl;
	cout <<"__________________" << endl;

	// Test Case 4
	cout << "Test case 4:\nAdding the word (hello) then checking the functions, \nchecking for another word (world) at the end" << endl;
	wl.add_word("hello");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 2);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 3);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(wl.contains("hello"));
	assert(!wl.contains("world"));
	cout << "Passed!" << endl;
	cout << "Test 4 is PASSED!" << endl;
	cout <<"__________________" << endl;

	// Test Case 5
	cout << "Test case 5:\nAdding the word (world) then checking the functions" << endl;
	wl.add_word("world");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 3);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 4);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(wl.contains("hello"));
	assert(wl.contains("world"));
	cout << "Passed!" << endl;

	cout << "Test 5 is PASSED!" << endl;
	cout <<"__________________" << endl;
	
	// Test Case 6
	cout << "Test case 6:\nAdding another (hello) then checking the functions" << endl;
	wl.add_word("hello");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 3);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 5);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;
	
	cout << "Test 6 is PASSED!" << endl;
	cout <<"__________________" << endl;
    //cout << wl << endl;
    wl.print_words();
}

void test_wordlist_1()
{
    Wordlist wl;

	// Test Case 1
	cout << "Test case 1:\nJust checking if functions are working with empty Wordlist" << endl;
	assert(wl.num_different_words() == 0);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 0);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(!wl.contains("hello"));
	cout << "Passed!" << endl;
	
	cout << "Test 1 is PASSED!" << endl;
	cout <<"__________________" << endl;

}

void test_wordlist_2()
{
    Wordlist wl;


	// Test Case 2
	cout << "Test case 2:\nAdding the world (zoo) then checking the functions, \nchecking for another word (hello) at the end" << endl;
	wl.add_word("zoo");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 1);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 1);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(!wl.contains("hello"));
	cout << "Passed!" << endl;
	
	cout << "Test 2 is PASSED!" << endl;
	cout <<"__________________" << endl;

}

void test_wordlist_3()
{
    Wordlist wl;

	cout << "Test case 3:\nAdding another (zoo) then checking the functions, \nchecking for another word (hello) at the end" << endl;
	wl.add_word("zoo");
	wl.add_word("zoo");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 1);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 2);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(!wl.contains("hello"));
	cout << "Passed!" << endl;
	
	cout << "Test 3 is PASSED!" << endl;
	cout <<"__________________" << endl;

}

void test_wordlist_4()
{
    Wordlist wl;

	cout << "Test case 4:\nAdding the word (hello) then checking the functions, \nchecking for another word (world) at the end" << endl;
	wl.add_word("zoo");
	wl.add_word("zoo");
	wl.add_word("hello");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 2);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 3);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(wl.contains("hello"));
	assert(!wl.contains("world"));
	cout << "Passed!" << endl;
	cout << "Test 4 is PASSED!" << endl;
	cout <<"__________________" << endl;

}

void test_wordlist_5()
{
    Wordlist wl;
	// Test Case 5
	cout << "Test case 5:\nAdding the word (world) then checking the functions" << endl;

	wl.add_word("zoo");
	wl.add_word("zoo");
	wl.add_word("hello");
	wl.add_word("world");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 3);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 4);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;

	cout << "Testing contains()..." << endl;
	assert(wl.contains("zoo"));
	assert(wl.contains("hello"));
	assert(wl.contains("world"));
	cout << "Passed!" << endl;

	cout << "Test 5 is PASSED!" << endl;
	cout <<"__________________" << endl;
	
}

void test_wordlist_6()
{
    Wordlist wl;
	// Test Case 6
	cout << "Test case 6:\nAdding another (hello) then checking the functions" << endl;

	wl.add_word("zoo");
	wl.add_word("zoo");
	wl.add_word("hello");
	wl.add_word("world");
	wl.add_word("hello");
	cout << "Testing num_different_words()..." << endl;
	assert(wl.num_different_words() == 3);
	cout << "Passed!" << endl;

	cout << "Testing total_words()..." << endl;
	assert(wl.total_words() == 5);
	cout << "Passed!" << endl;

	cout << "Testing is_sorted()..." << endl;
	assert(wl.is_sorted());
	cout << "Passed!" << endl;
	
	cout << "Test 6 is PASSED!" << endl;
	cout <<"__________________" << endl;
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
    //Wordlist lst(filename);
    //lst.print_stats();
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


