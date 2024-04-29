#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using std::string;  

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    void SetName(string name);
    void SetDescription(string description);
    void SetPrice(int price);
    void SetQuantity(int quantity);

    string GetName() const;
    string GetDescription() const;
    int GetPrice() const;
    int GetQuantity() const;

