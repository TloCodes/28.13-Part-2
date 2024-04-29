//git respsitory link
Travis Pryor
Christy Marunza

#include <iostream>
#include <limits>
#include <vector>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void PrintMenu();
void ExecuteMenu(char option, ShoppingCart& theCart);
void PrintMenu() {


    cout << "MENU" << endl;
      cout   << "a - Add item to cart"  << endl;
       cout   << "d - Remove item from cart"  << endl;
        cout   << "c - Change item quantity"  << endl;
         cout   << "i - Output items' descriptions"  << endl;
          cout   << "o - Output shopping cart"  << endl;
            cout   << "q - Quit"  << endl;
         
 
}

int main() {
    string customerName;
    string currentDate;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);

    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);

    cout << "\nCustomer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;

    ShoppingCart theCart(customerName, currentDate);
   cout << endl;
    PrintMenu();
   cout << endl;
    char menuOption = ' ';
    do {
        cout << "Choose an option:" << endl;
        cin >> menuOption;
        if (cin.peek() == '\n') {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
       


        if (menuOption != 'q') {
            ExecuteMenu(menuOption, theCart);
            if (menuOption == 'o' || menuOption == 'i' || menuOption == 'a' || menuOption == 'd' || menuOption == 'c') {
                   cout << endl;
                PrintMenu();
                   cout << endl;
            }
        }
    } while (menuOption != 'q');

    return 0;
}


void ExecuteMenu(char option, ShoppingCart& theCart) {
    string name, description;
    int price, quantity;

    switch (option) {
        case 'a': {
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:\n";
            getline(cin, name);
            cout << "Enter the item description:\n";
            getline(cin, description);
            cout << "Enter the item price:\n";
            cin >> price;
            cout << "Enter the item quantity:\n";
            cin >> quantity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ItemToPurchase newItem(name, description, price, quantity);
            theCart.AddItem(newItem);
            break;
        }
        case 'd': {
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:\n";
            getline(cin, name);
            theCart.RemoveItem(name);
            break;
        }
        case 'c': {
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:\n";
            getline(cin, name);
            cout << "Enter the new quantity:\n";
            cin >> quantity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ItemToPurchase item;
            item.SetName(name);
            item.SetQuantity(quantity);
            theCart.ModifyItem(item);
            break;
        }
        case 'i': {
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            theCart.PrintDescriptions();
            break;
        }
        case 'o': {
            cout << "OUTPUT SHOPPING CART" << endl;
            theCart.PrintTotal();
            break;
        }
        case 'q':
            // No action needed, quitting is handled by the loop condition
            break;
        default:
           
            break;
    }
}




