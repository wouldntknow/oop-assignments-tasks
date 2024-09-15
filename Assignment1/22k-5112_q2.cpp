//23K-2079
#include<iostream>
using namespace std;

class Dhaba{
	int Tseats;
	int seatsOcc;
	int freeS;
	bool clean;
	
	public:
	Dhaba()
	{
		Tseats=0;
		seatsOcc=0;
		freeS=0;
		clean=false; 
	}
	Dhaba(int Tseats, int seatsOcc, int freeS, bool clean)
	{
		this->Tseats=Tseats;
		this->seatsOcc=seatsOcc;
		this->freeS=freeS;
		this->clean=clean;
	}
	void settotalseats(int Tseats)
	{
		this->Tseats=Tseats;
	}
	void setseatsOcc(int seatsOcc)
	{
		this->seatsOcc=seatsOcc;
	}
	void setfreeS(int freeS)
	{
		this->freeS=freeS;
	}
	void setclean(bool clean)
	{
		this->clean=clean;
	}
	
	int gettotalseats()
	{
		return Tseats;
	}
	int getseatsOcc()
	{
		return seatsOcc;
	}
	int getfreeS()
	{
		return freeS;
	}
	bool getclean()
	{
		return clean; 
	}
	void display()
	{
		cout<<"Total seats at each table : "<<Tseats<<endl;
		cout<<"Current seats occupied : "<<seatsOcc<<endl;
		cout<<"Seats available : "<<freeS<<endl;
		cout<<"Is table clean?: "<<clean<<endl;
	}
	void occupied(Dhaba tab[],int s,int size)
	{
		cout<<endl;
		cout<<"***************************"<<endl;
		int numoftables;
		cout<<"Enter number of tables : "<<endl;
		cin>>numoftables;
		for(int i=0;i<numoftables;i++)
		{
			if(tab[i].freeS >= size)
			{
				tab[i].freeS -= size;
				tab[i].seatsOcc = size;
				cout<<"Table is assigned to group of friends "<<i+1<<endl;
			}
			else
			{
				cout << "Table " << i + 1 << " does not have enough seats for the group." << endl;
			}
		}
	}
	
	void HavingL()
	{
		cout<<endl;
		cout<<"*************************"<<endl;
		if(clean == true) 
		{
			cout<<"Group of friends having lunch"<<endl;
		}
		else{
			cout<<"They are leaving without having lunch"<<endl;
		}
	}
	void LeavingT()
	{
		cout<<endl;
		cout<<"*******************************"<<endl;
		if(clean == true)
		{
			cout<<"They are leaving"<<endl;
		}
		else{
			cout<<"They are not leaving, they are still seated"<<endl;
		}
	}
	void CleaningT()
	{
		cout<<endl;
		cout<<"************************"<<endl;
		if(seatsOcc == 0 && clean == false) 
		{
			cout<<"Table is not clean. Staff is cleaning"<<endl;
		}
		else{
			cout<<"Table is clean"<<endl;
		}
	}
	void EmptyT(int table_number)
    {
        seatsOcc = 0; 
        freeS += Tseats; 
        cout << "Table " << table_number << " is now empty." << endl;
    }
};

int main()
{
    Dhaba tables[5] = {
        Dhaba(8, 0, 8, false),
        Dhaba(8, 0, 8, false),
        Dhaba(4, 0, 4, false),
        Dhaba(4, 0, 4, false),
        Dhaba(4, 0, 4, false)
    };

    tables[0].occupied(tables, 5, 4);

    tables[1].occupied(tables, 5, 6);

    cout << "Table 1:" << endl;
    tables[0].HavingL();
    tables[0].LeavingT();
    tables[0].CleaningT();
    tables[0].display();

    tables[1].EmptyT(1);
return 0;
}
