

#include <iostream>
#include <string>

using namespace std;


class Colddrink {
    protected:
    string name;
    int price;

public:
    Colddrink(string n, int p) : name(n), price(p) {}

    virtual float calPrice() const {
        return price;
    }

   
    virtual void display() const {
        cout << "Name: " << name << endl;
        cout<<"Price:$" << calPrice() << endl;
    }

    virtual ~Colddrink() = default;
};


class Soda : public Colddrink {

    int ml;

public:
    Soda(string n, int p, int quantity) : Colddrink(n, p), ml(quantity) {}

    
    float calPrice() const {
        float baseP = price;
        if (ml >= 30 && ml <= 50) {
            baseP += 20;
        } else if (ml > 50 && ml <= 80) {
            baseP += 30;
        } else if (ml > 80 && ml <= 100) {
            baseP += 40;
        }
        return baseP;
    }
};


class Juice : public Colddrink {
    string fruit;

public:
    Juice(string n, int p, string f) : Colddrink(n, p), fruit(f) {}

    void display() const  {
        cout << "Name: " << name <<endl;
        cout<< "Fruit: " << fruit<<endl;
        cout << "Price:$ " << calPrice()<<endl;

    }
};

class EnergyDrink : public Colddrink {

    double caffeineLevel;

public:
    EnergyDrink(string n, int p, double c) : Colddrink(n, p), caffeineLevel(c) {}

    void display() const  {
        cout << "Name: " << name << endl;
        cout<<"Caffeine Level: " << caffeineLevel << endl;
        cout<<" Price: $ " << calPrice()<<endl;

    }
};

int main() {
    Soda colaNext("Cola Next", 2, 65);
    Juice Slice("Slice Mango Juice", 3.5, "Mango");
    EnergyDrink redBull("Red Bull", 4, 80.0);

    colaNext.display();
    Slice.display();
    redBull.display();

    return 0;
}

