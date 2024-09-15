#include <iostream>
#include <cmath>
using namespace std;

class Flyable {
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longgitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};


class Drone {
protected:
    float latitude;
    float longitude;
    float altitude;
    float speed;

public:
    Drone(float lat, float lon, float alt, float s)
        : latitude(lat), longitude(lon), altitude(alt), speed(s) {}

    void adjustAltitude(float meters) {
        altitude += meters;
    }

    void setSpeed(float s) {
        speed = s;
    }

    
    float getLatitude() const {
        return latitude;
    }

    float getLongitude() const {
        return longitude;
    }

    float getAltitude() const {
        return altitude;
    }

    float getSpeed() const {
        return speed;
    }
};


class ReconDrone : public Drone, public Flyable, public Scannable {
private:
    float cameraRes;
    float flightT;

public:
    ReconDrone(float lat, float lon, float alt, float s, float resolution, float maxTime)
        : Drone(lat, lon, alt, s), cameraRes(resolution), flightT(maxTime) {}

    void takeoff() override {
    cout << "Recon D taking off." <<endl;
    }

    void land() override {
    cout << "Recon D landing." <<endl;
    }

    void navigateTo(float latitude, float longgitude, float altitude) override {
       
        float dLat = latitude - getLatitude();
        float dLon = longgitude - getLongitude();
        float dAlt = altitude - getAltitude();

        float earthRadius = 6371000; 

        float a = pow(sin(dLat / 2), 2) + cos(getLatitude()) * cos(latitude) * pow(sin(dLon / 2), 2);
        float c = 2 * atan2(sqrt(a), sqrt(1 - a));

        float distance = earthRadius * c;
        float timeRequired = distance / getSpeed(); 

    cout << "Estimated time to reach destination: " << timeRequired << " seconds." <<endl;
    }

    void scanArea(float radius) override {
    cout << "Scanning area with radius " << radius << " meters." <<endl;
    }
};

int main() {
    
    ReconDrone D(0, 0, 100, 10, 12, 3600); 


    D.takeoff();
    D.navigateTo(30, 40, 200);
    D.scanArea(100);
    D.land();

    return 0;
}
