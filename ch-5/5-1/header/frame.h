#ifndef FRAME_H
#define FRAME_H

#include <algorithm>
#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&,
                               const std::string, const int);
std::vector<std::string> frame(const std::vector<std::string>&, const char,
                               const std::string, const int);

std::vector<std::string> vcat(const std::vector<std::string>&,
                              const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&,
                              const std::vector<std::string>&);

#endif // FRAME_H
