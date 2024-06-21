#ifndef PERMUTATION_INDEX_H
#define PERMUTATION_INDEX_H

#include <istream>
#include <string>
#include <vector>

struct WordPermutation
{
    std::vector<std::string> text;
    std::string index_word;
    int line_number;
    int word_number;
};

struct Line
{
    std::vector<std::string> text;
    int line_number;
};

std::vector<std::string> read_page(std::istream&, std::string);
std::vector<Line> split_raw_page(std::vector<std::string>&);
std::vector<WordPermutation> create_permutations(const Line&);
std::vector<std::string> rotate(const std::vector<std::string>&, int);
#endif