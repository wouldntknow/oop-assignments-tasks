#include <iostream>
#include <string>
using namespace std;
class Book{
	public:
	string name;
	string author;
	string isbn;
	int npages;
	int rpages;
	
	Book()
	{
		//default
		
		
}
			Book(string n,string a,string Isbn,int np)
			{
				name=n;
				author=a;
				isbn=Isbn;
				npages=np;
				
			}

	void npagesread(int r)
	{
		rpages+=r;
		if(rpages>=npages)
		{
			cout<<"You have finished the book"<<endl;
		}
else {
	cout<<"Keep reading!"<<endl;
	cout<<"The number of pages u have read are "<<rpages<<endl;
}
	}

	
};

	
int main ()
{
	Book book1("dfd","Dfd","4354556",25);
	book1.npagesread(10);
	book1.npagesread(5);

	return 0;
	
}