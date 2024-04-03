// Write a program to compute and print the quartiles of a set of integers.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::ceil;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

int main()
{
    cout << "Please enter a set of integers, followed by end-of-file: ";
    vector<int> integers;
    // variable to store vector's size
    typedef vector<double>::size_type vec_sz;
    // Variable to store the quartiles
    int q_75, q_50, q_25;
    // Variable to store user input
    int x;

    // Get input from user
    while (cin >> x)
    {
        integers.push_back(x);
    }

    // Vector size
    vec_sz size = integers.size();

    // Basic check to see if the user has entered any number
    if (size == 0)
    {
        cout << endl << "You must enter your grades. Please try again." << endl;
        // Exit with failure
        return 1;
    }

    // Sort the vector to start calculating quantiles
    sort(integers.begin(), integers.end());

    // Calculate the quantiles, return a number from the list of integers
    // provided by the user
    q_75 = integers[int(ceil(size * 0.75) - 1)];
    q_50 = integers[int(ceil(size * 0.50) - 1)];
    q_25 = integers[int(ceil(size * 0.25) - 1)];

    // Print the quantiles
    cout << "Quartiles: " << endl;
    cout << "First quartile: " << q_75 << endl;
    cout << "Second quartile: " << q_50 << endl;
    cout << "Third quartile: " << q_25 << endl;

    return 0;
}