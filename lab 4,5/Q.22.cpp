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
	
	Book(int n, int r) : npages(n),rpages(r){}

		/*	Book(string n,string a,string Isbn,int rp)
			{
				name=n;
				author=a;
				isbn=Isbn;
				npages=20;
				rpages=rp; 
			
			} 
		*/
		void set(string N, string a, string Isbn)
		{
			name=N;
			author=a;
			isbn=Isbn;
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
	Book book2(1000,0);
	book2.npagesread(2);
	book2.npagesread(3);

	return 0;
	
}