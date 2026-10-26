#ifndef PALINDROMESTACK_H
#define PALINDROMESTACK_H

#include <iostream>

// class node that contains data and the next pointer
template <typename T>
class Node {
    public:
    T data;      // value that we need to store
    Node* next;  // pointer to the next node
};

// global variable template for the head of the stack
template <typename T>
Node<T>* head = nullptr;

// operations of the stack

// push
template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

// pop
template <typename T>
T pop() {
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow! \n";
        return T();
    }

    Node<T>* temp = head<T>;
    T tempval = temp->data;
    head<T> = head<T>->next;
    delete temp;
    return tempval;
}

// top
template<typename T>
void Top() {
    if (head<T> == nullptr) {
        std::cout << "The stack is empty\n";
        return;
    }
    std::cout << "The current top is " << head<T>->data << std::endl;
}

// is_empty
template<typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// display all
template<typename T>
void display() {
    if (head<T> == nullptr) {
        std::cout << "The stack is empty\n";
        return;
    }

    std::cout << "Displaying the stack: \n";
    Node<T>* currentNode = head<T>;

    while (currentNode != nullptr) {
        std::cout << currentNode->data << std::endl;
        currentNode = currentNode->next;
    }
    std::cout << "\n";
}

#endif