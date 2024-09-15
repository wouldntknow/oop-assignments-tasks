#include<iostream>
#include<string>

using namespace std;
struct airplanes{
    string model;
    string role;
    string origin;
    string manufacturer;
    bool status; // 0-not in servie
                 // 1-In service
};
void func(airplanes*array, int size)
{
    
 for (int i=0;i<size;i++)
 {
    cout<<"Airplane Model: "<<endl;
    cin>>array[i].model;
     cout<<"Airplane Role: "<<endl;
    cin>>array[i].role;
     cout<<"Airplane Origin: "<<endl;
    cin>>array[i].origin;
     cout<<"Airplane Manufacturer: "<<endl;
    cin>>array[i].manufacturer;
     cout<<"Airplane status: "<<endl;
    cin>>array[i].status;

 }
}
int main()
{
int num;
cout<<"Enter the number of airplanes"<<endl;
cin>>num;
airplanes* array = new airplanes[num];
func(array,num);
delete[] array;
 return 0;
}