
#include <iostream>
#include <string>

using namespace std;

class Player {
protected:
    string name;
    int age;
    double amount;
public:
    Player(string n, int a, double am) : name(n), age(a), amount(am) {}
    string getName() { 
        return name; 
        }
    int getAge() { 
        return age;
         }
    double getAmount() { 
        return amount; 
        }
};

class Batsman : virtual public Player {
private:
    string role;
public:
    Batsman(string n, int a, double am, string r) : Player(n, a, am), role(r) {}
    string getRole() { 
        return role; 
        }
    void setRole(string r) { 
        role = r; 
        }
};

class Bowler : virtual public Player {
private:
    string Btype;
public:
    Bowler(string n, int a, double am, string bt) : Player(n, a, am), Btype(bt) {}
    string getBtype() { 
        return Btype;
         }
    void setBtype(string bt) { 
        Btype = bt; 
        }
};

class AllRounder : public Batsman, public Bowler {
public:
    AllRounder(string n, int a, double am, string r, string bt) : Player(n, a, am), Batsman(n, a, am, r), Bowler(n, a, am, bt) {}
};

int main() {
    AllRounder ar("idk", 90, 1000, "Opener", "Fast");
    cout << "Name: " << ar.getName() << endl;
    cout << "Age: " << ar.getAge() << endl;
    cout << "Amount: " << ar.getAmount() << endl;
    cout << "Role: " << ar.getRole() << endl;
    cout << "Bowling Type: " << ar.getBtype() << endl;
    return 0;
}
