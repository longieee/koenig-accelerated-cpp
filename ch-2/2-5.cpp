// Write a set of ‘‘*’’ characters so that they form a square, a rectangle, and
// a triangle.
#include <iostream>
#include <string>

int main()
{
    // Configurations
    const int shape_size = 8;
    const int square_height = shape_size;
    // When printing out to the console,
    // a rows's height is equaly to 2 column's width
    const int square_width = shape_size * 2;

    // Draw a square
    std::cout << "Drawing a square:" << std::endl;
    for (int r = 0; r < square_height; r++)
    {
        int c = 0;

        while (c < square_width)
        {
            if (r == 0 || r == square_height - 1 || c == 0 ||
                c == square_width - 1)
            {
                std::cout << '*';
            }
            else
            {
                std::cout << ' ';
            }
            ++c;
        }
        // Go to the next row
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Draw a rectangle
    std::cout << "Drawing a rectangle:" << std::endl;
    // Use the fact about row and column sizes' differences in the console, we
    // can re-use the code above
    for (int r = 0; r < shape_size; r++)
    {
        int c = 0;

        while (c < shape_size)
        {
            if (r == 0 || r == shape_size - 1 || c == 0 || c == shape_size - 1)
            {
                std::cout << '*';
            }
            else
            {
                std::cout << ' ';
            }
            ++c;
        }
        // Go to the next row
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Draw a triangle
    std::cout << "Drawing a triangle:" << std::endl;

    return 0;
}