// Write a function that reads words from an input stream
// and stores them in a vector. Use that function both to
// - write programs that count the number of words in the input, and to
// - count how many times each word occurred.
#include "WordCounter.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int num_words;
    int num_distinct_words;

    // Ask the user the input the strings
    cout << "Please enter the strings, followed by end-of-file:" << endl;

    // Read and store the words into a vector
    vector<string> words;
    read_words(cin, words);

    num_words = count_words(words);
    cout << "Number of words: " << num_words << endl;

    num_distinct_words = count_unique_words(words);
    cout << "Number of unique words: " << num_distinct_words << endl;

    return 0;
}