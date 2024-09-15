#include <iostream>
#include <string>
#include <list>
using namespace std;

class Restaurant {
    string name;
    string address;
    string phone;
    int rating;
    list<string> menu;

public:
    // Default constructor
    Restaurant(){}

    // Parameterized constructor
    Restaurant(string n, string a, string num, int r): name(n), address(a), phone(num), rating(r) {
        cout << "Restaurant Name: " << name << endl;
        cout << "Restaurant Address: " << address << endl;
        cout << "Restaurant Phone number: " << phone << endl;
        cout << "Restaurant Rating: " << rating << endl;
    }

    void addMenu(list<string> menuItems) {
        menu = menuItems;
    }

    void getMenu() {
        cout << "List of Menu Items available:" << endl;
        for(string menuItems : menu) {
            cout << menuItems << endl;
        }
    }
};

class Italian : public Restaurant {
    string pasta;
    string pizza;

public:
    Italian(string n, string a, string num, int r, string piz, string pas): Restaurant(n, a, num, r), pizza(piz), pasta(pas) {}

    void makePasta(string pasta) {
        cout << pasta << " pasta have been prepared!" << endl;
    }

    void makePizza(string pizza) {
        cout << pizza << " pizza have been prepared!" << endl;
    }
};

class Mexican : public Restaurant {
    string tacos;
    string burritos;

public:
    Mexican(string n, string a, string num, int r, string t, string b): Restaurant(n, a, num, r), tacos(t), burritos(b) {}

    void makeTacos(string tacos) {
        cout << tacos << " tacos have been prepared!" << endl;
    }

    void makeBurritos(string burritos) {
        cout << burritos << " burrito have been prepared!" << endl;
    }
};

int main() {
    Italian I1("Zeytin", "dfgf", "57678768", 5, "Alferedo", "Ranch");
    I1.addMenu({"burger", "sausages", "noodles", "drinks"});
    I1.getMenu();
    I1.makePasta("Alferedo");
    I1.makePizza("Ranch");

    Mexican M1("The Mexican House", "dfsdf", "34545", 4, "Spicy", "Vegan");
    M1.addMenu({"chicken burritos", "Special tacos", "wings", "drinks"});
    M1.getMenu();
    M1.makeBurritos("Spicy");
    M1.makeTacos("Vegan");

    return 0;
}
