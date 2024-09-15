#include <iostream>
#include <cmath>
using namespace std;
float sqrtnum(int num)
{
    if(num<0)
    {
    
       throw runtime_error("Cannot calculate square root of a negative number");
    }
return sqrt(num);
}
int main()
{
    int num;
    cout<<"Enter a number: "<<endl;
    cin>>num;
    cout<<"Square root of "<<num<<" is "<<sqrtnum(num);
    
    return 0;
    
}