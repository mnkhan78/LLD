#include <iostream>
#include <vector>
using namespace std;

// srp --> single responsibility principle...

class Product {
    public:
        string name;
        double price;

    Product (string name, double price) {
        this -> name = name;
        this -> price = price;
    }
};

class ShoppingCart {
    private:
        vector<Product*> products;

    public:
        void addProduct (Product *p){
            products.push_back(p);
        }

        const vector<Product*> & getProducts(){
            return products;
        }

        //1. calculate total price in cart:
        double calculateTotal(){
            double total = 0;

            for (auto product : products){
                total += product -> price;
            }
            return total;
        }
        //2. Print Invoice: ----violating srp
        void printInvoice (){
            cout << "Shopping Cart Invoice: \n";

            for (auto product: products){
                cout << product -> name << "- Rs. " << product -> price << endl;
            }

            cout << "Total: Rs " << calculateTotal() << endl;
        }
        
        //3. Saves to DB --- violating SRP
        void saveToDatabase () {
            cout << "saving shopping cart to database..." << endl;
        }
};

int main() {
    ShoppingCart *cart = new ShoppingCart();

    cart -> addProduct(new Product("Laptop", 500000));
    cart -> addProduct(new Product("Mouse", 200));

    cart -> printInvoice();
    cart -> saveToDatabase();

    return 0;
}