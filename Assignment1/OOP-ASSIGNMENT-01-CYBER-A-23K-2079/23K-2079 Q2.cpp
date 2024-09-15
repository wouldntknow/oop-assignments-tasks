//23K-2079
#include<iostream>
using namespace std;

class dhaba{
	int totalseats;
	int currseatocupied;
	int freeseat;
	bool clean;
	
	public:
	dhaba()
	{
		totalseats=0;
		currseatocupied=0;
		freeseat=0;
		clean=false; 
	}
	dhaba(int totalseats, int currseatocupied, int freeseat, bool clean)
	{
		this->totalseats=totalseats;
		this->currseatocupied=currseatocupied;
		this->freeseat=freeseat;
		this->clean=clean;
	}
	void settotalseats(int totalseats)
	{
		this->totalseats=totalseats;
	}
	void setcurrseatocupied(int currseatocupied)
	{
		this->currseatocupied=currseatocupied;
	}
	void setfreeseat(int freeseat)
	{
		this->freeseat=freeseat;
	}
	void setclean(bool clean)
	{
		this->clean=clean;
	}
	
	int gettotalseats()
	{
		return totalseats;
	}
	int getcurrseatocupied()
	{
		return currseatocupied;
	}
	int getfreeseat()
	{
		return freeseat;
	}
	bool getclean()
	{
		return clean; 
	}
	void display()
	{
		cout<<"total seats at each table is : "<<totalseats<<endl;
		cout<<"current seats occupied are : "<<currseatocupied<<endl;
		cout<<"available seat is : "<<freeseat<<endl;
		cout<<"table is clean or not : "<<clean<<endl;
	}
	void occupytable(dhaba tab[],int s,int size)
	{
		cout<<endl;
		cout<<"***************************"<<endl;
		int numoftables;
		cout<<"enter number of tables : "<<endl;
		cin>>numoftables;
		for(int i=0;i<numoftables;i++)
		{
			if(tab[i].freeseat >= size)
			{
				tab[i].freeseat -= size;
				tab[i].currseatocupied = size;
				cout<<"table is assigned to group of friends "<<i+1<<endl;
			}
			else
			{
				cout << "Table " << i + 1 << " does not have enough seats for the group." << endl;
			}
		}
	}
	
	void havinglunch()
	{
		cout<<endl;
		cout<<"*************************"<<endl;
		if(clean == true) 
		{
			cout<<"group of friends having lunch"<<endl;
		}
		else{
			cout<<"they leave without having lunch"<<endl;
		}
	}
	void leavingtable()
	{
		cout<<endl;
		cout<<"*******************************"<<endl;
		if(clean == true)
		{
			cout<<"they are leaving"<<endl;
		}
		else{
			cout<<"they are not leaving, they are still seated"<<endl;
		}
	}
	void cleaningtable()
	{
		cout<<endl;
		cout<<"************************"<<endl;
		if(currseatocupied == 0 && clean == false) 
		{
			cout<<"table is not clean. Staff is cleaning"<<endl;
		}
		else{
			cout<<"table is clean"<<endl;
		}
	}
	void emptytable(int table_number)
    {
        currseatocupied = 0; 
        freeseat += totalseats; 
        cout << "Table " << table_number << " is now empty." << endl;
    }
};

int main()
{
    dhaba tables[5] = {
        dhaba(8, 0, 8, false),
        dhaba(8, 0, 8, false),
        dhaba(4, 0, 4, false),
        dhaba(4, 0, 4, false),
        dhaba(4, 0, 4, false)
    };

    tables[0].occupytable(tables, 5, 4);

    tables[1].occupytable(tables, 5, 6);

    cout << "Table 1:" << endl;
    tables[0].havinglunch();
    tables[0].leavingtable();
    tables[0].cleaningtable();

    tables[1].emptytable(1);

}
