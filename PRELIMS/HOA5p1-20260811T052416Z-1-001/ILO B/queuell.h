#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
class qNode{
      public:
      T data;
      qNode* next;

};


//creating a new node

template <typename T>
qNode<T> * new_node(T newData){
    //allocates the new node
    qNode<T>* newNode = new qNode<T>;
    //sets the new data in the newNode's data
    newNode->data = newData;
    //points the next pointer of the newNode to nullptr
    newNode->next = nullptr;
    return newNode;



}

//===========
//enqueue
//===========





template<typename T>
//frontptr and backptr is defined in the int main
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData){
      //create a new node
      qNode<T>* newNode = new_node(newData);

      //inserting to an empty queue
      //checks if the queue is empty
      if((*frontPtr) == nullptr && (*backPtr) == nullptr){
      (*frontPtr) = newNode;
      (*backPtr) = newNode;
      }


      //inserting an item into a non empty queue
      //point the backPtr next to the newNode
      (*backPtr)->next = newNode;
      (*backPtr) = newNode;
    
}




//============
//dequeueing
//============

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
      //create a temporary node to store the node to be deleted
      qNode<T>* deleteNode = nullptr;
      deleteNode = (*frontPtr);

      //check if the queue is only one 1 node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
         (*frontPtr) = nullptr;
         (*backPtr) = nullptr;
         delete deleteNode;
         return;

    }
      //deleting of the node
      (*frontPtr)= deleteNode->next;
      delete deleteNode;
    


}
//=================================
//display all elements in the list
//=================================

template <typename T>
void display(qNode<T>* frontPtr){
   if(frontPtr == nullptr){
      std::cout<< "queue is empty \n";
      return;
   }

   qNode<T>* current = frontPtr;
   while (current != nullptr){
    std::cout << current->data << "->";
    current= current->next;
   }
   std::cout<< "NULL \n";

}

//============================
//return the front variable
//============================
template <typename T>
T FrontVariable(qNode<T>* frontPtr){

   if(frontPtr != nullptr) {
    return frontPtr->data;
   }

}
#endif
