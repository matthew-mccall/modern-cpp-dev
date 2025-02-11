#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

// Function to check if a number is even
bool isEven(int n) {
    return n % 2 == 0;
}

// Function to square a number
int square(int n) {
    return n * n;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evens;
    std::vector<int> result;

    // Filter even numbers
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens), isEven);

    // Square the even numbers
    std::transform(evens.begin(), evens.end(), std::back_inserter(result), square);

    // Print the result
    for (const auto& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}