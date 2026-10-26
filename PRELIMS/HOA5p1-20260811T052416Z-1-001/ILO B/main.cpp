#include <iostream>
#include "queuell.h"


int main(){

//why front and back?

qNode<char> * front = nullptr;
qNode<char>* back = nullptr;

enqueue(&front, &back, 'R');
std::cout << front->data << " " << back->data << std::endl;
enqueue(&front, &back, 'A');
std::cout << front->data << " " << back->data << std::endl;
enqueue(&front, &back, 'M');
std::cout << front->data << " " << back->data << std::endl;
dequeue(&front, &back);
std::cout << front->data << " " << back->data << std::endl;
enqueue(&front, &back, 'R');
std::cout << front->data << " " << back->data << std::endl;

std:: cout << "Queue list \n";
display(front);
std::cout << "Front value: " << FrontVariable(front) << std::endl;

    return 0;
}



