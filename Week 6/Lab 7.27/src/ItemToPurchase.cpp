#include <string>
#include <iostream>

#include "include/ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice , int itemQuantity)
{
    this->itemName = itemName;
    this->itemDescription = itemDescription;
    this->itemPrice = itemPrice;
    this->itemQuantity = itemQuantity;
}

string ItemToPurchase::GetName() const
{
    return itemName;
}
void ItemToPurchase::SetName(const string& itemName)
{
    this->itemName = itemName;
}

int ItemToPurchase::GetPrice() const
{
    return itemPrice;
}
void ItemToPurchase::SetPrice(const int itemPrice)
{
    this->itemPrice = itemPrice;
}

int ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}
void ItemToPurchase::SetQuantity(const int itemQuantity)
{
    this->itemQuantity = itemQuantity;
}

string ItemToPurchase::GetDescription() const
{
    return itemDescription;
}
void ItemToPurchase::SetDescription(const string& itemDescription)
{
    this->itemDescription = itemDescription;
}

void ItemToPurchase::PrintItemCost() const
{
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << (itemQuantity * itemPrice) << endl;
}
void ItemToPurchase::PrintItemDescription() const
{
    cout << itemName << ": " << itemDescription << endl;
}
