//23K-2079
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class BOGOCoupon
{
private:
    string coupon_code;
    time_t valid_from;
    time_t valid_until;
    string restaurant_code;

public:
    BOGOCoupon(string code, time_t from, time_t until, string rest_code)
        : coupon_code(code), valid_from(from), valid_until(until), restaurant_code(rest_code) {}

    bool is_valid(string selected_restaurant)
    {
        time_t now = time(nullptr);
        return (now >= valid_from && now <= valid_until && restaurant_code == selected_restaurant);
    }

    string get_coupon_code() const
    {
        return coupon_code;
    }
};

class Restaurant
{
private:
    string restaurant_name;
    string location;
    vector<string> menu_list;
    vector<double> price_list;
    vector<string> valid_coupon_codes_list;
    static int coupons_redeemed_count;

public:
    Restaurant(string name, string loc, vector<string> menu, vector<double> price, vector<string> coupons)
        : restaurant_name(name), location(loc), menu_list(menu), price_list(price), valid_coupon_codes_list(coupons) {}

    void display_menu()
    {
        cout << "Menu for " << restaurant_name << " at " << location << ":" << endl;
        for (int i = 0; i < menu_list.size(); ++i)
        {
            cout << i + 1 << ". " << menu_list[i] << " - $" << price_list[i] << endl;
        }
    }

    void generate_bill(vector<int> items_selected)
    {
        double total = 0.0;
        for (int item : items_selected)
        {
            total += price_list[item - 1]; // item index starts from 1
        }
        cout << "Total bill amount: $" << total << endl;
    }

    bool apply_discount(string coupon_code)
    {
        for (string valid_coupon : valid_coupon_codes_list)
        {
            if (valid_coupon == coupon_code)
            {
                coupons_redeemed_count++;
                return true;
            }
        }
        return false;
    }

    static int get_coupons_redeemed_count()
    {
        return coupons_redeemed_count;
    }
};

int Restaurant::coupons_redeemed_count = 0;

class User
{
private:
    string name;
    int age;
    string mobile_number;
    vector<BOGOCoupon> coupons_list;
    vector<string> redeemed_coupons_list;

public:
    User(string n, int a, string num) : name(n), age(a), mobile_number(num) {}

    void accumulate_coupon(BOGOCoupon coupon)
    {
        coupons_list.push_back(coupon);
    }

    bool has_valid_coupon(string selected_restaurant)
    {
        for (BOGOCoupon coupon : coupons_list)
        {
            if (coupon.is_valid(selected_restaurant))
            {
                return true;
            }
        }
        return false;
    }

    bool redeem_coupon(string coupon_code)
    {
        for (int i = 0; i < coupons_list.size(); ++i)
        {
            if (coupons_list[i].get_coupon_code() == coupon_code)
            {
                redeemed_coupons_list.push_back(coupon_code);
                coupons_list.erase(coupons_list.begin() + i);
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Restaurant food_haven("Food Haven", "City Center", {"Sushi", "Pad Thai", "Mango Tango"}, {10.99, 8.99, 6.99}, {"FH_BOGO_12345"});
    Restaurant pixel_bites("Pixel Bites", "Cyber Street", {"Binary Burger", "Quantum Quinoa", "Data Donuts"}, {9.99, 7.99, 5.99}, {"PB_BOGO_67890"});

    food_haven.display_menu();
    pixel_bites.display_menu();

    User user("John Doe", 30, "123-456-7890");

    string restaurant_choice;
    cout << "Enter restaurant choice (Food_Haven / Pixel_Bites): ";
    cin >> restaurant_choice;

    if (restaurant_choice == "Food_Haven")
    {
        string coupon_code;
        cout << "Enter coupon code: ";
        cin >> coupon_code;

        if (user.has_valid_coupon("FH"))
        {
            if (food_haven.apply_discount(coupon_code))
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
            cout << "No valid coupon available for Food Haven." << endl;
        }
    }
    else if (restaurant_choice == "Pixel_Bites")
    {
        string coupon_code;
        cout << "Enter coupon code: ";
        cin >> coupon_code;

        if (user.has_valid_coupon("PB"))
        {
            if (pixel_bites.apply_discount(coupon_code))
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
            cout << "No valid coupon available for Pixel Bites." << endl;
        }
    }
    else
    {
        cout << "Invalid restaurant choice." << endl;
    }

    cout << "Total coupons redeemed across all restaurants: " << Restaurant::get_coupons_redeemed_count() << endl;

    return 0;
}
