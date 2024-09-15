#include <iostream>
#include <string>
using namespace std;
class RealEstateProperty {
private:
    string address;
    double price;
    double squareFootage;
    bool sold;

public:
    
    RealEstateProperty(const std::string addr, double prc, double sqft) : 
        address(addr), price(prc), squareFootage(sqft), sold(false) {}

    
    void displayDetails() {
        std::cout << "Address: " << address << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Square Footage: " << squareFootage << " sqft" <<endl;
        std::cout << "Status: " << (sold ? "Sold" : "Available") <<endl;
    }

    void Soldout() 
    { 
        sold = true;
    }
};

int main() {
    
    RealEstateProperty property("123 Main St", 250000.0, 2000.0);
    property.displayDetails();

    property.Soldout();
    cout << "After solding out: "<<endl;
    property.displayDetails();

    return 0;
}
