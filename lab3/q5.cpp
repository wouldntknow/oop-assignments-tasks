#include <iostream>
#include <string>
using namespace std;
class UberRide {
private:
string riderName;
string driverName;
    double distance;
    double fare;

public:
    UberRide(string rn, string dn, double d) :
        riderName(rn), driverName(dn), distance(d) {
    
            calculateFare();
        }

    void calculateFare() {
       
        double fareRatePerKm = 20.0;
        fare = distance * fareRatePerKm;
    }

string getRiderName() const {
        return riderName;
    }

string getDriverName() const {
        return driverName;
    }

    double getDistance() const {
        return distance;
    }

    double getFare() const {
        return fare;
    }
};

int main() {
   
    UberRide ride("Ali", "Ahmed", 10.5); // Assume the distance is 10.5 kilometers from Saddar to Gulistan block 13


cout << "Rider Name: " << ride.getRiderName() <<endl;
cout << "Driver Name: " << ride.getDriverName() <<endl;
cout << "Distance: " << ride.getDistance() << " kilometers" <<endl;
cout << "Fare: Rs. " << ride.getFare() <<endl;

    return 0;
}
