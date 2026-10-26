#include <iostream>
#include "singly_ll.h" //imports the custom header file-
                //so that you can use the class SingleList<T> to store data


int main(){
    
    //dynamically allocates memory in the heap for a new node created  in SingleList 
    //it holds an initger as inputed on the <> part which then in T variable in singly_ll.h
    //which is a variable that holds any data type its assigned to
    //this also creates a pointer which points to the data stored in the heap
    SingleList<int> *head = new SingleList<int>;
    SingleList<int> *second = new SingleList<int>;
    SingleList<int> *third = new SingleList<int>;



    //asigns the data "1" into the head node and points to the second node
    head->data = 1;
    //assigns head's pointer which is "next" with the address of second
    head->next = second;


    second->data = 2;
    second->next = third;


    third->data = 3;
    //points to nullptr meaning the ending of the linked list,
    third->next = nullptr;


    std::cout <<"Linked list traversal:";
    ListTraversal(head);


    std::cout<<"Newly inserted head of Linked List: ";
    sllinserthead(0,&head);
    ListTraversal(head);


    std::cout <<"Newly inserted after a node of Linked List: \n";
    sllGeneralInsertion(3, head);
    ListTraversal(head);

    std::cout <<"Newly inserted node in the middle: \n";
    sllGeneralInsertion(4,head->next->next);
    ListTraversal(head);

    std::cout <<"Newly inserted node in the end: \n";
    sllInsertEnd(10, &head);
    ListTraversal(head);


    std::cout <<"deleting a node: \n";
    sllDelete(10, &head);
    ListTraversal(head);


    std::cout <<"Deleting the list: \n";
    sllDeleteList(&head);
    ListTraversal(head);


    delete head;
    delete second;
    delete third;    




}
