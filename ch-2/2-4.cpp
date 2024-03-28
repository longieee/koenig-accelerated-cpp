// Exercise: The framing program writes the mostly blank lines that separate the
// borders from the greeting one character at a time. Change the program so
// that it writes all the spaces needed in a single output expression.
#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // ask for the person's name
    cout << "Please enter your first name: ";

    // read the name
    string name;
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // the number of blanks surrounding the greeting
    int inPad;
    cout << "Enter the amount of spacing to leave between the frame and the "
            "greeting: ";
    cin >> inPad;
    const int pad = inPad;

    // the number of rows and columns to write
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // Calculate the left/right pad in a single output expression
    // Left/Right pad size is as specified
    const string horizontalPad(pad, ' ');
    // Up/down pad size must -2 to leave room for the border
    const string verticalPad(cols - 2, ' ');

    // write a blank line to separate the output from the input
    cout << endl;

    // write `rows` rows of output
    // invariant: we have written `r` rows so far
    for (int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        // invariant: we have written c characters so far in the current row
        while (c < cols)
        {
            // is it time to write the greeting?
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                // are we on the border?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                {
                    cout << "*";
                    ++c;
                }
                else
                {
                    // Same logic as previous programs, but now we have to check
                    // if horizontal or vertical pad is needed
                    if (r == pad + 1)
                    {
                        cout << horizontalPad;
                        c += horizontalPad.size();
                    }
                    else
                    {
                        cout << verticalPad;
                        c += verticalPad.size();
                    }
                }
            }
        }

        cout << endl;
    }

    return 0;
}