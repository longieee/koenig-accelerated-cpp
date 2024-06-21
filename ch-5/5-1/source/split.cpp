
#include <cctype>
#include <string>
#include <vector>

#include "../header/split.h"

using std::string;
using std::vector;

using std::isspace;

/**
 * Splits a string into a vector of substrings based on whitespace characters.
 *
 * @param s The string to be split.
 * @return A vector of substrings.
 */
vector<string> split(const string& s)
{
    vector<string> ret;
    typedef vector<string>::size_type str_sz;
    str_sz i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size())
    {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
        {
            ++i;
        }

        // find end of next word
        str_sz j = i;
        // invariant: none of the characters in range [original j, current j) is
        // a space
        while (j != s.size() && !isspace(s[j]))
        {
            ++j;
        }

        // if we found some nonwhitespace characters
        if (i != j)
        {
            // copy from s starting at i and taking j – i chars
            ret.push_back(s.substr(i, j - i));

            // Reset i from the position of j, so that we continue walking
            // forward in the string
            i = j;
        }
    }
    return ret;
}