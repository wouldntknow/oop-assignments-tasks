#include <iostream>
#include <string>
using namespace std;

class Animals{
    public:
virtual void cats()=0;
virtual void dogs()=0;

}; 
class cat: public Animals{
    public:
    void cats()
    {
        cout<<"Cats meow"<<endl;
    }
    void dogs(){
        cout << "This is a cat, not a dog!" << endl; // all virtual functions have to be implemented
        
    }
};
class dog: public Animals{
    public:
     void dogs()
    {
        cout<<"Dogs bark"<<endl;
    }
    void cats(){
cout << "This is a dog, not a cat!" << endl;
    }
};
int main()
{
    cat myCat;
myCat.cats();
    dog myDog;
    myDog.dogs();
    
    return 0;
}