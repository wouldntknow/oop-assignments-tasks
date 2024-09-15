#include<iostream>
using namespace std;
int main()
{
    int n,target,sum;
    int array[n];
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    cout<<"Enter elements in the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<"Enter a number for target value: "<<endl;
    cin>>target;
    
    for(int i=0;i<=n;i++)
    {
        int d=i+1;
       if(array[i]+array[d]==target)
       {
        cout<<i<<", "<<d<<endl;
       }    
    
    else {
        cout<<"Can't be found. Enter array values again."<<endl;
        break;
       }
       
    }
    return 0;
}