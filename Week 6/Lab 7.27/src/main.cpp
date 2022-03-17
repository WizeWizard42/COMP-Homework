#include <iostream>
#include <iomanip>

#include "include/ShoppingCart.h"

using namespace std;

void PrintMenu();

void ExecuteMenu(char option, ShoppingCart& theCart);

int main(void)
{
   string customerName;
   string currentDate;
   char userChoice;

   cout << "Enter customer's name:" << endl;
   getline(cin, customerName);

   cout << "Enter today's date:" << endl;
   getline(cin, currentDate);
   cout << endl;

   cout << "Customer name: " << customerName << endl;
   cout << "Today's date: " << currentDate << endl;
   cout << endl;

   ShoppingCart cart(customerName, currentDate);

   PrintMenu();
   while (true)
   {
      cout << "Choose an option:" << flush;
      cin >> userChoice;

      if (userChoice == 'q')
      {
         break;
      }

      cout << endl;

      switch (userChoice)
      {
         case 'a':
         case 'd':
         case 'c':
         case 'i':
         case 'o':
            ExecuteMenu(userChoice, cart);
            PrintMenu();
            break;
      }
   }
   cout << endl;

   return 0;
}

void PrintMenu()
{
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart)
{
   cin.ignore();

   if (option == 'a')
   {
      string itemName;
      string itemDescription;
      int itemPrice;
      int itemQuantity;

      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, itemName);

      cout << "Enter the item description:" << endl;
      getline(cin, itemDescription);

      cout << "Enter the item price:" << endl;
      cin >> itemPrice;

      cout << "Enter the item quantity:" << endl;
      cin >> itemQuantity;

      ItemToPurchase item(itemName, itemDescription, itemPrice, itemQuantity);
      theCart.AddItem(item);

      cout << endl;
   }

   if (option == 'd')
   {
      string itemName;

      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      getline(cin, itemName);

      theCart.RemoveItem(itemName);

      cout << endl;
   }

   if (option == 'c')
   {
      string itemName;
      int itemQuantity;

      cout << "CHANGE ITEM QUANTITY" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, itemName);

      cout << "Enter the new quantity:" << endl;
      cin >> itemQuantity;

      ItemToPurchase item;
      item.SetName(itemName);
      item.SetQuantity(itemQuantity);

      theCart.ModifyItem(item);

      cout << endl;
   }

   if (option == 'i')
   {
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      theCart.PrintDescriptions();
      cout << endl;
   }

   if (option == 'o')
   {
      cout << "OUTPUT SHOPPING CART" << endl;
      theCart.PrintTotal();
      cout << endl;
   }
   
}
