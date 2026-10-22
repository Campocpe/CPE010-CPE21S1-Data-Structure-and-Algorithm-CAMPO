#include <iostream>

//1

//the global declaration section to swap 2 values
void swap(int num1, int num2);

//2

//Global declaration section
void convert(float far, float deg);

//3

//Global declaration section
void distance(float point1, float point2 );


int main(){
//MAIN CALLER
    
    //1
    //it assigns the value to the variable inside the function
    int num1 = 7;
    int num2 = 14;
    
    //calls out the function
    swap(num1 , num2);

    //2
    //it assigns the value to the variable inside the function
    float far;
    float kel;
    //calls out the function
    convert(far, kel);

    //3
    //it assigns the value to the variable inside the function
    float point1;
    float point2;
    //calls out the function
    distance(point1, point2);
}

//1

//this function uses another variable to store the data of the first value so that the 2nd value can be the new first value
//it also displays the before and after the switch
void swap(int num1, int num2){
    int extra;
    std:: cout << "before: " << num1 << ", " << num2 << std:: endl;
    
    extra = num1;
    num1 = num2;
    
    
    
   std:: cout << "after: " << num1 << ", " << extra << std:: endl;
}

//2 this function asks the user for the temperature in kelvin which is trasnfered into a convertion formula that is assigned-
//to the farenheit variable and then it outputs the temperature in farenheit
void convert(float far, float kel){

     

    std:: cout << "welcome to kelvin to farenheit converter" << std:: endl;
    std:: cout << "enter the temperature in kelvin: ";
    std:: cin >> kel;

    far = (((kel - 273.15)* 1.8) + 32) ;

    std:: cout << "the temperature in farenheit is: " << far<< "\n\n";

}

//3 this function asks the user for the first point and second point, it then subtracts the 2nd point to the 1st point to get the-
//distance (which is assigned to fpoint) and it is then outputed
void distance(float point1, float point2 ){

    float fpoint;
    std:: cout << "welcome to the distance checker" << std:: endl;
    std:: cout<< "enter the first point (in meters): " ;
    std:: cin >> point1;
    std:: cout << "enter the second point (in meters): ";
    std:: cin >> point2; 
    fpoint = point2 - point1;
    std:: cout << "the distance between point 1 and point 2 is: " << fpoint;
}

