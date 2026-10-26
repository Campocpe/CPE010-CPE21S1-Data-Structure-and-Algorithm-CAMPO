#include <iostream>

// attributes of the stack array
const size_t maxCap = 100;
int stack[maxCap];  // the maximum cap of the array
int top = -1;       // shows that the array is empty
int maxElements;    // the max element you assign

void push(); // add data to the stack
void pop();
void Top();
bool isEmpty();
bool isFull();
void displayStack();

int main() {
    int choice;

    std::cout << "Enter the max capacity for the stack (max " << maxCap << "): ";
    std::cin >> maxElements;

    if (maxElements > maxCap || maxElements <= 0) {
        std::cout << "Invalid capacity! Defaulting to " << maxCap << std::endl;
        maxElements = maxCap;
    }

    while (true) {
        std::cout << "\n--- Stack Operations ---" << std::endl;
        std::cout << " 1. PUSH \n 2. POP \n 3. TOP \n 4. isEmpty \n 5. DISPLAY STACK \n 6. EXIT" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: 
                push();
                break;
            case 2: 
                pop();
                break;
            case 3: 
                Top();
                break;
            case 4: 
                std::cout << (isEmpty() ? "Stack is Empty" : "Stack is NOT Empty") << std::endl;
                break;
            case 5: 
                displayStack();
                break;
            case 6:
                return 0;
            default: 
                std::cout << "Invalid Choice!" << std::endl;
                break;
        }
    }

    return 0;
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top >= maxElements - 1;
}

void push() {
    // checks if the stack is full, because if its full you cant push anymore data
    if (isFull()) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }

    int newData;
    std::cout << "New Value to add into the stack: ";
    std::cin >> newData;    // gets the new data
    stack[++top] = newData; // increments the top so that the data can be added on the stack
}

void Top() {
    // check if the stack is empty because if its empty it wont output anything
    if (isEmpty()) {
        std::cout << "Stack Underflow! No top element." << std::endl;
        return;
    }
    // outputs the top value of your stack
    std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

void pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow! Cannot pop." << std::endl;
        return;
    }
    std::cout << "Popping: " << stack[top] << std::endl; // pops the top part
    top--; // decrements the top so that the program doesnt recognize that the top value is there,
           // but in reality its still there its just not part of the stack
}

void displayStack() {
    if (isEmpty()) {
        std::cout << "Stack Empty" << std::endl;
        return;
    }
    //access the contents of the stack array from top to bottom 
    //by decrementing the array going through the last value altrhough the first value
    std::cout << "Stack contents (top to bottom): ";
    for (int j = top; j >= 0; j--) {
        std::cout << stack[j];
        if (j > 0) std::cout << ", ";
    }
    std::cout << std::endl;
}