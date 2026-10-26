#include <iostream>
#include "stackList.h"



int main(){

    std:: cout << "---- PUSHING 'C' 'P' 'E' ONTO THE STACK --- \n";
    

    //push
    push('c');
    push('p');
    push('e');
        
    //display the current top
    display<char>();
    Top<char>(); //top should be 'e'
    
    std::cout <<"\n ======== popping all the elements =======\n";
 

    while(!isEmpty<char>()){

      std::cout<<"Popped: " << pop<char>() <<std::endl;
    }

    std::cout <<"\n ------- Testing the underflow -------- \n";
    pop<char>();

    return 0;


}