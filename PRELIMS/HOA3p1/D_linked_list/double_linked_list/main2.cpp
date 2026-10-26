#include <iostream>
#include <string>
#include "double_ll.h"


int main(){
    

    //creation of head node:
    doubleList<char>* head = new_node('C');
    //creation ofn other nodes:
    doubleList<char>* second = new_node('P');
    doubleList<char>* third = new_node('E');

    //link the nodes
    head->next = second;
    second->prev = head;
    //!note: head is actually a pointer to the first node and it is NOT a node itself, it only holds the address of the first node

    second->next = third;
    third->prev = second;

    std::cout<<"initial traversal" << std::endl;
    dllTraverse(head);


    std::cout << "insertion of the head node" << std::endl;
    dllInsertHead('G', &head);
    dllTraverse(head);


    std::cout << "insertion of the middle node" << std::endl;
    dllInsertAny('A', head->next);
    dllTraverse(head);


    std::cout << "insertion of the end node" << std::endl;
    dllInsertEnd('1', head);
    dllTraverse(head);


    std::cout << "deletion of the nodes" << std::endl;
    dllDelete('A', &head);
    dllTraverse(head);
    
    return 0;
}



