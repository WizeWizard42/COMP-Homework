#include <iostream>
#include <string>

#include "include/ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(const string& customerName, const string& currentDate)
{
    this->customerName = customerName;
    this->currentDate = currentDate;
}

string ShoppingCart::GetCustomerName() const
{
    return customerName;
}
string ShoppingCart::GetDate() const
{
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item)
{
    cartItems.push_back(item);
}
void ShoppingCart::RemoveItem(const string& itemName)
{
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if (cartItems.at(i).GetName() == itemName)
        {
            cartItems.erase(cartItems.begin() + i);
            return;
        }
    }

    cout << "Item not found in cart. Nothing removed." << endl;
}
void ShoppingCart::ModifyItem(const ItemToPurchase& item)
{
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if (cartItems.at(i).GetName() == item.GetName())
        {
            if (item.GetDescription() != "none")
            {
                cartItems.at(i).SetDescription(item.GetDescription());
            }
            if (item.GetPrice() != 0)
            {
                cartItems.at(i).SetPrice(item.GetPrice());
            }
            if (item.GetQuantity() != 0)
            {
                cartItems.at(i).SetQuantity(item.GetQuantity());
            }
            return;
        }
    }

    cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() const
{
    int numItems = 0;
    for (size_t i = 0; i < cartItems.size(); i++)
    {
        numItems += cartItems.at(i).GetQuantity();
    }
    return numItems;
}
int ShoppingCart::GetCostOfCart() const
{
    int totalCost = 0;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        totalCost += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() const
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl;
    cout << endl;

    for (const ItemToPurchase& item : cartItems)
    {
        cout << item.GetName() << " "
        << item.GetQuantity() << " @ $"
        << item.GetPrice() << " = $"
        << (item.GetQuantity() * item.GetPrice()) << endl;
    }

    if (GetNumItemsInCart() < 1)
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    cout << endl;
    cout << "Total: $" << GetCostOfCart() << endl;
}
void ShoppingCart::PrintDescriptions() const
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;

    cout << "Item Descriptions" << endl;
    for (const ItemToPurchase& item : cartItems)
    {
        cout << item.GetName() << ": " << item.GetDescription() << endl;
    }
}
