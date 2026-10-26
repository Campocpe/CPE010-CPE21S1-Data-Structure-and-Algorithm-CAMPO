#include <iostream>
#include "delimiter.h"

// Helper function to check matching bracket pairs
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

int main() {
    while (true) {
        // Reset stack head for each new expression
        head<char> = nullptr;

        char ch;
        bool isBalanced = true;

        std::cout << "Expression: ";

        // Reads input character by character
        while (std::cin.get(ch) && ch != '\n') {
            if (!isBalanced) continue; 

            // If opening symbol, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                push<char>(ch);
            } 
            // If closing symbol, validate against popped element
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (isEmpty<char>()) {
                    isBalanced = false;
                } else {
                    char topChar = pop<char>();
                    if (!isMatchingPair(topChar, ch)) {
                        isBalanced = false;
                    }
                }
            }
        }

        // If stack is not empty, unclosed brackets remain -> INVALID
        if (!isEmpty<char>()) {
            isBalanced = false;
        }

        // Output Result
        if (isBalanced) {
            std::cout << "Result: VALID (Y)\n" << std::endl;
        } else {
            std::cout << "Result: INVALID (N)\n" << std::endl;
        }

        // Clean up remaining stack memory
        while (!isEmpty<char>()) {
            pop<char>();
        }
    }

    return 0;
}