#include <iostream>


//the class for the triangle
class Triangle{

    //this private specifier has the variables of the angles, since its private it can be only accessed within this class
    //- and not on the main program
    private:
    double totalAngle, angleA, angleB, angleC;
    
    //this is a public specifier, the variables in it can be called in and out of the class 
    public:

    //this function is where we get the angles of each side of the triangle
    Triangle(double A, double B, double C);

    //this is the same as the Triangle function but its a void
    void setAngles(double A, double B, double C);
    
    //this function validates the triangle whether if its a triangle or not
    const bool validateTriangle();
    };


int main(){
//MAIN CALLER

    //this is where the value is set inside the function
    Triangle set1(40, 50, 110);

    //this part uses an if else statement where it,opens up the validateTriangle function to check if its a real triangle
    if(set1.validateTriangle()){
    std::cout << "The shape is a valid triangle.\n";
    } else {
    std::cout << "The shape is NOT a valid triangle.\n";
     }
    return 0;


}
    
// this definition is where we assign the public variables to the private variables which basically stores the data in in the class
Triangle::Triangle(double A, double B, double C) {
angleA = A;
angleB = B;
angleC = C;
totalAngle = A+B+C;
}
//its the same as the triangle function but again this is the "void" type version
void Triangle::setAngles(double A, double B, double C) {
angleA = A;
angleB = B;
angleC = C;
totalAngle = A+B+C;
}

//this function is where it validates the triangle by using a condition where it should be less or equal than 180 and returns the output
const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);

}