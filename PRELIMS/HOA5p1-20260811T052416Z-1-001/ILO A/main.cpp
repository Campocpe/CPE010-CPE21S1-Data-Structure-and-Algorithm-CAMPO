#include <iostream>
#include <queue>



void display(std::queue<char> r);
void empty(std::queue<char> r);
void size(std::queue<char> r);

int main(){
     char x = x;
     std::queue<char> q;

     //creates a queue/line
     q.push('c');
     q.push('p');
     q.push('e');
     q.push('0');
     q.push('1');
     q.push('0');


     //display
     display(q);

     //empty()
     std:: cout << q.empty() << std::endl;

     //size()
     std:: cout << "the size of the queue is " << q.size() << std:: endl;
     //front
     std:: cout <<"the front of the queue is " << q.front() << std:: endl;
     //back
     std:: cout <<"the back of the queue is " << q.back()  << std:: endl;
     //pop
     std:: cout << "removing the first element" << std:: endl;
     q.pop();
     //display
     display(q);
     //push another element
     q.push('R');
     q.push('a');
     q.push('m');
     //display
     display(q);

    return 0;
}

//r is q 
void display(std::queue<char> r){
      //create a copy of the queue
      std::queue<char> c = r;

      //!note c.function is from stl
      //executes it until empty
      while(!c.empty()){
        std::cout<<" " << c.front(); //prints and pops the front and goes to the next node
        c.pop();

      }
      
      std::cout<<"\n";

}

void size(std::queue<char> r){
    
    //this is the queue
    std::queue<char> c = r;

    std::cout <<"the size of the queue is: " << c.size();

}