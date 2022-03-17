#include <iostream>
#include <string>

#include "include/VendingMachine.h"

VendingMachine::VendingMachine() {
	bottles = 20;
}

void VendingMachine::Purchase(int amount) {
	bottles = bottles - amount;
}

int VendingMachine::GetInventory() {
	return bottles;
}


void VendingMachine::Restock(int amount) {
	bottles = bottles + amount;
}

void VendingMachine::Report() {
	std::cout << "Inventory: " << bottles << " bottles" << std::endl;
}