#include <iostream>
#include <vector>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

// 1. ShoppingCart: --> only responsible for cart related things
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    const vector<Product*> &getProducts()
    {
        return products;
    }

    double calculateTotal()
    {
        double total = 0;

        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};
// 2. ShoppingCartPrinter: --> Only responsible for printing invoices
class ShoppingCartPrinter
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    // vector<Product*> products = cart->getProducts();

    void printInvoice()
    {
        cout << "shopping cart invoice: \n";

        for (auto prod : cart->getProducts())
        {
            cout << prod->name << "- Rs. " << prod->price << endl;
        }

        cout << "total " << cart->calculateTotal() << endl;
    }
};

int main()
{

    Product *laptop = new Product("laptop", 50000);
    Product *iphone = new Product("iphone", 60000);
    Product *pixel = new Product("pixel", 40000);

    ShoppingCart *cart1 = new ShoppingCart;

    cart1->addProduct(laptop);
    cart1->addProduct(pixel);

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart1);
    printer->printInvoice();

    return 0;
}