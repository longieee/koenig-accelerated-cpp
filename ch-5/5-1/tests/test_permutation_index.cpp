#include "../header/PermutationIndex.h"

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

void printline(const vector<string>& s, bool print_separator = false)
{
    vector<string>::const_iterator iter_line = s.begin();
    while (iter_line != s.end())
    {
        cout << *iter_line;
        if (print_separator)
        {
            cout << ", ";
        }
        else
        {
            cout << ' ';
        }
        iter_line++;
    }
    cout << endl;
}

int main()
{

    string s;
    vector<string> page;
    vector<Line> lines;
    vector<WordPermutation> permutations;

    cout << "Page content:" << endl;
    page = read_page(cin, s);
    lines = split_raw_page(page);

    vector<Line>::iterator iter_lines = lines.begin();

    // Print out the raw strings read as Line objects
    while (iter_lines != lines.end())
    {

        cout << "Line number " << iter_lines->line_number << ": ";
        printline(iter_lines->text, true);
        iter_lines++;
    }

    // Print out permutation indexes
    cout << "Permutations: " << endl;
    iter_lines = lines.begin();
    while (iter_lines != lines.end())
    {
        permutations = create_permutations(*iter_lines);
        cout << "Line number " << iter_lines->line_number << ": " << endl;
        vector<WordPermutation>::iterator iter_perm = permutations.begin();
        while (iter_perm != permutations.end())
        {
            printline(iter_perm->text);
            cout << iter_perm->index_word << endl;
            iter_perm++;
        }
        iter_lines++;
    }

    // Print out sorted permutation indexes
    cout << endl;
    cout << "Sorted:" << endl;
    iter_lines = lines.begin();
    while (iter_lines != lines.end())
    {
        sort(permutations.begin(), permutations.end(), compare);
        cout << "Line number " << iter_lines->line_number << ": " << endl;
        vector<WordPermutation>::iterator iter_perm = permutations.begin();
        while (iter_perm != permutations.end())
        {
            cout << "Left: ";
            printline(iter_perm->left_text, false);
            cout << "Index: ";
            cout << iter_perm->index_word << endl;
            cout << "Right: ";
            printline(iter_perm->right_text, false);
            cout << "-------" << endl;
            iter_perm++;
        }
        iter_lines++;
    }

    return 0;
}