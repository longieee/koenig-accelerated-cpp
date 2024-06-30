/**
 * @file PermutationIndex.cpp
 * @brief Implementation file for the PermutationIndex class.
 */

#include "../header/PermutationIndex.h"
#include "../header/frame.h"
#include "../header/split.h"

#include <istream>
#include <string>
#include <vector>

using std::getline;
using std::istream;
using std::min;
using std::max;
using std::string;
using std::to_string;
using std::vector;

/**
 * Reads the contents of a page from the input stream and stores each line in a
 * vector.
 *
 * @param is The input stream to read from.
 * @return A vector containing all the lines of the page.
 */
vector<string> read_page(istream& is)
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
        perm.word_number = rotation_idx + 1;

        // Get the surrounding texts of the index_word

        // If the texts are too long, crop it
        perm.left_text = slice(line.text, max(0, rotation_idx - 5), rotation_idx);
        perm.right_text = slice(line.text, rotation_idx + 1,
                                min(rotation_idx + 6, static_cast<int>(line.text.size())));

        permutes.push_back(perm);

        // Next permutation
        rotation_idx++;
        iter++;
    }

    return permutes;
}

/**
 * Compares two WordPermutation objects based on their index_word,
 * line_number, and word_number.
 *
 * @param x The first WordPermutation object to compare.
 * @param y The second WordPermutation object to compare.
 * @return true if x is less than y, false otherwise.
 */
bool compare(const WordPermutation& x, const WordPermutation& y)
{
    if (x.index_word < y.index_word)
    {
        return true;
    }
    // For the same word, we prioritize the line number
    else if (x.index_word == y.index_word)
    {
        if (x.line_number < y.line_number)
        {
            return true;
        }
        // For the same line, we prioritize the words appearing first
        else if (x.line_number == y.line_number)
        {
            // No 2 words on the same line have the same word_number
            return x.word_number < y.word_number;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/**
 * Returns a sliced vector of strings from the given vector.
 *
 * @param v The vector of strings to be sliced.
 * @param start The starting index of the slice.
 * @param end The ending index of the slice.
 * @return A sliced vector of strings from the given vector.
 */
vector<string> slice(const vector<string>& v, int start, int end)
{
    vector<string> ret;

    typedef vector<string>::const_iterator iter;
    // Ensure the start and end positions are within the vector's range
    iter start_it = v.begin() + min(start, static_cast<int>(v.size()));
    iter end_it = v.begin() + min(end, static_cast<int>(v.size()));

    // Constructing the sliced vector from start_it to end_it by copying the
    // items
    ret = vector<string>(start_it, end_it);

    return ret;
}

/**
 * Reads the content of a column from a vector of strings and returns it as a
 * single string.
 *
 * @param v The vector of strings representing the column.
 * @return The content of the column as a single string.
 */
string read_column(const vector<string>& v)
{
    string column_content;
    vector<string>::const_iterator iter = v.begin();

    while (iter != v.end())
    {
        column_content += (*iter + ' ');
        iter++;
    }

    return column_content;
}

PermutationTable
create_permutation_table(const vector<WordPermutation>& permutations)
{
    vector<WordPermutation>::const_iterator iter = permutations.begin();
    PermutationTable table;
    vector<string> left_text_col, index_word_col, right_text_col, word_num_col,
        word_line_col;
    while (iter != permutations.end())
    {
        left_text_col.push_back(read_column(iter->left_text));
        index_word_col.push_back(iter->index_word);
        right_text_col.push_back(read_column(iter->right_text));
        word_num_col.push_back(to_string(iter->word_number));
        word_line_col.push_back(to_string(iter->line_number));
        iter++;
    }
    // Create and insert headers into the texts to create the frame
    vector<string> left_text_header = {" ", string(width(left_text_col), '*')},
                   index_word_header = {"Index",
                                        string(width(index_word_col), '*')},
                   right_text_header = {" ",
                                        string(width(right_text_col), '*')},
                   word_num_header = {"Pos", string(3, '*')},
                   word_line_header = {"Line", string(4, '*')};

    // insert headers to the columns content
    left_text_col.insert(left_text_col.begin(), left_text_header.begin(),
                         left_text_header.end());
    index_word_col.insert(index_word_col.begin(), index_word_header.begin(),
                          index_word_header.end());
    right_text_col.insert(right_text_col.begin(), right_text_header.begin(),
                          right_text_header.end());
    word_num_col.insert(word_num_col.begin(), word_num_header.begin(),
                        word_num_header.end());
    word_line_col.insert(word_line_col.begin(), word_line_header.begin(),
                         word_line_header.end());

    // frame creation
    table.left_text_frame = frame(left_text_col, '*', "right", 4);
    table.index_word_frame = frame(index_word_col, "left", 4);
    table.right_text_frame = frame(right_text_col, '*', "left", 4);
    table.word_num_frame = frame(word_num_col, "left", 2);
    table.word_line_frame = frame(word_line_col, '*', "left", 2);

    return table;
}
