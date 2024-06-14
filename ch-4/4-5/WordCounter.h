#ifndef GUARD_WordCounter_h
#define GUARD_WordCounter_h
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::istream& read_words(std::istream&, std::vector<std::string>&);
int count_words(const std::vector<std::string>&);
int count_unique_words(const std::vector<std::string>&);
bool is_distinct(std::vector<std::string>, std::string);

#endif