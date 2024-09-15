#include <iostream>
#include <string>
using namespace std;

class Medicine {
    string name;
    string formula;
    int price;
    string mDate;
    string exDate;
    

public:
    Medicine(string n, string f, int p, string md, string ed) : name(n), formula(f), price(p), mDate(md), exDate(ed) {
        
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Retail Price: Rs. " << price << endl;
        cout << "Manufacturing Date: " << mDate << endl;
        cout << "Expiration Date: " << exDate << endl;
    }

    friend class pharmacist;
    friend class Counter;
};



class Tablet : public Medicine {
    bool sucroseLevel;

public:
    //Tablet(bool s) : Medicine("", "", 0, "", ""), sucroseLevel(s) {}

    void display() {
        Medicine::display();
        cout << "Sucrose Level: " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine {
    string absorption;

public:

    void display() {
        Medicine::display();
        cout << "Absorption Percentage: " << absorption << endl;
    }
};

class Syrup : public Medicine {
    string quantity;

public:
 

    void display() {
        Medicine::display();
        cout << "Quantity (ml): " << quantity << endl;
    }
};

class pharmacist {
public:
    void searchMedicine(string s, Medicine& M) {
        if (s == M.name) {
            M.display();
        }
        else {
            cout << "Enter correct medicine name!" << endl;
        }
    }
};

class Counter {
    static int revenue;
    static int count;

public:
    void searchMedicine(string s, Medicine M) {
        if (s == M.name) {
            cout<<"Recommended Medicine: "<<endl;
            M.display();

        }
        else {
            cout << "Enter correct medicine name!" << endl;
        }
    }

    static void updateRevenue(Medicine M) {
        revenue += Counter::count * M.price;
        cout << "Total Revenue: " << revenue << endl;
    }
    static void checkCount()
    {
            count++;
        }
    
};

int Counter::revenue;
int Counter::count;

int main() {
    Medicine M("Panadol", "hv", 200, "5/6/2024", "5/12/2025");
    Counter C,C1;
    C.searchMedicine("Panadol", M);
          Counter::checkCount();
    Counter::updateRevenue(M);
    return 0;
}
