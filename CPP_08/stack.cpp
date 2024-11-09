#include <iostream>
#include <stack>

void    printStackElements(std::stack<int> stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}

int main() {
    //empty, size, push, pop, top
    std::stack<int> numbersStack;
    numbersStack.push(1);
    numbersStack.push(2);  
    numbersStack.push(3);
    numbersStack.pop();
    // numbersStack.pop();
    // numbersStack.pop();

    printStackElements(numbersStack);
    // if (numbersStack.empty())
    //     std::cout << "Stack is empty" << std::endl;
    // else
    //     std::cout << "Stack is not empty" << std::endl;
    // std::cout << "Stack size is " << numbersStack.size() << std::endl;


}