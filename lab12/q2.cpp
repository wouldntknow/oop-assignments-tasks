#include <iostream>
#include <string>
using namespace std;
template <typename T>
T maxValue(T v1, T v2)
{
   
    if(v1>v2)
    {
        return v1;
    }
    else {
        return v2;
    }
}
int main()
{
    
    maxValue<float>(3.5, 4.5);
    cout<<"Max value is "<< maxValue<float>(3.5,4.5)<<endl;
    return 0;
}