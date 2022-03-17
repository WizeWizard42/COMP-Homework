#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>

#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart
{
    public:
        ShoppingCart();
        ShoppingCart(const string& customerName, const string& currentDate);

        // Getters for customerName and currentDate.
        string GetCustomerName() const;
        string GetDate() const;

        // Adds ItemToPurchase object to list.
        void AddItem(const ItemToPurchase& item);
        // Removes ItemToPurchase object from list.
        void RemoveItem(const string& itemName);
        // Modifies ItemToPurchase object in list by name.
        void ModifyItem(const ItemToPurchase& item);

        // Returns number of items in cart.
        int GetNumItemsInCart() const;
        // Returns total cost of items in cart.
        int GetCostOfCart() const;

        // Prints summary and total of items in cart.
        void PrintTotal() const;
        // Prints summary and descriptions of items in cart.
        void PrintDescriptions() const;

    private:
        string customerName;
        string currentDate;

        vector<ItemToPurchase> cartItems;
};

#endif // SHOPPING_CART_H