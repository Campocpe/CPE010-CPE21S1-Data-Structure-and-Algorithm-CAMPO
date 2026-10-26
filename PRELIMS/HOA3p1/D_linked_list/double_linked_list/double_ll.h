#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

template <typename T>
class doubleList{
    public:
        T data; //T data acts as the data holder per every node created
        doubleList<T>* next = nullptr;
        doubleList<T>* prev = nullptr;
};

//!note: doulbeList<T> acts as a data type 
//!note: nullptr is basically NOTHING

//====================
//creating a node
//====================
template <typename T>
doubleList<T>* new_node(T newData){
    //dynamically allocate memory for a new node
    doubleList<T>* newNode = new doubleList<T>;
    //store data in the node:
    newNode->data = newData;
    //since its a new node, it will point to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

//====================
//traversal 
//====================
template <typename T>
//current node acts as an indicator to point to the current node
void dllTraverse(doubleList<T>* currentNode){
    doubleList<T>* tail = nullptr;
    std::cout << "Forward Traversal: ";

    while(currentNode != nullptr){
        //prints the data
        std::cout << currentNode->data << " ";
        //save the current node as the last visited node
        tail = currentNode;
        //move to the next node
        currentNode = currentNode->next;
    }
    
    //space
    std::cout << std::endl;

    //reverse traversal
    std::cout << "Reverse Traversal:  ";

    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

//====================
//insertion at the head
//====================
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead){
    //create a new node
    doubleList<T>* newNode = new_node(newData);

    //SET THE new node to point to the current head
    newNode->next = *currentHead;

    //current head will be pointed to the new node
    if(*currentHead != nullptr){
        (*currentHead)->prev = newNode;
    }
    //update the head pointer
    *currentHead = newNode;
}

//====================
//general insertion
//====================
template <typename T>
void dllInsertAny(T newData, doubleList<T>* prevNode){
    //cannot insert after a null node (previous node cannot be null)

    //check if the previous node is null
    if(prevNode == nullptr){
        std::cout << "Previous node cannot be null" << std::endl;
        return;
    }

    //create a new node
    doubleList<T>* newNode = new_node(newData);

    //set the new node's next to the prevNodenext
    newNode->next = prevNode->next;

    //set the previous node's next to the new node
    prevNode->next = newNode;

     //set the new node's prev to the previous node
    newNode->prev = prevNode;

    //if the new node's next is not null, set its prev to the new node
    if(newNode->next != nullptr){
        newNode->next->prev = newNode;
    }

    //previous node will be pointed to the new node
    prevNode->next = newNode;
}




//====================
//insertion at the end
//====================
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* currentHead){
    //create a new node
    doubleList<T>* newNode = new_node(newData);
    //traverse until the last node
    doubleList<T>* currentNode = currentHead;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    //connect the last node to the new node
    currentNode->next = newNode;

    //connect the prev node to the new node
    newNode->prev = currentNode;
}

//====================
//deletion
//====================

template <typename T>
void dllDelete(T findData, doubleList<T>** head){

    // Checks the list if its is empty, if it it ends the program-
    //-if its not it continues it
    if(*head == nullptr) return;
    
    //sets the current node to the head of the list
    doubleList<T>* currentNode = *head;

    
    //searches for the node and checks if it hasn't reach the end of the node 
    //and if the data doenst match the data of the current node
    while(currentNode != nullptr && currentNode->data != findData){
        currentNode = currentNode->next;
    }

    // If data is not found
    if(currentNode == nullptr) return;

    // Delete the head node
    if(currentNode->prev == nullptr){
        *head = currentNode->next;
        
        if(*head != nullptr){
            (*head)->prev = nullptr;
        }
    }
    else{
        currentNode->prev->next = currentNode->next;

        if(currentNode->next != nullptr){
            currentNode->next->prev = currentNode->prev;
        }
    }

    delete currentNode;
}

#endif



