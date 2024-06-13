// Write a program to calculate the squares of int values up to 100.
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::to_string;

int main()
{
    cout << "Printing integers (up to 100) and their squares..." << endl;

    int start_int = 0;
    int end_int = 100;

    // The largest integer will have the most digits, hence the longest display.
    typedef string::size_type str_len;

    str_len largest_initial_length;
    str_len largest_squared_length;
    str_len padding = 5;

    // Find the length of the first column when printing out the integers
    largest_initial_length = to_string(end_int).length() + padding;
    largest_squared_length = to_string(end_int * end_int).length() + padding;

    for (int i = start_int; i <= end_int; i++)
    {
        int i_squared = i * i;

        // Printing
        cout << setw(largest_initial_length) << i
             << setw(largest_squared_length) << i_squared << endl;
    }

    return 0;
}