// Write a program to report the length of the longest and shortest string in
// its input.
#include <algorithm>
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
    cout << "Please enter a string, followed by an end-of-file: ";

    vector<string> input_string;
    typedef vector<string>::size_type vec_sz;
    string s;
    string longest_string;
    int longest_length = 0;

    while (cin >> s)
    {
        input_string.push_back(s);
    }
    vec_sz size = input_string.size();

    if (size == 0)
    {
        cout << "You must enter a string." << endl;
        // Exit with error
        return 1;
    }

    // Let the longest string be the first one on the list
    longest_string = input_string[0];
    longest_length = input_string[0].size();

    // Now loop through the rest of the vector to find the longest string
    // If there are ties, return only the first string.
    for (int i = 1; i < size; i++)
    {
        if (input_string[i].size() > longest_length)
        {
            longest_string = input_string[i];
            longest_length = input_string[i].size();
        }
    }

    cout << "The longest string in the input is '" << longest_string
         << "' with length " << longest_length << endl;

    return 0;
}
