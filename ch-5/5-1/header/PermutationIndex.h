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
    std::vector<std::string> left_text;
    std::vector<std::string> right_text;
};

struct Line
{
    std::vector<std::string> text;
    int line_number;
};

std::vector<std::string> read_page(std::istream&);
std::vector<Line> split_raw_page(std::vector<std::string>&);
std::vector<WordPermutation> create_permutations(const Line&);
std::vector<std::string> rotate(const std::vector<std::string>&, int);
std::vector<std::string> slice(const std::vector<std::string>&, int, int);
bool compare(const WordPermutation&, const WordPermutation&);
std::string read_column(const std::vector<std::string>&);

#endif