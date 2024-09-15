#include <iostream>
#include <string>
using namespace std;

 template<typename t,typename e>
class Pair{
t first;
e second;
public:
Pair(t f, e s):first(f), second(s){}

void display()
{
    cout<<"First value: "<<first<<endl;
    cout<<"Second Value: "<<second<<endl;
}
};
int main()
{
    Pair<int, float>intPair(5,4.5); //one integer value and one float
    intPair.display();

   // intPair.display();
   return 0;
}