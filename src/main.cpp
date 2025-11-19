#include "data_structures/arrays/array.hpp"
#include <iostream>

int main()
{
    // Create an array of integers with size 5
    dsa_handbook::Array<int, 5> arr;

    // Assign values to the array
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        arr[i] = static_cast<int>(i) * 10;
    }

    // Print the values in the array
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << "Element at index " << i << ": " << arr[i] << std::endl;
    }

    // check for out of bounds access
    try
    {
        arr[5] = 100; // This should throw an exception
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
