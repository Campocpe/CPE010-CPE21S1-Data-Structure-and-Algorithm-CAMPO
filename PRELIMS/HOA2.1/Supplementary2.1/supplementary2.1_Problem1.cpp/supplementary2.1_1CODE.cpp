#include <iostream>
#include <string>

// creates a class for item. it serves as a array for the item. since an array only uses one data type this class's purpose is to have-
// - multiple data types store in that array
class Item {
private: //stores the name,price, quantity and category in the item class
    std::string name;
    int price;
    int quantity;
    std::string category;

public:
    Item(std::string name = "Item", int price = 0, int quantity = 0, std::string category = "Item") {
        //stores it into "this" which is a built in pointer which stores the memory address of the price,name,quantity and category
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->category = category;
    }

    ~Item() {}
     //this is a  Getter functions to retrieve the Item's member variables
     //NOTE! a getter is used to return the value of a private variable
    std::string getName() { return name; }
    int getPrice() { return price; }
    int getQuantity() { return quantity; }
    std::string getCategory() { return category; }
    
    //the function to calculate the sum
    int calculateSum() {
        return price * quantity;
    }
   //the function to print the shopping list of jenna
    void printDetails() {
        std::cout << "Category: [" << category << "] | Name: " << name 
                  << " | Price: PHP " << price 
                  << " | Qty: " << quantity 
                  << " | Subtotal: PHP " << calculateSum() << std::endl;
    }
};


// PROBLEM 1: Fruit & Vegetable Classes


class fruit : public Item {
public:
    // Constructor
    fruit(std::string newname = "Fruit", int newprice = 0, int newquantity = 0)
        : Item(newname, newprice, newquantity, "Fruit") {
        std::cout << "Fruit constructor called" << std::endl;
    }

    // Destructor
    ~fruit() {
        std::cout << "Fruit destructor called" << std::endl;
    }

    // Copy Constructor
    fruit(const fruit &copy) : Item(copy) {
        std::cout << "Fruit copy constructor called" << std::endl;
    }

    // Copy Assignment Operator
    fruit& operator=(const fruit &copy) {
        std::cout << "Fruit copy assignment called" << std::endl;
        if (this != &copy) {
            Item::operator=(copy);
        }
        return *this;
    }
};

class vegetable : public Item {
public:
    // Constructor
    vegetable(std::string newname = "Vegetable", int newprice = 0, int newquantity = 0)
        : Item(newname, newprice, newquantity, "Vegetable") {
        std::cout << "Vegetable constructor called" << std::endl;
    }

    // Destructor
    ~vegetable() {
        std::cout << "Vegetable destructor called" << std::endl;
    }

    // Copy Constructor
    vegetable(const vegetable &copy) : Item(copy) {
        std::cout << "Vegetable copy constructor called" << std::endl;
    }

    // Copy Assignment Operator
    vegetable& operator=(const vegetable &copy) {
        std::cout << "Vegetable copy assignment called" << std::endl;
        if (this != &copy) {
            Item::operator=(copy);
        }
        return *this;
    }
};


// PROBLEM 3: TotalSum Function

// the function to calculate the grand total of the items in jenna's list
int TotalSum(Item* GroceryList[], int size) {
    int grandTotal = 0;
    for (int i = 0; i < size; i++) {
        if (GroceryList[i] != NULL) {
            grandTotal += GroceryList[i]->calculateSum();
        }
    }
    return grandTotal;
}



//MAIN CALLERR
int main() {
    //assigns the GroceryList array a size
    const int SIZE = 4;
    Item* GroceryList[SIZE];

    // PROBLEM 2: Dynamic allocation into GroceryList
    //assigns the array with the category, quantity and price
    GroceryList[0] = new fruit("Apple", 10, 7);
    GroceryList[1] = new fruit("Banana", 10, 8);
    GroceryList[2] = new vegetable("Broccoli", 60, 12);
    GroceryList[3] = new vegetable("Lettuce", 50, 10);
    
    //prints out the values in the array
    std::cout << "\n--- Displaying Items ---" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        if (GroceryList[i] != NULL) {
            GroceryList[i]->printDetails();
        }
    }

    // PROBLEM 3: Calculate Total Sum
    
    // calls out the total sum function
    std::cout << "Grand Total: PHP " << TotalSum(GroceryList, SIZE) << std::endl;

    // PROBLEM 4: Delete Lettuce and de-allocate memory
    
    //deletes letuce in the GroceryList 
    
    for (int i = 0; i < SIZE; i++) {
        if (GroceryList[i] != NULL && GroceryList[i]->getName() == "Lettuce") {
            delete GroceryList[i];   // Free heap memory
            GroceryList[i] = NULL;   // Clear pointer to prevent dangling reference
            std::cout << "Lettuce deleted successfully." << std::endl; 
        }
    }
   //outputs the grand total without the lettuce included
    std::cout << "Updated Grand Total: PHP " << TotalSum(GroceryList, SIZE) << std::endl;

    // Clean up remaining allocated memory
    for (int i = 0; i < SIZE; i++) {
        if (GroceryList[i] != NULL) {
            delete GroceryList[i];
            GroceryList[i] = NULL;
        }
    }

    return 0;
}