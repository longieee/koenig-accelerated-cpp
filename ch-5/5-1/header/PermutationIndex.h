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

    // Equality operator, for gtest
    bool operator==(const WordPermutation& other) const
    {
        return line_number == other.line_number &&
               word_number == other.word_number &&
               index_word == other.index_word && text == other.text &&
               left_text == other.left_text && right_text == other.right_text;
    }
};

struct Line
{
    std::vector<std::string> text;
    int line_number;

    // Equality operator, for gtest
    bool operator==(const Line& other) const
    {
        return line_number == other.line_number &&
               text == other.text; // Compare relevant fields
    }
};

struct PermutationTable
{
    std::vector<std::string> left_text_frame, index_word_frame,
        right_text_frame, word_num_frame, word_line_frame;

    // Equality operator, for gtest
    bool operator==(const PermutationTable& other) const
    {
        return left_text_frame == other.left_text_frame &&
               index_word_frame == other.index_word_frame &&
               right_text_frame == other.right_text_frame &&
               word_num_frame == other.word_num_frame &&
               word_line_frame == other.word_line_frame;
    }
};

std::vector<std::string> read_page(std::istream&);
std::vector<Line> split_raw_page(std::vector<std::string>&);
std::vector<WordPermutation> create_permutations(const Line&);
std::vector<std::string> rotate(const std::vector<std::string>&, int);
std::vector<std::string> slice(const std::vector<std::string>&, int, int);
bool compare(const WordPermutation&, const WordPermutation&);
std::string read_column(const std::vector<std::string>&);
PermutationTable create_permutation_table(const std::vector<WordPermutation>&);

#endif
