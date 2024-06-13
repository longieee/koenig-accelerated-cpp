// What happens if we rewrite the previous program to allow values up to but not
// including 1000 but neglect to change the arguments to setw? Rewrite the
// program to be more robust in the face of changes that allow i to grow without
// adjusting the setw arguments

// Already handled in my implementation of exercise 4.2
// Here I'll make the starting and ending integer chosen by the user
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::setw;
using std::string;
using std::to_string;

int main()
{
    int start_int, end_int;

    cout << "Input the starting integer: ";
    cin >> start_int;

    cout << "Input the ending integer: ";
    cin >> end_int;

    if (start_int > end_int)
    {
        throw logic_error("Starting integer larger than ending integer");
        return 1;
    }

    cout << "Printing integers from " << start_int << " to " << end_int
         << " and their squares..." << endl;

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