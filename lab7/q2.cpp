#include <iostream>
#include <vector>
using namespace std;

class product {
protected:
    int p_id;
    string name;
    float price;
    int quantity;
    string category;
    string supplier;

public:
    product() {}
    product(int id, string n, float p, int q, string c, string s) :
        p_id(id), name(n), price(p), quantity(q), category(c), supplier(s) {}

    void add_stock(int quantity) {
        this->quantity += quantity;
        cout << "Added " << quantity << " units to " << name << endl;
    }

    void update() {
        cout << "Updated quantity is: " << quantity << endl;
    }

    void display() const {
        cout << "Product Details:\n" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << p_id << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Category: " << category << endl;
        cout << "Supplier: " << supplier << endl;
    }

    // Getter for category
    string getCategory() const {
        return category;
    }

    // Getter for supplier
    string getSupplier() const {
        return supplier;
    }
};

class category : virtual protected product {
protected:
    int c_id;
    string c_name;
    vector<product> item;

public:
    category() {}
    category(int id, string n = "") :
        c_id(id), c_name(n) {}

    void add_product(const product& p1) {
        item.push_back(p1);
    }

    void get_product() const {
        for (const auto& it : item) {
            it.display();
            cout << "Category name: " << c_name << endl;
            cout << "Category id: " << c_id << endl;
        }
    }
};

class supplier : public category {
    int s_id;
    string s_name;
    vector<product> sup;

public:
    supplier() {}
    supplier(int id, string n, float p, int q, string c, string s, int si, string sn) :
        category(id, n), s_id(si), s_name(sn) {}

    void add_pro(const product& s1) {
        sup.push_back(s1);
    }

    void get_product_of_supplier() const {
        for (const auto& it : sup) {
            it.display();
            cout << "Supplier name: " << s_name << endl;
            cout << "Supplier id: " << s_id << endl;
        }
    }

    // Override the display function to include supplier details
    void display() const {
        category::display();
        cout << "Supplier name: " << s_name << endl;
        cout << "Supplier id: " << s_id << endl;
    }

    // Override the getSupplier function to access the supplier name
    string getSupplier() const {
        return s_name;
    }

    // Implement update function
    void update() {
        cout << "Updated quantity is: " << quantity << endl;
    }
};

int main() {
    product p1(1, "14 Pro Max", 200000, 10, "mobile", "Apple");
    product p2(2, "lip Liners", 1200, 3, "make up", "Huda Beauty");

    p1.add_stock(5);
    p1.update();

    category c1(3, "make up");
    c1.add_product(p2);

    supplier s1(5, "Apple", 0, 0, "", "", 0, "Apple");
    s1.add_pro(p1);

    p1.display();
    c1.get_product();
    s1.get_product_of_supplier();

    return 0;
}
