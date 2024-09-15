#include <iostream>
#include <string>
using namespace std;
class Smartphone {
private:
    string company;
    string model;
    string displayResolution;
    int ram;
    int rom;
    int storage;

public:
    Smartphone( string comp, string mdl, string resolution, int ramSize, int romSize, int storageSize) :
        company(comp), model(mdl), displayResolution(resolution), ram(ramSize), rom(romSize), storage(storageSize) {}

    string getCompany() {
        return company;
    }

    string getModel(){
        return model;
    }

    string getDisplayResolution()  {
        return displayResolution;
    }

    int getRAM() {
        return ram;
    }

    int getROM(){
        return rom;
    }

    int getStorage(){
        return storage;
    }

    void setCompany(string comp) {
        company = comp;
    }

    void setModel(string mdl) {
        model = mdl;
    }

    void setDisplayResolution(string resolution) {
        displayResolution = resolution;
    }

    void setRAM(int ramSize) {
        ram = ramSize;
    }

    void setROM(int romSize) {
        rom = romSize;
    }

    void setStorage(int storageSize) {
        storage = storageSize;
    }

    void makePhoneCall(string number) {
        cout << "Making a phone call to " << number << endl;
    }

    void sendMessage(string recipient, string message) {
        cout << "Sending a message to " << recipient << ": " << message << endl;
    }

    void connectToWifi(string wifiName) {
        cout << "Connecting to Wi-Fi network: " << wifiName << endl;
    }

    void browseInternet() {
        cout << "Browsing the internet" << endl;
    }
    void display(){
     cout << "Company: " << getCompany() << endl;
    cout << "Model: " <<getModel() << endl;
    cout << "Display Resolution: " << getDisplayResolution() << endl;
    cout << "RAM: " <<getRAM() << " GB" << endl;
    cout << "ROM: " << getROM() << " GB" << endl;
    cout << "Storage: " << getStorage() << " GB" << endl;
    }
};

int main() {
    Smartphone myPhone("Samsung", "Galaxy S21", "2400x1080", 8, 128, 256);
    myPhone.display();
     myPhone.makePhoneCall("111-456-7890");
    myPhone.sendMessage("Hamna", "Hello!");
    myPhone.connectToWifi("MyHomeWiFi");
    myPhone.browseInternet();
//created 2 objects
Smartphone Apple("Apple", "Apply 14 pro", "2400x1080", 8, 128, 256);
Apple.display();
    

    Apple.makePhoneCall("02178890433");
    Apple.sendMessage("Mom", "Hello!");
    Apple.connectToWifi("MyHomeWiFi");
    Apple.browseInternet();

    return 0;
}
