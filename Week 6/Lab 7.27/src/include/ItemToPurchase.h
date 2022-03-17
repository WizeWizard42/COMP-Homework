#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>

using namespace std;

class ItemToPurchase
{
    public:
        ItemToPurchase();
        ItemToPurchase(string itemName, string itemDescription, int itemPrice = 0, int itemQuantity = 0);

        // Getter for item name.
        string GetName() const;
        // Setter for item name.
        void SetName(const string& itemName);

        // Getter for item price.
        int GetPrice() const;
        // Setter for item price.
        void SetPrice(const int itemPrice);

        // Gettter for item quantity.
        int GetQuantity() const;
        // Setter for item quantity.
        void SetQuantity(const int itemQuantity);

        // Getter for item description.
        string GetDescription() const;
        // Setter for item description.
        void SetDescription(const string& itemDescription);

        // Prints breakdown of item cost.
        void PrintItemCost() const;
        // Prints item description.
        void PrintItemDescription() const;
        
    private:
        string itemName;
        string itemDescription;

        int itemPrice;
        int itemQuantity;
};

#endif // ITEM_TO_PURCHASE_H
