#include "ShoppingCart.h"
#include <iostream>
#include <algorithm> // Needed for find_if

ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}

ShoppingCart::ShoppingCart(string name, string date)
    : customerName(move(name)), currentDate(move(date)) {}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(move(item));
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::RemoveItem(string itemName) {
    auto it = find_if(cartItems.begin(), cartItems.end(),
                      [&itemName](const ItemToPurchase& item) {
                          return item.GetName() == itemName;
                      });

    if (it != cartItems.end()) {
        cartItems.erase(it);
    } else {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    auto it = find_if(cartItems.begin(), cartItems.end(),
                      [&item](const ItemToPurchase& cartItem) {
                          return cartItem.GetName() == item.GetName();
                      });
if (it != cartItems.end()) {
        if (!item.GetDescription().empty()) it->SetDescription(item.GetDescription());
        if (item.GetPrice() != 0) it->SetPrice(item.GetPrice());
        if (item.GetQuantity() != 0) it->SetQuantity(item.GetQuantity());
    } else {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() const {
    int numItems = 0;
    for (const auto& item : cartItems) {
        numItems += item.GetQuantity();
    }
    return numItems;
}

double ShoppingCart::GetCostOfCart() const {
    double totalCost = 0;
    for (const auto& item : cartItems) {
        totalCost += item.GetPrice() * item.GetQuantity();
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
   
    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
        cout << "Total: $0" << endl;
       
    } else {
        for (const ItemToPurchase& item : cartItems) {
            item.PrintItemCost();
        }
        cout << endl;
        cout << "Total: $" << GetCostOfCart() << endl;
    }
}

void ShoppingCart::PrintDescriptions() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (const ItemToPurchase& item : cartItems) {
        item.PrintItemDescription();
    }
}
