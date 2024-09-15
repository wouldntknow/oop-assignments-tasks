//23k-2079
#include <iostream>
#include <string>
using namespace std;

class Pet {
    string HealthS;
    string SpecialS;
    int Hungerl;
    int HappinessL;

public:
    Pet() {
        HealthS = "Unknown";
        SpecialS = "None";
        Hungerl = 0;
        HappinessL = 0;
    }

    Pet(string HealthS, string SpecialS, int Hungerl, int HappinessL) {
        this->HealthS = HealthS;
        this->SpecialS = SpecialS;
        this->Hungerl = Hungerl;
        this->HappinessL = HappinessL;
    }

    void setHealthS(string HealthS) {
        this->HealthS = HealthS;
    }

    void setSpecialS(string SpecialS) {
        this->SpecialS = SpecialS;
    }

    void setHungerl(int Hungerl) {
        this->Hungerl = Hungerl;
    }

    void setHappinessL(int HappinessL) {
        this->HappinessL = HappinessL;
    }

    string getHealthS() {
        return HealthS;
    }

    string getSpecialS() {
        return SpecialS;
    }

    int getHungerl() {
        return Hungerl;
    }

    int getHappinessL() {
        return HappinessL;
    }

    void Displaydetails() {
        cout << "Pet health status is : " << HealthS << endl;
        cout << "Pet special skills is: " << SpecialS << endl;
        cout << "Pet hunger level  is : " << Hungerl << endl;
        cout << "Pet happiness level is : " << HappinessL << endl;
    }

    void UpHappiness() {
        int Hungerlevel;
        cout << "Enter hunger level of pet : " << endl;
        cin >> Hungerlevel;
        if (Hungerlevel <= 4) {
            cout << "Pet is hungry" << endl;
            HappinessL = max(1, HappinessL - 1);
            Hungerl = min(10, Hungerl + 1);
        } else if (Hungerlevel >= 7) {
            HappinessL = min(10, HappinessL + 1);
            Hungerl = max(1, Hungerl - 1);
        }
    }

    void updateHunger() {
        int running;
        cout << "How many km can the pet run? : " << endl;
        cin >> running;
        if (running >= 20) {
            cout << "Pet is getting starving, feed pet" << endl;
            Hungerl = min(10, Hungerl + 1);
            HappinessL = max(1, HappinessL - 1);
        }
    }

    void updateHealth() {
        int health;
        cout << "Enter health points : " << endl;
        cin >> health;
        if (health < 4) {
            health = health - 1;
            cout << "Pet is getting sick" << endl;
            HealthS = "Sick";
        }
    }
};

class Adopter {
    string name;
    int number;
    Pet pets[3];

public:
    Adopter(string name, int number) {
        this->name = name;
        this->number = number;
    }

    void setname(string name) {
        this->name = name;
    }

    void setnumber(int number) {
        this->number = number;
    }

    string getname() {
        return name;
    }

    int getnumber() {
        return number;
    }

    void adoptPet(Pet pet) {
        for (int i = 0; i < 3; ++i) {
            if (pets[i].getHappinessL() == 0) {
                pets[i] = pet;
                break;
            }
        }
    }

    void returnPet(int index) {
        pets[index].setHappinessL(0);
    }

    void display() {
        for (int i = 0; i < 3; ++i) {
            cout << "Pet " << i + 1 << ":" << endl;
            pets[i].Displaydetails();
        }
    }
};

int main() {
    Pet pet1("Healthy", "Talking", 7, 9);
    pet1.Displaydetails();
    pet1.UpHappiness();
    pet1.Displaydetails();
    pet1.updateHunger();
    pet1.Displaydetails();
    pet1.updateHealth();
    pet1.Displaydetails();

    Adopter A1("Anne", 230434053);
    A1.adoptPet(pet1);
    A1.display();
}

