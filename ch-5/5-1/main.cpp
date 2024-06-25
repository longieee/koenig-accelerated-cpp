// Design and implement a program to produce a permuted index
#include "header/PermutationIndex.h"
#include "header/frame.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::sort;
using std::string;
using std::to_string;
using std::vector;

int main()
{
    vector<string> page;
    vector<Line> lines;
    vector<WordPermutation> all_permutations;

    cout << "Page content:" << endl;
    cout << "-------------" << endl;

    // Step 1: Read the whole page and get all permutations
    page = read_page(cin);
    lines = split_raw_page(page);

    vector<Line>::iterator iter_lines = lines.begin();

    while (iter_lines != lines.end())
    {
        vector<WordPermutation> permutations_from_line =
            create_permutations(*iter_lines);
        all_permutations.insert(all_permutations.end(),
                                permutations_from_line.begin(),
                                permutations_from_line.end());
        iter_lines++;
    }

    // Step 2: Sort the permutations
    sort(all_permutations.begin(), all_permutations.end(), compare);

    // Step 3: Display in correct format
    vector<string> left_text_col, index_word_col, right_text_col, word_num_col,
        word_line_col;
    // 3.1 Read each column content
    vector<WordPermutation>::iterator iter_perm = all_permutations.begin();
    while (iter_perm != all_permutations.end())
    {
        left_text_col.push_back(read_column(iter_perm->left_text));
        index_word_col.push_back(iter_perm->index_word);
        right_text_col.push_back(read_column(iter_perm->right_text));
        word_num_col.push_back(to_string(iter_perm->word_number));
        word_line_col.push_back(to_string(iter_perm->line_number));
    }

    // 3.2 Framing
    vector<string> left_text_frame = frame(left_text_col),
                   index_word_frame = frame(index_word_col),
                   right_text_frame = frame(right_text_col),
                   word_num_frame = frame(word_num_col),
                   word_line_frame = frame(word_line_col);

    // 3.3 Concatenate for final display
    vector<string> disp;
    disp = hcat(left_text_frame, index_word_frame);
    disp = hcat(disp, right_text_frame);
    disp = hcat(disp, word_num_frame);
    disp = hcat(disp, word_line_frame);

    // 3.4 Print out final result
    for (vector<string>::size_type i = 0; i != disp.size(); ++i)
    {
        cout << disp[i] << endl;
    }

    return 0;
}