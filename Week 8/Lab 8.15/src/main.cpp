/*
 * Given main(), define an InsertAtFront() member function in the InventoryNode class that inserts items at the front of a linked list (after the dummy head node).
 */
#include "include/InventoryNode.h"

int main() {
	int count;
	int numItems;
	string item;

	InventoryNode *headNode = new InventoryNode();
	InventoryNode *currNode;

	// Obtain number of items
	cin >> count;

	// Get each item and number of each
	for (int i = 0; i < count; i++) {
		cin >> item;
		cin >> numItems;
		currNode = new InventoryNode(item, numItems);
		currNode->InsertAtFront(headNode, currNode);
	}

	// Print linked list
	currNode = headNode->GetNext();
	while (currNode != NULL) {
		currNode->PrintNodeData();
		currNode = currNode->GetNext();
	}

	return 0;
}