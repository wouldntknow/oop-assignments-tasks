#include <iostream>
#include <string>
#include <list>
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Player {
public:
    string playerName;
    int playerId;
    int health;

    Player(string n, int a, int h) : playerName(n), playerId(a), health(h) {}
};

class Weapon {
public:
    list<string> weapons;

    Weapon() {
        weapons.push_back("Knife");
        weapons.push_back("Spear");
        weapons.push_back("Crossbow");
        weapons.push_back("Club");
        weapons.push_back("Blade"); // 5 items
    }

    void use() {
        cout << "List of Weapons:\n";
        for (string weapon : weapons) {
            cout << weapon << endl;
        }
    }

    void selection() {
        int c;
        cout << "Enter your choice (choose a number):" << endl;
        cin >> c;
        if(c<1 & c<=5){
        list<string>::iterator itr = weapons.begin();
        advance(itr, c);

       
        cout << "Option Selected:" << *itr << endl;
    }
    }
};

class Character : public Player {
public:
    int level;
    int points;
    string experience;

    Character(string n, int pId, int pHealth, int a, int b, string c)
        : Player(n, pId, pHealth), level(a), points(b), experience(c) {}

    void levelUp() {
        if (points >= 10) {
            level++;
            if (experience == "Beginner")
                experience = "Intermediate";
            else if (experience == "Intermediate")
                experience = "Advanced";
            else if (experience == "Advanced")
                experience = "Expert";
        }
    }

    void playGame(int& ehealth, int damage, Weapon& w1) {
        w1.use();
        w1.selection();
        cout << "Enemy's health before: " << ehealth << endl;
        ehealth -= damage; // Update enemy's health
        cout << "Enemy's health after attack: " << ehealth << endl;
    }
    friend class weapon;
};

class Enemy : public Player {
public:
    int damage;

    Enemy(string m, int a, int b, int d)
        : Player(m, a, b), damage(d) {}

    void attack(int& cHealth, Weapon& w2) {
        w2.use();
        w2.selection();
        cout << "Character's health before: " << cHealth << endl;
        cHealth -= damage; // Update character's health
        cout << "Character's health after attack: " << cHealth << endl;
    }
};

int main() {
    srand(time(nullptr)); 

    
    Character c1("hamna", 5112, 100, 3, 0, "Beginner");
    Character c2("a", 5112, 10, 2, 11, "Intermediate");
    Character c3("ha", 5112, 1, 5, 12, "Advance");

    Weapon weapon;
    
    cout << "Character 1 attacks Character 2:" << endl;
    c1.playGame(c2.health, 10, weapon); 
    cout << endl;

    cout << "Character 3 attacks Character 1:" << endl;
    c3.playGame(c1.health, 5, weapon); 
    cout << endl;

    cout << "Character 1's health: " << c1.health << endl;
    cout << "Character 2's health: " << c2.health << endl;
    cout << "Character 3's health: " << c3.health << endl;

    return 0;
}
