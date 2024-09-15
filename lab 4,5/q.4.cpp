#include<iostream>
#include <string>
using namespace std;
class MenuItems {
  private:
    string Itemname; 
    int Itemprice; 
    bool available; 

  public:
    static const int Total = 10; 
    static int capacity; 
 
  public:
   
    MenuItems() {
     
      Itemname = "";
      Itemprice = 0;
      available = false;
    }

    MenuItems(string itname, int itprice, bool itavail) {
      Itemname = itname;
      Itemprice = itprice;
      available = itavail;
      capacity--;
    }

    static int getCapacity() {

      return capacity;
    }

    static void setCapacity(int capc) {

      capacity = capc;
    }
};
int MenuItems::capacity = MenuItems::Total;

int main() {
  MenuItems* menu = new MenuItems[MenuItems::Total];
  menu[0] = MenuItems("Burger", 100, true);
  menu[1] = MenuItems("Fries", 50, true);
  menu[2] = MenuItems("Pizza", 200, false);
  menu[3] = MenuItems("Salad", 80, true);
  menu[4] = MenuItems("Cake", 120, false);

  cout << "Capacity after creating 5 objects= " << MenuItems::getCapacity() << endl;
  delete[] menu;

  return 0;
}
