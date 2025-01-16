#include <iostream>
#include <string>
using namespace std;

class BakeryProduct
{
  protected:
    string productName;
    int basePrice;

  public:
    BakeryProduct(string name, int price)
    {
        productName = name;
        basePrice = price;
    }

    void display()
    {
        cout << "Product: " << productName << ", Base Price: " << basePrice << endl;
    }

    int getBasePrice()
    {
        return basePrice;
    }

    string getProductName()
    {
        return productName;
    }

    ~BakeryProduct()
    {
    }
};

class Cake : public BakeryProduct
{
  public:
    Cake()
    {
        productName = "Cake";
        basePrice = 500;
    }
};

class Cookie : public BakeryProduct
{
  public:
    Cookie()
    {
        productName = "Cookie";
        basePrice = 100;
    }
};

class Bread : public BakeryProduct
{
  public:
    Bread()
    {
        productName = "Bread";
        basePrice = 50;
    }
};

class BakeryProductFactory
{
  public:
    static BakeryProduct *createProduct(int choice)
    {
        switch (choice)
        {
        case 1:
            return new Cake();
        case 2:
            return new Cookie();
        case 3:
            return new Bread();
        default:
            return nullptr;
        }
    }
};

class Flavor
{
  protected:
    string flavorName;
    int flavorPrice;

  public:
    Flavor(string name, int price)
    {
        flavorName = name;
        flavorPrice = price;
    }

    int getPrice()
    {
        return flavorPrice;
    }

    string getFlavorName()
    {
        return flavorName;
    }
};

class FlavorFactory
{
  public:
    static Flavor *createFlavor(int productChoice, int flavorChoice)
    {
        if (productChoice == 1)
        {
            if (flavorChoice == 1)
                return new Flavor("Chocolate", 50);
            if (flavorChoice == 2)
                return new Flavor("Strawberry", 40);
        }
        else if (productChoice == 2)
        {
            if (flavorChoice == 1)
                return new Flavor("Chocolate Chip", 30);
            if (flavorChoice == 2)
                return new Flavor("Peanut Butter", 35);
        }
        else if (productChoice == 3)
        {
        }
        if (flavorChoice == 1)
            return new Flavor("Garlic", 20);
        if (flavorChoice == 2)
            return new Flavor("Herb", 15);
};

int main()
{
    int productChoice, flavorChoice;
    char continueChoice;

    do
    {
        BakeryProduct *product = nullptr;
        Flavor *flavor = nullptr;

        cout << "1. Cake\n2. Cookie\n3. Bread\nEnter your product choice: ";
        cin >> productChoice;

        product = BakeryProductFactory::createProduct(productChoice);
        if (product)
        {
            if (productChoice == 1)
            {
                cout << "Select flavor for Cake:\n1. Chocolate\n2. Strawberry\nEnter your choice: ";
            }
            else if (productChoice == 2)
            {
                cout << "Select flavor for Cookie:\n1. Chocolate Chip\n2. Peanut Butter\nEnter your choice: ";
            }
            else if (productChoice == 3)
            {
                cout << "Select flavor for Bread:\n1. Garlic\n2. Herb\nEnter your choice: ";
            }

            cin >> flavorChoice;

            flavor = FlavorFactory::createFlavor(productChoice, flavorChoice);
            int totalPrice = product->getBasePrice();
            string flavorName = "None";

            if (flavor)
            {
                totalPrice += flavor->getPrice();
                flavorName = flavor->getFlavorName();
            }

            product->display();
            cout << "Flavor: " << flavorName << ", Price: " << (flavor ? flavor->getPrice() : 0) << endl;
            cout << "Total Price: Rs. " << totalPrice << endl;

            delete product;
            delete flavor;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y');

    cout << "Thank you for visiting the bakery!" << endl;
    return 0;
}