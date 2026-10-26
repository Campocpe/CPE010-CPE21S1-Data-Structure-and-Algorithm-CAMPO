#include <iostream>

// attributes of the stack array
const size_t maxCap = 100; // assigns the maximum capacity of the array to 100
char stack[maxCap];        // array to store open symbols
int top = -1;              // shows that the stack is empty

// stack operations
void push(char c);
void pop();
char getTop();
bool isEmpty();
bool isFull();

// helper function for checking balanced symbols
bool isMatchingPair(char open, char close);

int main() {
    // continuous loop to keep program running and prevent terminal syntax errors
    while (true) {
        top = -1; // reset stack top for each new expression
        char ch;
        bool isBalanced = true;

        std::cout << "Expression: ";

        // Reads character by character until the user hits Enter ('\n')
        while (std::cin.get(ch) && ch != '\n') {
            if (!isBalanced) continue; // Skip checking if an error was already found

            // If character is an opening symbol, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                push(ch);
            } 
            // If character is a closing symbol
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (isEmpty()) {
                    isBalanced = false; // missing opening symbol for closing bracket
                } else {
                    char topChar = getTop();
                    pop();
                    if (!isMatchingPair(topChar, ch)) {
                        isBalanced = false; // Error: mismatched bracket types
                    }
                }
            }
        }

        // Check if any open symbols were left unclosed
        if (!isEmpty()) {
            isBalanced = false; // leftover open brackets in stack
        }

        // Output Result matching screenshot format
        if (isBalanced) {
            std::cout << "Result: VALID (Y)\n" << std::endl;
        } else {
            std::cout << "Result: INVALID (N)\n" << std::endl;
        }
    }

    return 0;
}

bool isEmpty() {
    return top == -1; // returns true if top is -1 (stack is empty)
}

bool isFull() {
    return top >= (int)maxCap - 1; // returns true if top reaches array capacity limit
}

void push(char c) {
    // checks if the stack is full, if it is full it will label stack overflow
    if (isFull()) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }
    stack[++top] = c; // increments top index and adds the new symbol
}

void pop() {
    // checks if stack is empty before removing element
    if (isEmpty()) {
        return;
    }
    top--; // decrements top index to remove the top element
}

char getTop() {
    // if the stack is empty, returns null character '\0'
    if (isEmpty()) {
        return '\0';
    }
    // returns the current top element of the stack
    return stack[top];
}

bool isMatchingPair(char open, char close) {
    // checks if the open and close brackets match each other
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}