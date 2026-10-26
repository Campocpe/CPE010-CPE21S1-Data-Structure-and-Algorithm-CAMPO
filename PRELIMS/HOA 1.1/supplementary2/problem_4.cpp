#include <iostream>

//Class Declaration and Method Definition Section

//the class for the triangle
class Triangle{
    
    //this private specifier has the variables of the angles, since its private it can be only accessed within this class
    //- and not on the main program
    private:
    double peri, area, angleA, angleB, angleC, base, height, sideA, sideB, sideC;
    
    //this is a public specifier, the variables in it can be called in and out of the class
    public:
    Triangle(double A, double B, double C, double b, double h, double sA, double sB, double sC);
    
    
   //a) the function to identify the type of triangle
   void TypeOfTriangle();

   //b) the function to identify the area of the triangle
   void AreaOfTriangle();
   
   //c) the function to identify the perimeter of the triangle
   void PerimeterOfTriangle();
    };


int main(){
//MAIN CALLER    
    
 //variables    
double A;
double B;
double C;
double b, h, sA, sB, sC;

//this section asks the user for the needed inputs (height, base, side and angles)    
    std:: cout << "welcome to the triangle perimeter, area and type of angle checker \n";
    std:: cout << "enter the 1st angle \n";
    std:: cin >> A;
    std:: cout << "enter the 2nd angle \n";
    std:: cin >> B;
    std:: cout << "enter the 3rd angle \n";
    std:: cin >> C;
    std:: cout << "enter base: ";
    std:: cin >> b;
    std:: cout << "enter height: ";
    std:: cin >> h;
    std:: cout << "enter side A: ";
    std:: cin >> sA;
    std:: cout << "enter side B: ";
    std:: cin >> sB;
    std:: cout << "enter side C: ";
    std:: cin >> sC;
    
    //this is where it calls the constructor and assigns the value of the variables in the main caller to the triangle class
    Triangle set1(A, B, C, b, h, sA, sB, sC);
    
    //outputs the triangle components by calling the functions
    std:: cout << " \n";
    std:: cout << "TRIANGLE COMPONENTS \n";
    set1.TypeOfTriangle(); 
    set1.AreaOfTriangle();
    set1.PerimeterOfTriangle();
    return 0;


}
    
//function/class definitions

//defines the triangle class and the functions inside it
//assigns the private variables with the public variables, it also assigns the formula to the perimeter and area
Triangle::Triangle(double A, double B, double C, double b, double h, double sA, double sB, double sC) {
    
angleA = A;
angleB = B;
angleC = C;
base = b;
height = h;
sideA = sA; 
sideB = sB;
sideC = sC;

peri = sA+sB+sC;
area = ((h * b)/ 2);
}

//this function gets the area from the triangle class and outputs it
void Triangle:: AreaOfTriangle(){
    
    std:: cout << "the area of this triangle: " << area << std:: endl;
    
}
//this function gets the perimeter from the triangle class and outputs it
void Triangle:: PerimeterOfTriangle(){
    std:: cout << "The perimeter of this triangle: " << peri << std:: endl;
    
}
//this function gets the type of the triangle class and outputs it using an if else statement to determine what type it is
 void Triangle::TypeOfTriangle(){
    if( angleA < 90 && angleB < 90 && angleC < 90){
        
        std:: cout << "this triangle is an acute triangle \n";
    } else if (angleA > 90 || angleB > 90 || angleC > 90 ){
        
        std::cout<< "this triangle is a obtuse Triangle \n";
    } else{
        std:: cout << "other triangles \n";
    }
 }