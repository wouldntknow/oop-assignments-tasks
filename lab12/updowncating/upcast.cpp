
#include <iostream>
using namespace std;


class base {
public:
	 void print() { cout << "print base class\n"; }

};

class derived : public base {
public:
	void print() { cout << "print derived class\n"; }
void func(){ cout<<"Another func of derived class\n";}
};
int main()
{
    base *ptr;
    derived d;
    ptr=&d; 
    //base class reference
    base &refer=d;
    refer.print();
    ptr->print();

}