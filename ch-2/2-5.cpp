// Write a set of ‘‘*’’ characters so that they form a square, a rectangle, and
// a triangle.
#include <iostream>
#include <string>

int main()
{
    // Configurations
    const int shape_size = 9;
    const int square_height = shape_size;
    // When printing out to the console,
    // a rows's height is equaly to 2 column's width
    const int square_width = shape_size * 2;
    // Configuration for the triangle
    int triangle_height = shape_size;
    int triangle_width = triangle_height * 2 - 1;

    // Draw a square
    std::cout << "Drawing a square:" << std::endl;
    for (int r = 0; r < square_height; r++)
    {
        int c = 0;

        while (c < square_width)
        {
            // Are we at the border?
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
            // Are we at the border?
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
    // Strategy: drawing by each layer, from top to bottom. We're not going to
    // cheat by drawing a right triangle The "width" of each layer of the
    // triangle is 1,3,5,7, etc. The center of each row this the triangle
    // section This means the height of the triangle must be pre-determined so
    // that we can calculate the center
    for (int r = 0; r < triangle_height; r++)
    {
        int c = 0;
        // The width of the layer
        int layer_width = 2 * r + 1;
        // Determine the center of the row
        int center = triangle_width / 2;
        // The left and right border of the triangle
        int left_border = center - r;
        int right_border = center + r;
        // If we are at the bottom row, draw the whole row as border
        if (r == triangle_height - 1)
        {
            while (c < triangle_width)
            {
                std::cout << '*';
                ++c;
            }
        }
        else
        {
            // Draw the layer
            while (c < triangle_width)
            {
                if (c == left_border || c == right_border)
                {
                    std::cout << '*';
                }
                else
                {
                    std::cout << ' ';
                }
                ++c;
            }
        }
        // Go to the next row
        std::cout << std::endl;
    }
    return 0;
}