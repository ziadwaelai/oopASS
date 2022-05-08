/*
Name: Ziad Wael Abdl Hamed Abdl Rashed   ID:20200211
Name: Suhayla Ehab Gamal Malatie         ID:20200236
*/

#include <iostream>
using namespace std;

class Item
{
private:
    string name;
    int quantity, ID;
    double price;

public:
    static int id;

    // default Constructor
    Item()
    {
        setID(id);
        id++;
    };

    // parameterized Constructor
    Item(string n, int q, double p)
    {
        setName(n);
        setQuantity(q);
        setPrice(p);
        setID(id);
        ++id;
    };

    // copy Constructor
    Item(const Item& obj)
    {
        name = obj.name;
        quantity = obj.quantity;
        price = obj.price;
        ID = obj.ID;
    };

    // == operator
    bool operator==(const Item& obj)
    {
        bool state;
        if (name == obj.name)
        {
            state = true;
        }
        else
        {
            state = false;
        }
        return state;
    }
    // operator ++
    Item operator+=(const Item& obj)
    {
        quantity += obj.quantity;
        return *this;
    }
    // operator --
    Item operator-=(const Item& obj)
    {
        quantity -= obj.quantity;
        return *this;
    }
    // getters & setters
    int getID() const
    {
        return ID;
    }
    int getQuantity() const
    {
        return quantity;
    }
    double getPrice() const
    {
        return price;
    }
    string getName() const
    {
        return name;
    }
    void setName(string n)
    {
        name = n;
    }
    void setQuantity(int q)
    {
        quantity = q;
    }
    void setPrice(double p)
    {
        price = p;
    }
    void setID(int id)
    {
        ID = id;
    }

    // insertion , extraction operator to get items' info
    friend ostream& operator<<(ostream& os, const Item& fi);
    friend istream& operator>>(istream& is, Item& fi);
};

int Item::id = 0;

ostream& operator<<(ostream& os, const Item& fi)
{
    os << endl
        << "Name: " << fi.getName();
    os << endl
        << "quantity: " << fi.getQuantity();
    os << endl
        << "price: " << fi.getPrice();
    return os;
};
istream& operator>>(istream& is, Item& fi)
{
    cout << endl
        << "Enter Name Quantity Price :";
    is >> fi.name >> fi.quantity >> fi.price;
    fi.setID(fi.id);
    return is;
};

class Seller
{
private:
    string name, email;
    int maxitems;
    Item* items;

    bool check(const Item& obj)
    {
        for (int i = 0; i < maxitems; i++)
        {
            if (items[i] == obj)
            {
                return true;
            }
        }
        return false;
    }

public:
    static int c;

    //parameterized Constructor
    Seller(string n, string e, int max)
    {
        name = n;
        email = e;
        maxitems = max;
        items = new Item[maxitems];
        for (int i = 0; i < maxitems; i++)
        {
            items[i].setName("");
            items[i].setPrice(0);
            items[i].setQuantity(0);
            items[i].setID(0);
        }
    };

    // function that's add items
    bool addItems(Item obj)
    {
        if (c == maxitems && !check(obj))
        {
            cout << "The Store Capactiy is full";
            return false;
        }
        else
        {
            if (check(obj))
            {
                for (int i = 0; i < maxitems; i++)
                {
                    if (items[i] == obj)
                    {
                        items[i] += obj;
                    }
                }
            }
            else
            {
                items[c] = obj;
                c++;
            }
            cout << "Item Added Successfully ";
            return true;
        }
    }

    //function that's sell items
    bool sellItems(string name, int qun)
    {

        for (int i = 0; i < maxitems; i++)
        {
            if (items[i].getName() == name && items[i].getQuantity() >= qun)
            {
                items[i].setQuantity(items[i].getQuantity() - qun);
                cout << "Item Sold Successfully ";
                return true;
            }
        }
        for (int i = 0; i < maxitems; i++)
        {
            if (items[i].getName() == name)
            {
                cout << "There is only " << items[i].getQuantity() << " left for this item";
                return false;
            }
        }
        return false;
    }

    //function that's  find item by its id
    Item findByID(int Id)
    {

        for (int i = 0; i < maxitems; i++)
        {
            if (items[i].getID() == Id + maxitems)
            {
                return items[i];
            }

        }
        cout << "Not Found :)";
    }

    // function that's  print items
    void printItems()
    {
        for (int i = 0; i < c; i++)
        {
            cout << "ID:" << items[i].getID() - maxitems << items[i] << endl;
        }
        if (c == 0)
        {
            cout << "The Store is Empty :) ";
        }
    }

    // destructor
    ~Seller()
    {
        delete[] items;
    };

    //  insertion , extraction operator to get seller's info
    friend ostream& operator<<(ostream& os, const Seller& fi);
};
ostream& operator<<(ostream& os, const Seller& fi)
{
    os << "Name: " << fi.name << endl
        << "Email " << fi.email;
    return os;
};
int Seller::c = 0;
int main()
{

    string name, emil, c;
    int n;
    cout << "Enter your Name and your Email:" << endl;
    cin >> name >> emil;
    cout << "Enter Ehe Store Capactiy :";
    cin >> n;
    Seller s(name, emil, n);
    system("CLS");

    // Menu
    while (1)
    {
        int n;
        cout << "      Menu" << endl;
        cout << "1. Print My Info" << endl;
        cout << "2. Add An Item" << endl;
        cout << "3. Sell An Item" << endl;
        cout << "4. Print Items." << endl;
        cout << "5. Find an Item by ID." << endl;
        cout << "6. Exit." << endl;
        cin >> n;
        if (n == 1)
        {
            system("CLS");//to clear console

            cout << s << endl;
        }
        else if (n == 2)
        {
            system("CLS");

            Item i;
            cin >> i;
            s.addItems(i);
        }
        else if (n == 3)
        {
            system("CLS");

            string name;
            int q;
            cout << "Enter The Name of item and Quantity:";
            cin >> name >> q;
            s.sellItems(name, q);
        }
        else if (n == 4)
        {
            system("CLS");
            s.printItems();
        }
        else if (n == 5)
        {
            system("CLS");

            int iid;
            cout << "Enter The ID of item:";
            cin >> iid;
            cout << s.findByID(iid);
        }
        else
        {
            return 0;
        }
        cout << endl
            << "Back to Menu Press [Y] or [E] to Exit: ";
        cin >> c;
        if (c == "y" || c == "Y")
        {
            system("CLS");
        }
        else if (c == "E" || c == "e")
        {
            return 0;
        }
    }

    return 0;
}
