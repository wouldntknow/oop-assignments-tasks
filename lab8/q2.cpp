
#include <iostream>
using namespace std;
class Bike {
private:
     string brand;
    double cost;

public:
    
    Bike( string b, double c) : brand(b), cost(c) {}

    bool operator<(const Bike& other) const 
	{
        return cost < other.cost;
    }

    bool operator>(const Bike& other) const 
	{
        return cost > other.cost;
    }

    bool operator==(const Bike& other) const {
        return cost == other.cost;
    }

    bool operator!=(const Bike& other) const {
        return cost != other.cost;
    }

    void display() const {
         cout << "Brand: " << brand << ", Cost: $" << cost <<  endl;
    }
};

int main() {
	
	string n1,n2;
	float c1,c2;
	cout<<"Enter Bike 1 name:"<<endl;
	cin>>n1;
	cout<<"Enter cost of bike 1"<<endl;
	cin>>c1;
	cout<<"Enter Bike 2 name:"<<endl;
	cin>>n2;
	cout<<"Enter cost of bike 2"<<endl;
	cin>>c2;
	
    Bike b1(n1, c1);
    Bike b2(n2,c2);

    if (b1 < b2) {
         cout << n1<<" is cheaper than " <<n2<<endl;
    } else if (b1 > b2) {
         cout << n1<<" is expensive than " <<n2 << endl;
    }

    if (b1 == b2) {
         cout << n1<<" and "<<n2<<" have the same cost" <<  endl;
    }

    if (b1 != b2) {
         cout <<n1<<" and "<<n2<<" have different costs" <<  endl;
    }

    return 0;
}
