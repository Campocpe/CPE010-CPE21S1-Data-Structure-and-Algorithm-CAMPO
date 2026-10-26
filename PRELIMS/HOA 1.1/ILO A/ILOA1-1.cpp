#include <iostream>

//1
void sum(int fnum, int lnum);

//2
void greater(int fvar, int lvar);

//3
void logic(bool val1 , bool val2);



int main() {
//MAIN CALLER

  //1
   int fnum;
   int lnum;

   //gets the input from the user and assigns it into the given variables
   std::cout << "1# welcome to the addition tracker" << std::endl;
   std::cout << "enter the first digit" << std::endl;
   std::cin >> fnum;
   std::cout << "enter the second digit" << std::endl;
   std::cin >> lnum;

   //calls the function that add the numbers up
   sum(fnum, lnum);

  //2

  int fvar;
  int lvar;

  //gets the input from the user and assigns it into the given variables
  std::cout << "2# welcome to the greater or less than checker" << std::endl;
  std::cout << "enter first value" << std:: endl;
  std::cin >> fvar;
  std::cout << "enter the second value" << std:: endl;
  std::cin >> lvar;

  //calls out the greater function to determine if the first value is lesser or greater than the second value
  greater(fvar, lvar);
  
  //3
  bool val1;
  bool val2;
  
  //gets the input from the user and assigns it into the given variables
  std::cout << "3# welcome to the logic gate displayer" << std::endl;
  std:: cout << "type 1 if its true" << std:: endl;
  std:: cout << "type 0 if its false" << "\n\n";
  std:: cout << "type in the first value: " << std:: endl;
  std::cin >> val1;
  std:: cout << "type in the second value" << std:: endl;
  std::cin >> val2;

  //calls out the logic function to determine the result in each logic gate
  logic(val1, val2);
  
    return 0;
}

//1
void sum(int fnum, int lnum){

//adds the given values and displays the sum
int total = fnum + lnum;
std::cout << "your total: "<< total << "\n\n";


}
//2
void greater(int fvar, int lvar){

//an if else statement function to check whether its greater than, elss than or equal to
if (fvar > lvar){
    std::cout << fvar << " is greater than " << lvar << "\n\n";
} else if (fvar == lvar){
    
    std::cout<< fvar << " is equal to " << lvar<< "\n\n";
    
    } else {

    std::cout << fvar << " is less than " << lvar << "\n\n";
}


}

//3
void logic(bool val1 , bool val2){

//code for AND GATE 
//an if else statement function that uses an AND logic gate to check the input
    if (val1 == true && val2 == true){
       std::cout << "AND GATE" << std::endl; 
       std::cout << "the statement is true" << std::endl;
    } else{
        std::cout << "AND GATE" << std::endl;
        std::cout << "the statement is false" << std::endl;
    }

    //code for OR GATE
    //an if else statement function that uses a OR logic gate to check the input
     if (val1 == true || val2 == true){
       std::cout << "OR GATE" << std::endl; 
       std::cout << "the statement is true" << std::endl;
    } else{
        std::cout << "OR GATE" << std::endl;
        std::cout << "the statement is false" << std::endl;
      }

    //code for NOT Gate
    //an if else statement that displays the "opposite" of the 1st and second input
    std:: cout << "NOT GATE" << std::endl;
    if (val1 == true){
        
        std:: cout << "the 1st statement is false" << std::endl;
        
    } else {
        
        std:: cout << "the 1st statement is true" << std::endl;
    }
    
    if(val2 == true){
        
        std:: cout << "the 2nd statement is false" << std::endl;
    }  else {
        std:: cout << "the 1st statement is true" << std::endl;
    }

}
