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

using std::vector;

int main()
{

    vector<string> page;
    vector<Line> lines;
    vector<WordPermutation> all_permutations;

    cout << "Page content:" << endl;
    cout << "-------------" << endl;
    cout << endl;

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

    // Step 3.1: Create a Permutation Table struct that contains each column as
    // a vector of strings.
    // Also include headers for the columns
    PermutationTable table = create_permutation_table(all_permutations);

    // Step 3.2 Concatenate for final display
    vector<string> disp;
    disp = hcat(table.left_text_frame, table.index_word_frame);
    disp = hcat(disp, table.right_text_frame);
    disp = hcat(disp, table.word_num_frame);
    disp = hcat(disp, table.word_line_frame);

    // 3.4 Print out final result

    cout << endl;
    cout << "Permutaiton Index:" << endl;
    cout << endl;
    for (vector<string>::size_type i = 0; i != disp.size(); ++i)
    {
        cout << disp[i] << endl;
    }

    return 0;
}
