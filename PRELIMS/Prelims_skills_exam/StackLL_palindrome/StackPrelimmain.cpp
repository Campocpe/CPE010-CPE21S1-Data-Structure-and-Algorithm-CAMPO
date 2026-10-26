#include <iostream>
#include <string>
#include "palindromeStack.h" // Ensure this matches your header filename

bool checkPalindrome(const std::string& input) {
    // 1. Push every character of the string onto the stack
    for (char ch : input) { //for every ch ( or the number inputed) in the input it will create a new node
        push<char>(ch); //creates a brand new stack/node that has the contents of what the user inputed
    }

    // 2. Pop characters and compare them to the original string
    for (char ch : input) { 
        if (pop<char>() != ch) { //pops the current top node to check, if the current top isint the same with the 
            //original it returns false
            // Clear remaining stack elements if a mismatch occurs
            while (!isEmpty<char>()) { //while the stack isint empty, pop every node in there
                pop<char>();
            }
            return false;
        }
    } //if every character appears the same, returns true
    return true;
}

int main() {
    
    std::string testCases[] = {
        "10201",
        "1003003001",
        "88",
        "0",
        "202"
    };

    std::cout << "Palindrome?\tOutput (Console) Remark\n";
    std::cout << "--------------------------------------------\n";

    // Loop through the fixed array directly
    for (const std::string& test : testCases) {
        std::cout << test << "\t\t";
        if (checkPalindrome(test)) {
            std::cout << "Is a Palindrome\n";
        } else {
            std::cout << "Not a Palindrome\n";
        }
    }

    return 0;
}