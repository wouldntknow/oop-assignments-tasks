#include <iostream>
#include <string>
using namespace std;

class pubgPlayers {
    string name;
    int level;
    string experience;
    int points; 
    string weapon;
    string sniperrifle;
    string loadout;
    float accuracyStats;
    string proficiency;

public:
    // Constructor 1
    pubgPlayers(string n, int l, int p, string e, string w) {
        name = n;
        level = l;
        points = p;
        experience = e;
        weapon = w;
    }

    // Constructor 2
    pubgPlayers(string n, int l, int p, string e, string r, float accuracy) {
        name = n;
        level = l;
        points = p;
        experience = e;
        sniperrifle = r;
        accuracyStats = accuracy;
    }

    // Constructor 3
    pubgPlayers(string n, int l, int p, string e, string ploadout, string prof) {
        name = n;
        level = l;
        points = p;
        experience = e;
        loadout = ploadout;
        proficiency = prof;
    }

    // Function to display player information for Constructor 1
    void forPlayerDisplay() {
        cout << "name: " << name<< endl;
        cout << "Level: " << level<< endl;
         cout << "Points scored: " << points<< endl;
        cout << "Experience: " << experience<< endl;
        cout << "Preferred Weapon: " << weapon<< endl;
    }

    // Function to display player information for Constructor 2
    void forPlayerDisplay(string player) {
        cout << "name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Points scored: " << points << endl;
        cout << "Experience: " << experience << endl;
        cout << "Sniper Rifle: " << sniperrifle << endl;
        cout << "Accuracy: " << accuracyStats << endl;
    }

    // Function to display player information for Constructor 3
    void forPlayerDisplay(int n) {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Points scored: " << points << endl;
           cout << "Experience: " << experience << endl;
        cout << "Preferred Loadout: " << loadout << endl;
        cout << "Healing Proficiency: " << proficiency << endl;
    }
};

int main() 
{
    pubgPlayers InfantryPlayer("Fortnight", 500, 5000, "Advanced", "blade");
    pubgPlayers SniperPlayer("Knight", 300, 4000, "Intermediate", "Rifle 8", 89);
     pubgPlayers MedicPlayer("Kryptonite", 200, 3000, "Beginner", "Spear,arrow,etc ","99.00%");
     cout<<"Player Infantry:"<<endl;
    InfantryPlayer.forPlayerDisplay();
    cout<<"Medic Player:"<<endl;
        SniperPlayer.forPlayerDisplay("Sniper");
        cout<<"Sniper Player: "<<endl;
    MedicPlayer.forPlayerDisplay(1);
    
    return 0;
}
