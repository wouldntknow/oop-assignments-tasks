#include <iostream>
#include <string>
using namespace std;
class InjusticeCharacter {
private:
    string name;
    int health;
    int powerLevel;
    string specialAbility;

public:
    InjusticeCharacter( string n, int h, int pl, string a) :
        name(n), health(h), powerLevel(pl), specialAbility(a) {}

   
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Power Level: " << powerLevel << endl;
        cout << "Special Ability: " << specialAbility << endl;
    }
};

int main() {
   
    InjusticeCharacter batman("Batman", 100, 90, "Flying");
    batman.displayDetails();

    return 0;
}
