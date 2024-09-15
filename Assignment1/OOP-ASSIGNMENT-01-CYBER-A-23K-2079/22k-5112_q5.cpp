//23K-2079
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class BogoCoupon
{
private:
    string Ccode;
    time_t Vfrom;
    time_t Vuntil;
    string RestaurantC;

public:
    BogoCoupon(string code, time_t from, time_t until, string rest_code)
        : Ccode(code), Vfrom(from), Vuntil(until), RestaurantC(rest_code) {}

    bool is_valid(string selected_restaurant)
    {
        time_t now = time(nullptr);
        return (now >= Vfrom && now <= Vuntil && RestaurantC == selected_restaurant);
    }

    string get_Ccode() const
    {
        return Ccode;
    }
};

class Restaurant
{
private:
    string restaurant_name;
    string lation;
    vector<string> menu;
    vector<double> prices;
    vector<string> Codeslist;
    static int CouponsR;

public:
    Restaurant(string name, string l, vector<string> menu, vector<double> price, vector<string> coupons)
        : restaurant_name(name), lation(l), menu(menu), prices(price), Codeslist(coupons) {}

    void display_menu()
    {
        cout << "Menu for " << restaurant_name << " at " << lation << ":" << endl;
        for (int i = 0; i < menu.size(); ++i)
        {
            cout << i + 1 << ". " << menu[i] << " - $" << prices[i] << endl;
        }
    }

    void Bill(vector<int> items_selected)
    {
        double total = 0.0;
        for (int item : items_selected)
        {
            total += prices[item - 1]; // item index starts from 1
        }
        cout << "Total bill amount: $" << total << endl;
    }

    bool Discounts(string Ccode)
    {
        for (string ValidC : Codeslist)
        {
            if (ValidC == Ccode)
            {
                CouponsR++;
                return true;
            }
        }
        return false;
    }

    static int get_CouponsR()
    {
        return CouponsR;
    }
};

int Restaurant::CouponsR = 0;

class User
{
private:
    string name;
    int age;
    string mobile_number;
    vector<BogoCoupon> coupons_list;
    vector<string> redeemed_coupons_list;

public:
    User(string n, int a, string num) : name(n), age(a), mobile_number(num) {}

    void accumulate_coupon(BogoCoupon coupon)
    {
        coupons_list.push_back(coupon);
    }

    bool has_ValidC(string selected_restaurant)
    {
        for (BogoCoupon coupon : coupons_list)
        {
            if (coupon.is_valid(selected_restaurant))
            {
                return true;
            }
        }
        return false;
    }

    bool redeem_coupon(string Ccode)
    {
        for (int i = 0; i < coupons_list.size(); ++i)
        {
            if (coupons_list[i].get_Ccode() == Ccode)
            {
                redeemed_coupons_list.push_back(Ccode);
                coupons_list.erase(coupons_list.begin() + i);
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Restaurant Zeytin("Zeytin", "City Center", {"Sushi", "Pad Thai", "Mango Tango"}, {10.99, 8.99, 6.99}, {"FH_BOGO_12345"});
    Restaurant MeetTheCheese("MeetTheCheese", "Cyber Street", {"Binary Burger", "Quantum Quinoa", "Data Donuts"}, {9.99, 7.99, 5.99}, {"PB_BOGO_67890"});

    Zeytin.display_menu();
    MeetTheCheese.display_menu();

    User user("John Doe", 30, "123-456-7890");

    string restaurant_choice;
    cout << "Enter restaurant choice (Zeytin / MeetTheCheese): ";
    cin >> restaurant_choice;

    if (restaurant_choice == "Zeytin")
    {
        string Ccode;
        cout << "Enter coupon code: ";
        cin >> Ccode;

        if (user.has_ValidC("FH"))
        {
            if (Zeytin.Discounts(Ccode))
            {
                cout << "Coupon applied successfully!" << endl;
            }
            else
            {
                cout << "Invalid coupon code." << endl;
            }
        }
        else
        {
            cout << "No valid coupon available for Zeytin." << endl;
        }
    }
    else if (restaurant_choice == "MeetTheCheese")
    {
        string Ccode;
        cout << "Enter coupon code: ";
        cin >> Ccode;

        if (user.has_ValidC("PB"))
        {
            if (MeetTheCheese.Discounts(Ccode))
            {
                cout << "Coupon applied successfully!" << endl;
            }
            else
            {
                cout << "Invalid coupon code." << endl;
            }
        }
        else
        {
            cout << "No valid coupon available for Meet the Cheese." << endl;
        }
    }
    else
    {
        cout << "Invalid restaurant choice." << endl;
    }

    cout << "Total coupons redeemed across all restaurants: " << Restaurant::get_CouponsR() << endl;

    return 0;
}
