#include <iostream>
#include <string>
#include "palindromeQueue.h"

// calculates the string length 
int getLength(const std::string& str) {
    int len = 0;
    for (char c : str) {
        len++;
    }
    return len;
}

// Check palindrome using queueArr without stack
bool isPalindrome(const std::string& str) {
    int len = getLength(str); //gets the string's length
    queueArr<char> q(len);

    // Load characters into queue from left to right
    for (char ch : str) {
        q.Enqueue(ch);
    }

    // Compare queue output (Left-to-Right) with string index (Right-to-Left)
    for (int i = len - 1; i >= 0; i--) {
        if (q.Front() != str[i]) {
            return false; //if the inputed str isint equal to the input then it would stop the enqueueing and return false
        }
        q.Dequeue();
    }

    return true; // if all characters matches then it will return true
}

int main() {
    // Array with empty string sentinel
    std::string testCases[] = {
        "10201",
        "1003003001",
        "88",
        "0",
        "202",
        "" 
    };

    std::cout << "Input Value\tOutput\tRemark\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; testCases[i] != ""; i++) {
        bool result = isPalindrome(testCases[i]);
        int len = getLength(testCases[i]);
        
        std::cout << testCases[i] 
                  << (len < 8 ? "\t\t" : "\t")
                  << (result ? "Is a Palindrome" : "Not a Palindrome") 
                  << "\n";
    }

    return 0;
}