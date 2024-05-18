#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include "Course.h"
#define nullptr NULL
using namespace std;

template <class T>
class NumberList : public Course // Declare a class for the linked list
{
	private:
		struct ListNode
		{
			T value;
			ListNode *next; 
		};
		ListNode *head; // List head pointer
		
	public:
		// Constructor
		NumberList()
			{ head = nullptr; }
		
		// Linked list operations
		void appendNode(T data);	
		void deleteNode(T data);
		void display();
};

template <class T>
void NumberList<T>::appendNode(T data)
{
		ListNode *newNode; // To point to a new node
		ListNode *nodePtr; // To move through the list
		
		// Allocate a new node and store num there.
		newNode = new ListNode;
		newNode->value = data;
		newNode->next = nullptr;
		
		// If there are no nodes in the list
		// make newNode the first node.
		if (!head)
			head = newNode;
		else // Otherwise, insert newNode at end.
		{
			// Initialize nodePtr to head of list.
			nodePtr = head;
			
			// Find the last node in the list.
			while (nodePtr->next)
				nodePtr = nodePtr->next;
			
			// Insert newNode as the last node.
			nodePtr->next = newNode;
		}	
}

template <class T>
void NumberList<T>::deleteNode(T data)
{
		ListNode *nodePtr; // To traverse the list
		ListNode *previousNode; // To point to the previous node
	
		// If the list is empty, do nothing.	
		if (!head)
			cout << "There is no subject registered";
		
		// Determine if the first node is the one.
		if (head->value == data)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			// Initialize nodePtr to head of list.
			nodePtr = head;
			
			// Skip all nodes whose value member is
			// not equal to num.
			while (nodePtr != nullptr && nodePtr->value != data)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}
			
			// If nodePtr is not at the end of the list,
			// link the previous node to the node after
			// nodePtr, then delete nodePtr.
			if(nodePtr)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}	
}

template <class T>
void NumberList<T>::display()
{
		ListNode *nodePtr; // To move through the list
		ListNode *next;
		
		nodePtr = head;// Position nodePtr at the head of the list.
		// While nodePtr points to a node, traverse
        // the list.
		while(nodePtr != nullptr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;
			// Move to the next node.
			nodePtr = nodePtr->next;
		}	
}

#endif
