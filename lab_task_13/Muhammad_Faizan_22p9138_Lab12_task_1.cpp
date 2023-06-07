#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Item {
    string item_name;
    double price;

public:
    Item(string itm = "Null", double pri = 0) {
        setItem(itm);
        setPrice(pri);
    }

    /* Setter For The Item Class */
    void setItem(string s_itm) {
        if (!s_itm.empty()) {
            item_name = s_itm;
        }
        else {
            item_name = "Null";
        }
    }
    void setPrice(double s_pri) {
        if (s_pri >= 0) {
            price = s_pri;
        }
        else {
            price = 0;
        }
    }
    string getItem() const {
        return item_name;
    }
    double getPrice() const {
        return price;
    }
};

/* Cart That Contains the class as a member */
class ShoppingCart {
    vector<Item> item_list;

public:
    ShoppingCart() {}

    void addItem(const string& product_name, const double& price) {
        Item temp(product_name, price);
        item_list.push_back(temp);
        cout << product_name << "\t" << price << "\t" << "Was Added To The Cart" << endl;
    }

    void removeItem() 
    {
        for (int i = 0; i < item_list.size(); i++) 
        {
            cout << i + 1 << "\t" << item_list[i].getItem() << "\t" << item_list[i].getPrice() << endl;
        }
        int remove;
        cout << "Please Select Product To Remove From The Cart: ";
        cin >> remove;
        if (remove >= 1 && remove <= item_list.size()) 
        {
            item_list.erase(item_list.begin() + remove - 1);
            cout << "The Product Was Successfully Removed From The Cart" << endl;
        }
        else 
        {
            cout << "Invalid Option Is Selected" << endl;
        }
    }

    void clearcart()
    {
        char confirm;
        cout<<"Do You Really Want TO Clear The Cart ?";
        cin>>confirm;

        if (confirm == 'Y' || confirm == 'y')
        {
            item_list.clear();
            item_list.shrink_to_fit();
        }
        else if (confirm == 'n' || confirm == 'N')
        {
            cout<<"Thanks For Not Making Me Empty Dear... \t Regards Card"<<endl;
        }
        else if (confirm != 'Y' || confirm != 'y' || confirm != 'N' || confirm != 'n')
        {
            cout<<"Invalid Option Selected"<<endl;
        }   
    }

    void exchangetheproduct()
    {
        cout<<"Please select the product to exchange from the cart: "<<endl;
        displayItems();
        int exchangeOption;
        cout<<"Enter the number of the product to exchange:";
        cin>>exchangeOption;

        if (exchangeOption >= 1 && exchangeOption <= item_list.size()) 
        {
            string currentProductName = item_list[exchangeOption - 1].getItem();
            double currentProductPrice = item_list[exchangeOption - 1].getPrice();

        cout<<"Enter the details of the new product:" << endl;
        string newProductName;
        double newProductPrice;

        cout<<"Name: ";
        cin>>newProductName;
        cout << "Price: ";
        cin >> newProductPrice;

        
        Item newItem(newProductName, newProductPrice);

        // Replace the existing item with the new item in the cart
        item_list[exchangeOption - 1] = newItem;
        cout<<"Product '"<<currentProductName<<"' with price "<<currentProductPrice<< " has been exchanged with product '" << newProductName << "' with price " << newProductPrice << endl;
    }
    else 
    {
        cout<<"Invalid product option selected." << endl;
    }
}


    void displayItems() const 
    {
        if (item_list.size() <= 0)
        {
            cout<<"The Cart Is Empty"<<endl;
        }
        else if(item_list.size() >= 1)
        {
            for (int i = 0; i < item_list.size(); i++) 
            {
                cout << i + 1 << "\t" << item_list[i].getItem() << "\t" << item_list[i].getPrice() << endl;
            }
        }
        else
        {
            cout<<"Please Pickup The Cart In Your Hand \t Full it with iteams"<<endl;
        }
    }
};

int main() 
{
    int option;
    Item* item_list[8] = {new Item("Shirt", 100.4), new Item("Pant", 200.00), new Item("Shoes", 1000),new Item("Cap", 50), new Item("Iphone", 250000), new Item("Samsung", 89000),new Item("Laptop", 40000), new Item("Macbook", 599999)};
    ShoppingCart buyer;

    while (option != 6) 
    {
        cout << "\nMenu:\n\t1. Add items \n\t2. Remove items\n\t3. Clear cart\n\t4. Exchange product\n\t5. View cart\n\t6. Exit" << endl;
        cin >> option;

        if (option == 1) 
        {
            for (int i = 0; i < 8; i++) 
            {
                cout << i + 1 << "  Name : " << item_list[i]->getItem() << "\tPrice : " << item_list[i]->getPrice() << endl;
            }
            int pro_option;
            cout << "Please Select Product: ";
            cin >> pro_option;
            if (pro_option >= 1 && pro_option <= 8) 
            {
                buyer.addItem(item_list[pro_option - 1]->getItem(), item_list[pro_option - 1]->getPrice());
            }
            else 
            {
                cout << "Invalid Product Number has Been Entered" << endl;
            }
        }
        else if (option == 2) 
        {
            buyer.removeItem();
        }
        else if (option == 3) 
        {
            buyer.clearcart();   
        }
        else if (option == 4) 
        {
            buyer.exchangetheproduct();
        }
        else if (option == 5) 
        {
            buyer.displayItems();
        }
        else 
        {
            cout<<"Thanks For Using Visting Our Shop"<<endl;
            break;
        }
    }
    return 0;
}
