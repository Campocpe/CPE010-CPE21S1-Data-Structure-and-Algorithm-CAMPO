#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>


//declares the size of the array
const size_t maxCap = 100;


//creates or alocates the stack array and assigns the set value of the stack
int stack[maxCap];
int top = -1;  //assigns the top of the stack with -1 (its used as an indicator to track the top item of the stack 
               //if you popped or pushed an item in the stack its also used to indicate that the stack is empty since the size of an array is 0
               // )
int userMaxCap = maxCap; //assigns the input of the user as the size of an array (should'nt exceed the actual maximum capacity which is 100)
   

//a function that checks if the stack is empty, uses the top variable which if it is equals to -1 it is empty and outs puts true
bool isEmpty(){

    if(top == -1) return true;
    return false;
}

bool isFull(int usercap){

    if(top !> i-1)

}
}