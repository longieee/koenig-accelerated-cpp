/**
 * @file PermutationIndex.cpp
 * @brief Implementation file for the PermutationIndex class.
 */

#include "../header/PermutationIndex.h"

#include "../header/split.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>

using std::getline;
using std::istream;
using std::string;
using std::vector;

/**
 * Reads the contents of a page from the input stream and stores each line in a
 * vector.
 *
 * @param is The input stream to read from.
 * @param page The name of the page being read.
 * @return A vector containing all the lines of the page.
 */
vector<string> read_page(istream& is, string page)
{
    string line;
    vector<string> all_lines;

    while (getline(is, line))
    {
        all_lines.push_back(line);
    }

    return all_lines;
}

/**
 * Splits the raw page into lines and assigns line numbers to each line.
 *
 * @param page The raw page to be split.
 * @return A vector of Line objects, each representing a line of the page.
 */
vector<Line> split_raw_page(vector<string>& page)
{
    vector<string>::iterator iter = page.begin();
    vector<Line> splitted_page;
    int count = 1;

    while (iter != page.end())
    {
        Line line;

        line.text = split(*iter);
        line.line_number = count;

        splitted_page.push_back(line);

        count++;
        iter++;
    }

    return splitted_page;
}

/**
 * Rotates "clockwise" the elements of a vector by a given index.
 *
 * @param v The vector to be rotated.
 * @param idx The index by which the vector elements should be rotated.
 * @return The rotated vector.
 */
vector<string> rotate(const vector<string>& v, int idx)
{

    vector<string> rotated;

    typedef vector<string>::size_type sz;
    sz len = v.size();

    for (sz i = 0; i < len; ++i)
    {
        int rotated_idx = (i + idx) % len;
        rotated.push_back(v[rotated_idx]);
    }

    return rotated;
}

/**
 * Creates all possible permutations of words in a line.
 *
 * @param line The line to create permutations for.
 * @return A vector of WordPermutation objects, each representing a word
 * permutation in the line.
 */
vector<WordPermutation> create_permutations(const Line& line)
{
    vector<WordPermutation> permutes;
    vector<string>::size_type line_sz = line.text.size();
    int rotation_idx = 0;

    vector<string>::const_iterator iter = line.text.begin();
    while (iter != line.text.end())
    {
        WordPermutation perm;

        perm.text = rotate(line.text, rotation_idx);
        perm.index_word = perm.text[0];
        perm.line_number = line.line_number;
        perm.word_number = rotation_idx;

        permutes.push_back(perm);

        // Next permutation
        rotation_idx++;
        iter++;
    }

    return permutes;
}