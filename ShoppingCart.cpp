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
