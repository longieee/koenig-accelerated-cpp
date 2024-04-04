// Write a program to count how many times each distinct word appears in its
// input.
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool is_distinct(vector<string> distinct_words, string word);

int main()
{
    // Ask user to input their string
    cout << "Please enter a string, followed by an end-of-file: ";
    string input;
    // Store the input
    vector<string> words;
    vector<string> distinct_words;
    typedef vector<string>::size_type vec_sz;

    while (cin >> input)
    {
        words.push_back(input);
    }
    // get the size of the vector
    vec_sz size = words.size();

    // Loop through the vector and count the number of times each word appears
    // This algorithm is O(n^2) because we have to loop through the vector twice
    for (int i = 0; i < size; i++)
    {
        // Check if the word has appeared in the distinct list
        if (is_distinct(distinct_words, words[i]))
        {
            distinct_words.push_back(words[i]);
            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (words[i] == words[j])
                {
                    count++;
                }
            }
            cout << "The word '" << words[i] << "' appears " << count
                 << " time(s)." << endl;
        }
    }

    return 0;
}

// Define a helper function to check whether a word has appeared in the distinct
// list or not
bool is_distinct(vector<string> distinct_words, string word)
{
    for (int i = 0; i < distinct_words.size(); i++)
    {
        if (distinct_words[i] == word)
        {
            return false;
        }
    }
    return true;
}