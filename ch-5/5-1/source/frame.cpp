#include "../header/frame.h"
#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::max;
using std::string;
using std::vector;

string::size_type width(const vector<string>& v)
{
    string::size_type max_len = 0;

    for (vector<string>::size_type i = 0; i != v.size(); i++)
    {
        max_len = max(max_len, v[i].size());
    }

    return max_len;
}

/**
 * @brief Function to produce a framed text
 *
 * @param v The vector of strings to produce a frame for
 * @param border_char The character of the border
 * @param align_side The texts will be aligned to the left or right, according
 * to this option
 * @param padding The width of padding between the text and the borders
 */
vector<string> frame(const vector<string>& v, const string align_side = "left",
                     const int padding = 4)
{
    if (align_side != "left" && align_side != "right")
    {
        throw domain_error("align_side must be one of [left, right]");
    }

    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + padding, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        if (align_side == "left")
        {
            ret.push_back("  " + v[i] + string(maxlen - v[i].size(), ' ') +
                          "  ");
        }
        else if (align_side == "right")
        {
            ret.push_back("  " + string(maxlen - v[i].size(), ' ') + v[i] +
                          "  ");
        }
    }

    // write the bottom border
    ret.push_back(border);

    return ret;
}

/**
 * @brief Function to produce a framed text
 *
 * @param v The vector of strings to produce a frame for
 * @param border_char The character of the border
 * @param align_side The texts will be aligned to the left or right, according
 * to this option
 * @param padding The width of padding between the text and the borders
 */
vector<string> frame(const vector<string>& v, const char border_char,
                     const string align_side = "left", const int padding = 4)
{
    if (align_side != "left" && align_side != "right")
    {
        throw domain_error("align_side must be one of [left, right]");
    }

    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + padding, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        if (align_side == "left")
        {
            ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') +
                          " *");
        }
        else if (align_side == "right")
        {
            ret.push_back("* " + string(maxlen - v[i].size(), ' ') + v[i] +
                          " *");
        }
    }

    // write the bottom border
    ret.push_back(border);

    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    // copy the top picture
    vector<string> ret = top;

    // copy the entire bottom picture
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end();
         ++it)
    {
        ret.push_back(*it);
    }

    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add 1 to leave a space between pictures
    vector<string>::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    // continue until we’ve seen all rows from both pictures
    while (i != left.size() || j != right.size())
    {
        // construct new string to hold characters from both pictures
        string s;

        // copy a row from the left-hand side, if there is one
        if (i != left.size())
        {
            s = left[i++];
        }

        // pad to full width, because
        // either s.size() is the size of the string that we copied from left,
        // or it is zero because there was no entry to copy
        s += string(width1 - s.size(), ' ');

        // copy a row from the right-hand side, if there is one
        if (j != right.size())
        {
            s += right[j++];
        }

        // add s to the picture we’re creating
        ret.push_back(s);
    }

    return ret;
}
