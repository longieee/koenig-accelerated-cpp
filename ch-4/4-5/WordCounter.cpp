#include "WordCounter.h"

using std::cout;
using std::endl;
using std::istream;
using std::string;
using std::vector;

istream& read_words(istream& in, vector<string>& words)
{
    if (in)
    {
        // Get rid of the previous words
        words.clear();

        // read input string one by one, and append to vector<string> container
        string word;
        while (in >> word)
        {
            words.push_back(word);
        }

        // clear the stream error status (if any) so that input will work for
        // the next set of inputs
        in.clear();
    }

    return in;
}

int count_words(const vector<string>& words) { return words.size(); }

int count_unique_words(const vector<string>& words)
{
    typedef vector<string>::size_type str_sz;
    int size = count_words(words);
    vector<string> distinct_words;

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

    return distinct_words.size();
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