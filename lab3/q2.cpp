#include <iostream>
#include <string>
using namespace std;


class HotelService {
private:
    string serviceName;
    double cost;

public:
   
    HotelService(string n, double c) : 
        serviceName(n), cost(c) {}

    void displayDetails()  {
        cout << "Service Name: " << serviceName <<endl;
        cout << "Cost: Rs." << cost << endl;
    }
};

int main() {
  
    HotelService roomService("Room Cleaning", 1000);
    roomService.displayDetails();

    return 0;
}
