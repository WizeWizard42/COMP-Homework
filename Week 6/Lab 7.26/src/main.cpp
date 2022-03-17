#include <iostream>

#include "include/ItemToPurchase.h"

void PromptItem(ItemToPurchase& item);

int AddPrice(const ItemToPurchase& item1, const ItemToPurchase& item2);

int main(void)
{
    ItemToPurchase item1;
    ItemToPurchase item2;

    std::cout << "Item 1" << std::endl;
    PromptItem(item1);

    std::cout << "Item 2" << std::endl;
    PromptItem(item2);

    int item1TotalPrice = item1.GetPrice() * item1.GetQuantity();
    int item2TotalPrice = item2.GetPrice() * item2.GetQuantity();
    int totalPrice = item1TotalPrice + item2TotalPrice;

    std::cout << "TOTAL COST" << std::endl;
    std::cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1TotalPrice << std::endl;
    std::cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2TotalPrice << std::endl;
    std::cout << std::endl;
    std::cout << "Total: $" << totalPrice << std::endl;

    return 0;
}

void PromptItem(ItemToPurchase& item)
{
    std::string itemName;
    int itemPrice;
    int itemQuantity;

    std::cout << "Enter the item name:" << std::endl;
    std::getline(std::cin, itemName);

    std::cout << "Enter the item price:" << std::endl;
    std::cin >> itemPrice;

    std::cout << "Enter the item quantity:" << std::endl;
    std::cin >> itemQuantity;
    std::cin.ignore();

    std::cout << std::endl;

    item.SetName(itemName);
    item.SetPrice(itemPrice);
    item.SetQuantity(itemQuantity);
}
