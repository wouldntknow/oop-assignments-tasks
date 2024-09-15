
#include<iostream>
using namespace std;
class Animal{
protected:
	string name;
	int age;
	static int count;
	public:
		Animal(string n,int a):name(n),age(a){
            count++;
            }
		void putdata()
		{
			cout<<"Details:"<<endl;
			cout<<"Name:"<<name<<endl;
			cout<<"Age:"<<age<<endl;
		
			}
			static int total(){
				return count;
			}
		
};

int Animal::count = 0;

class Eagle: virtual public Animal{
	protected:
		int wings;
		int heads;
		public:
			Eagle(string n,int a,int w=0,int h=0):Animal(n,a),wings(w),heads(h)
			{}
			void getdata()
		{
				int w,h;
	cout<<"Enter number of wings:"<<endl;
			cin>>w;
				cout<<"Enter number of heads:"<<endl;
			cin>>h;
			wings=w;
			heads=h;
			
			
		}
		void putdata() 
		{
			
			cout<<endl;
			cout<<"Eagle"<<endl;
			getdata();
	Animal::putdata();
		
				cout<<"Wings :"<<wings<<endl;
					cout<<"Heads :"<<heads<<endl;
		}
			
};

class Lion: virtual public Animal{
	protected:
		int teeth;
		public:
			Lion(string n,int a,int t=0):teeth(t),Animal(n,a){
			}
			void total_teeth()
			{
				int tt;
				cout<<"Total teeth:"<<endl;
				cin>>tt;
				teeth=tt;
			}
			void putdata() 
			{ cout<<endl;
			
				cout<<"Lion"<<endl;	
		total_teeth();
			Animal::putdata();
			
		cout<<"Teeth:"<<teeth;
		
			}
			
		
};
class Griffin:public Eagle,public Lion{
	public:
		Griffin(string n,int a,int w=0,int h=0,int t=0):Animal(n,a),Eagle(n,a,w,h),Lion(n,a,t){
		}
		void putdata()
		 
		{  cout<<endl;
		cout<<"Griffen"<<endl;
		 
			
			Eagle::putdata();
			
			
			Lion::putdata();
			
			
			
		}
};

int main()
{
	Eagle e1("burzaak",10);
	Lion l1("burrak",7);
	Griffin g1("griffen",10);
	 
	 
	 e1.putdata();
	
	
	
	 l1.putdata();
	 
	 g1.putdata();
	 cout<<endl;
	cout<<"Total Animal count:"<<Animal::total();
}
