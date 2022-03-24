/*
 * Given the MileageTrackerNode class, complete main() to insert nodes into a linked list (using the InsertAfter() function).
 * The first user-input value is the number of nodes in the linked list. Use the PrintNodeData() function to print the entire linked list.
 * DO NOT print the dummy head node.
 */
#include <string>
#include <iostream>

#include "include/MileageTrackerNode.h"
using namespace std;

int main () {
    int numNodes;

    // References for MileageTrackerNode objects
    MileageTrackerNode* headNode;
    MileageTrackerNode* currNode;
    MileageTrackerNode* lastNode;

    double miles;
    string date;
    int i;

    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;

    cin >> numNodes;

    for (i = 0; i < numNodes; i++)
    {
        cin >> miles;
        cin >> date;

        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);

        lastNode = currNode;

        lastNode->PrintNodeData();
    }

    // MileageTrackerNode Destructor deletes all
    //       following nodes
    delete headNode;
}