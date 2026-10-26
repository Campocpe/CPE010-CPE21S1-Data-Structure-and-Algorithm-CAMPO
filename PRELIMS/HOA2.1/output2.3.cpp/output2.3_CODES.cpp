//libraries 
#include <iostream>
#include <string.h>  //to use and store strings in the program

//creates a class called student
class student{
private:           //variables that can be only accessed within the class
std:: string studentName;
int studentAge ;

public:
//constructor

student(std:: string newname = "john doe", int newage = 18){     //assigns the "student" class with variables newname and newage
studentName = std:: move(newname); //NOTE! the 'move' command is basically copy assignment opperator but instead of copying its moving it-
                                  //-think of it as append and write in oop2
studentAge = newage;
std:: cout << "the constructor is called" << std:: endl;
}

//deconstructor

//!NOTE the destructor function's name does not REFER to the constructor function "student" instead it referrs to the "student" class
~student(){
    
   std:: cout << "destructor is called" << std:: endl; 
    
    
}

//copy constructor


student(const student &copystudent){
    
    std:: cout << "copy constructor is called" << std:: endl;
    
    //copies the EXACT value of studentName and studentAge in the private section and creates a new copy that is also named studentName- 
          //- and has the contents of the original student name in it
    
    //to differentiate the 2 thats we added &copystudent to get the data of the original studentName and assigns it to the new studentName-
          // -variable which has a different address but still holds the original value inside of it
    
    //FAQ: why use & when you can directly assign?
    //it is use to PASS the data to the constructor but instead of duplicating the data it actually creates an alias which in this case is-
          // -the student class itself
    //because ithout '&', passing by value would require calling the copy constructor to set up the argument, triggering infinite recursion
          // -that overflows the stack and crashes.
    
    studentName = copystudent.studentName;
    studentAge = copystudent.studentAge;
    
} 

// Copy Assignment Operator

//the function is only called if you assign a variable with another variable (ex. student3 = student2)
// FAQ: why does it use a referrence "&"?: so that the variable can be assigned/allocate multiple times which in the function's case would
       //- be the variable student2
student& operator=(const student &copystudent) {
    std::cout << "copy assignment operator is called" << std::endl;

    // checks if the assigned variable has the same name as the assigned variable (ex. student3 = student3)
    // the "this" variable is a variable that is used in classes to store dereferrenced data in it and it is promised to return it as- 
        //-referrenced data
    if (this == &copystudent) {
        return *this;   //dereferrences &copystudent
    }

    // creates a copy
    studentName = copystudent.studentName;
    studentAge = copystudent.studentAge;

    // returns the dereferrenced &copystudent
    return *this;
}


void Print_Details (){
    
  std::cout << this->studentName << " " << this->studentAge << std::endl;
    
};
};


//main caler
int main() {
      
 const size_t j = 5;                     //size_t represents the size of arrays in bytes. assigns j with 5

 student studentList[j] = {};                               //asigns the size of the array which will be stored in the "student" class
 
 //assigns the name and age of the students
 std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
 int ageList[j] = {15, 16, 18, 19, 16};

 for(int i = 0; i < j; i++){ //loop A
 student *ptr = new student(namesList[i], ageList[i]);   //creates the heap and adds the data in it (it triggers constructor)
 studentList[i] = *ptr;                                  //assigns the stack and triggers the copy assignment to copy the data to the stack
                                                         //!note: when we assigned studentlist[i] = *ptr it copies the data not TRANSFER it
delete ptr; 
 }

 for(int i = 0; i < j; i++){ //loop B
 studentList[i].Print_Details(); //this loop is created to print the data of the studentList[i]
 }
 return 0;
} 
