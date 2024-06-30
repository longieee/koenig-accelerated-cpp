#include "../header/PermutationIndex.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <vector>

using std::istringstream;
using std::sort;
using std::string;
using std::vector;

istringstream INPUT("the quick brown fox\njumps over the lazy dog");
// Read raw page to string vector
vector<string> page = read_page(INPUT);
// Read the string vector to Line objects
vector<Line> lines = split_raw_page(page);
// Read Line objects to permutation objects
vector<WordPermutation> permutations_from_line1 = create_permutations(lines[0]),
                        permutations_from_line2 = create_permutations(lines[1]);

TEST(PermutationTest, BasicPageRead)
{
    vector<string> expected = {"the quick brown fox",
                               "jumps over the lazy dog"};
    EXPECT_EQ(page, expected);
};

TEST(PermutationTest, LineRead)
{
    Line line1 = {{"the", "quick", "brown", "fox"}, 1},
         line2 = {{"jumps", "over", "the", "lazy", "dog"}, 2};
    vector<Line> expected = {line1, line2};

    EXPECT_EQ(expected, lines);
}

TEST(PermutationTest, CreatePermutation)
{
    vector<WordPermutation> expected_line1 =
                                {
                                    {{"the", "quick", "brown", "fox"},
                                     "the",
                                     1,
                                     1,
                                     {},
                                     {"quick", "brown", "fox"}},
                                    {{"quick", "brown", "fox", "the"},
                                     "quick",
                                     1,
                                     2,
                                     {"the"},
                                     {"brown", "fox"}},
                                    {{"brown", "fox", "the", "quick"},
                                     "brown",
                                     1,
                                     3,
                                     {"the", "quick"},
                                     {"fox"}},
                                    {{"fox", "the", "quick", "brown"},
                                     "fox",
                                     1,
                                     4,
                                     {"the", "quick", "brown"},
                                     {}},
                                },
                            expected_line2 = {
                                {{"jumps", "over", "the", "lazy", "dog"},
                                 "jumps",
                                 2,
                                 1,
                                 {},
                                 {"over", "the", "lazy", "dog"}},
                                {{"over", "the", "lazy", "dog", "jumps"},
                                 "over",
                                 2,
                                 2,
                                 {"jumps"},
                                 {"the", "lazy", "dog"}},
                                {{"the", "lazy", "dog", "jumps", "over"},
                                 "the",
                                 2,
                                 3,
                                 {"jumps", "over"},
                                 {"lazy", "dog"}},
                                {{"lazy", "dog", "jumps", "over", "the"},
                                 "lazy",
                                 2,
                                 4,
                                 {"jumps", "over", "the"},
                                 {"dog"}},
                                {{"dog", "jumps", "over", "the", "lazy"},
                                 "dog",
                                 2,
                                 5,
                                 {"jumps", "over", "the", "lazy"},
                                 {}}};

    EXPECT_EQ(expected_line1, permutations_from_line1);
    EXPECT_EQ(expected_line2, permutations_from_line2);
}

TEST(PermutationTest, SortPermutation)
{
    vector<WordPermutation> all_permutations(permutations_from_line1.begin(),
                                             permutations_from_line1.end());

    all_permutations.insert(all_permutations.end(),
                            permutations_from_line2.begin(),
                            permutations_from_line2.end());

    sort(all_permutations.begin(), all_permutations.end(), compare);

    vector<WordPermutation> expected = {
        {{"brown", "fox", "the", "quick"},
         "brown",
         1,
         3,
         {"the", "quick"},
         {"fox"}},
        {{"dog", "jumps", "over", "the", "lazy"},
         "dog",
         2,
         5,
         {"jumps", "over", "the", "lazy"},
         {}},
        {{"fox", "the", "quick", "brown"},
         "fox",
         1,
         4,
         {"the", "quick", "brown"},
         {}},
        {{"jumps", "over", "the", "lazy", "dog"},
         "jumps",
         2,
         1,
         {},
         {"over", "the", "lazy", "dog"}},
        {{"lazy", "dog", "jumps", "over", "the"},
         "lazy",
         2,
         4,
         {"jumps", "over", "the"},
         {"dog"}},
        {{"over", "the", "lazy", "dog", "jumps"},
         "over",
         2,
         2,
         {"jumps"},
         {"the", "lazy", "dog"}},
        {{"quick", "brown", "fox", "the"},
         "quick",
         1,
         2,
         {"the"},
         {"brown", "fox"}},
        {{"the", "quick", "brown", "fox"},
         "the",
         1,
         1,
         {},
         {"quick", "brown", "fox"}},
        {{"the", "lazy", "dog", "jumps", "over"},
         "the",
         2,
         3,
         {"jumps", "over"},
         {"lazy", "dog"}},
    };

    ASSERT_EQ(expected, all_permutations);
}
