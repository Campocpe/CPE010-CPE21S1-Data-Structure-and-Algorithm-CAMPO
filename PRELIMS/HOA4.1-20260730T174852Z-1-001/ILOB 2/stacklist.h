#ifndef STACK_LIST_H
#define STACK_LIST_H

//class node that contains data and the next

//template typename T is used as a data type we entered in the int main
template <typename T>
class Node{
    public:
    //value that we need to store
    T data; //pointer to the next node
    Node* next;

};

//global pointer for the top of the stack

template <typename T>
Node<T>* head = nullptr;

//operations of the stack

//push
//connect the new node to the current head(the top/pointer)
//its lie the insertinthehead function in linked list

template <typename T>
void push(T newData){
    //creates a new node and assign the newData

    Node<T>* newNode= new Node<T>;
    newNode->data = newData;

    //new node points to the currenyt top, then becomes the new top

    //we assign with head<T> because its a data type 
    newNode->next = head<T>;
    //assigns head as the new node (not to null ptr anymore because there is a new npode)
     head<T> = newNode;

}

//pop
//we will know that the stack is empty if the head pointer i pointed to null meaning there are new nodes
template <typename T>
T pop(){
     //checks if the stack is empty
     if(head<T> == nullptr){
        std::cout << "stack overflow \n";


     }

     //save the current top node
     //creates a temporary holder/variable to be the head pointer/current node
     Node<T>* temp = head<T>;

     //stores the data of the current node
     T tempval = temp->data;
     //move the head to the next node
     //assigns the current pointer of the current node to the next node
     head<T> = head<T>->next;
     //free the removed node but still stores its data
     delete temp;
     //return the removed value
     return tempval;
}


//top
//returns the top node
template<typename T>
void Top(){
      // error catching:
    if(head<T> == nullptr){

       std::cout << "the stack is empty\n";
       return;
    }

      //display the Top node
      std::cout << "the current top is " << head<T>->data << std::endl;
}


//is_empty
template<typename T>
bool isEmpty(){
       return head <T> == nullptr;

}



//display all

template<typename T>
void display(){

    if(head<T> == nullptr){

       std::cout << "the stack is empty\n";
       return;
    }
    
    std::cout << "displaying the stack \n";
    Node<T>* currentNode = head<T> ;
    

    while(currentNode != nullptr){

      std:: cout << currentNode->data << std:: endl;
      currentNode = currentNode-> next;

    }
    std::cout << "\n";

}

//!note we dont have is_full because the value limit is dynamic
//meaning it doesnt have a fixed value



#endif