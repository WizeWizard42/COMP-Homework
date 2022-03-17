#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>

class ItemToPurchase
{
    public:
        ItemToPurchase();

        std::string GetName() const;
        void SetName(std::string itemName);

        int GetPrice() const;
        void SetPrice(int itemPrice);

        int GetQuantity() const;
        void SetQuantity(int itemQuantity);
    private:
        std::string itemName;
        int itemPrice;
        int itemQuantity;
};

#endif // ITEM_TO_PURCHASE_H
