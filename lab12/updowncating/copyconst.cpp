#include <iostream>
#include <string>
using namespace std;
class Book{

    public:
    string name;
    float *bookprice;
    int c;
    Book(string n):name(n){
         c=3;
        bookprice = new float[c];
        cout<<"Enter prices:" <<endl;
        for(int i=0;i<c;i++){
            cin>>bookprice[i];
        }
for(int i=0;i<c;i++)
{ //for display
    cout<<*(bookprice +i)<<" ";
}
    }
~Book() {
		delete[] bookprice;
		bookprice = nullptr;
	}
//copy constructor
Book(const Book& original)
{
    name=original.name;
    c=original.c;
bookprice = new float[c];
for(int i=0;i<c;i++)
{
    bookprice[i]=original.bookprice[i];
}
}
};
int main()
{
     Book b1("fg");
    // Book b2=b1;
    Book b2(b1);
    cout<<b2.name;

}