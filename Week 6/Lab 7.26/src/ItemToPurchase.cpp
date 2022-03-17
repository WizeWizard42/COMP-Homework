#include <string>

#include "include/ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

std::string ItemToPurchase::GetName() const
{
    return itemName;
}
void ItemToPurchase::SetName(std::string itemName)
{
    this->itemName = itemName;
}

int ItemToPurchase::GetPrice() const
{
    return itemPrice;
}
void ItemToPurchase::SetPrice(int itemPrice)
{
    this->itemPrice = itemPrice;
}

int ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}
void ItemToPurchase::SetQuantity(int itemQuantity)
{
    this->itemQuantity = itemQuantity;
}
