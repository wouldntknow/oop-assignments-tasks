#include <iostream>
#include <string>
using namespace std;

template <typename T, typename t>
class Pets {
protected:
    T name;
    t age;
public:
    Pets(T n, t a) : name(n), age(a) {}
    virtual void makeSound() = 0;
    void display()
    {
        cout<<"Following are the pet details: "<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

template <typename T, typename t>
class Dog : public Pets<T, t> {
public:
    Dog(T n, t a) : Pets<T, t>(n, a) {}

    void makeSound() override {
        cout << "The dog barks" << endl;
    }
};

template <typename T, typename t>
class Cat : public Pets<T, t> {
public:
    Cat(T n, t a) : Pets<T, t>(n, a) {}

    void makeSound() override {
        cout << "The cat meows" << endl;
    }
};

template <typename T, typename t>
class Bird : public Pets<T, t> {
public:
    Bird(T n, t a) : Pets<T, t>(n, a) {}

    void makeSound() override {
        cout << "Birds are chirping" << endl;
    }
};

int main() {
    Dog<string, int> D1("Golden Retreiver", 5);
    Cat<string, int> C1("Persian Cat", 3);
    Bird<string, int> B1("Tweet", 1);
D1.display();
    D1.makeSound();
    C1.display();
    C1.makeSound();
    B1.display();
    B1.makeSound();

    return 0;
}
