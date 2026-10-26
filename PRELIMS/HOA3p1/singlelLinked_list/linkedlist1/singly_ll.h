#ifndef SINGLY_LL_H // header filename
//checks if the header file has been included before, if not it will include it

#define SINGLY_LL_H //  file name
//checks if this file has run once 

#include <iostream> //imports the iostream library to use std::cout and std::endl

template <typename T> // This makes the class accept any data type
            //the variable "T" acts as a placeholder for any data type
            
//this class represents a node in the singly linked list
class SingleList{
    //every variable declared in this class can be accessed by int main
    public:
    T data; //a variable that holds the data of the node
    SingleList<T> *next = nullptr; //stores the address of the next node

};

template <typename T>
void ListTraversal(SingleList<T>* head){//Will check the data type stored in that address 
    while( head != nullptr){
        std::cout << head->data;
    
        // to check if the next head is null
        if (head->next != nullptr){
            std::cout << "->";
        }
        head = head->next; //if its next is not null, it will go to the next node and print the data of that node
   }
   std::cout << std::endl;
} 

//node insertion at the front
template <typename T>
//!note: the double pointer is used to modify the head pointer in the calling function
//meaning if its a single pointer it will store the value in the variable currenthead 

//!note: the double pointer is used to modify the head pointer to change the address of the pointer thats pointing to-
//-meaning if a new node is called it would change the address of the head pointer to point to the new node
//wherin if its a single pointer its only a pointer to the address of the current node 
//(single pointer = holds the address of the node)(double pointer = holds the holder thats holding the address of the node)
//!note: the reason why we add a double pointer is because we want to modify the head pointer in the calling function-
//-meaning we want to change the address of the head pointer to point to the new node
void sllinserthead(T newData, SingleList<T>** currentHead){

    //allocate the memory for the new node
    SingleList<T>* newNode = new SingleList<T>;
    //Put data in a new node
    newNode->data = newData; 
    //set the new node to the point of the previous head
    //!note: "->" means its a operator(similar to . ex variable.class)
    //-for a pointer, it is use to access members of a class through a pointer

    //note!: notice how there is a dereferrence operator in currentHead. meaning it gets the value of the node its currently in
    newNode->next = *currentHead;
    //Reset head to point to the new node
    *currentHead = newNode;

}

//node insertion anywhere 
template <typename T>
void sllGeneralInsertion(T newData, SingleList<T>* prevNode){
    //check if the head node is null(which is impossible)
    if(prevNode == nullptr){
        std::cout <<"A previous node cannot be null";
        return;
    }
    //allocate a new node
    SingleList<T>* newNode = new SingleList<T>;
    //store data inside a newnode
    newNode->data = newData;
    //point node to the previous node
    newNode->next = prevNode->next;
    //point previous node to the new node
    prevNode->next = newNode;

}

//node insertion at the end
template <typename T>
void sllInsertEnd(T newData, SingleList<T>** head){
    //allocate a new node
    SingleList<T>* newNode = new SingleList<T>;

    //Dereference to the head/first node
    //note!: currentNode is a pointer 
    //the currentNode pointer will start at the head 
    SingleList<T>* currentNode = *head;

    //store data in the new node
    newNode->data = newData;

    //point data to null
    newNode->next = nullptr;

    //Check if list is empty, will insert new node in nullptr node
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    
    //Traverse the list until the next node is null
    while(currentNode->next != nullptr){
        currentNode = currentNode->next; //iteration going to one node to another
    }
    
    //assigns the new node as the last node in the list, since the currentNode->next is null, it will point to the new node
    currentNode->next = newNode;
}

//node deletion
template <typename T>
void sllDelete(T findData, SingleList<T>** head){

    //check if there is a list
    if(*head == nullptr){
        return;
    }

    SingleList<T>* cNode = *head;
    SingleList<T>* prevNode = nullptr;

    //Search fot the node
    while(cNode != nullptr && cNode->data != findData){
        prevNode = cNode;
        cNode = cNode->next;
    }


    //If data is not found
    if(cNode == nullptr) return;

    //delete the head node (the head node is findData)
    if (prevNode == nullptr){
        *head = cNode->next;
    }
    else {
        prevNode->next = cNode->next;
    }

    delete cNode;

}

template <typename T>
void sllDeleteList(SingleList<T>** head){
    SingleList<T>* cNode = *head;

    while(cNode != nullptr){
        SingleList<T>* temp = cNode;
        cNode = cNode->next;
        delete temp;
    }

    *head = nullptr;
}

#endif