#ifndef VENDINGMACHINE_H_
#define VENDINGMACHINE_H_

class VendingMachine {

    public:
		VendingMachine();
		void Purchase(int amount);
		int GetInventory();
		void Restock(int amount);
		void Report();

    private:
        int bottles;
};

#endif /* VENDINGMACHINE_H_ */