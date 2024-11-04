#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> numbers;
    numbers.push_back(0);

    for (int i = 1; i <= 10; i++) {
        numbers.push_back(i);
    }

    // for (int number : numbers)
    //     std::cout << number << std::endl;
    for (auto it = numbers.cbegin(); it != numbers.cend(); it++) {
        std::cout << *it << std::endl;
    }
}
