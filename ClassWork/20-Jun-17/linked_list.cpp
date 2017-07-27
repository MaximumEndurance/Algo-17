#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node
{
public:
	int data;
	Node *next;	//sUCH CLASSES ARE CALLED SELF-REFERENTIAL CLASSES

	Node(int num) {
		data = num;
		next = 0;	//NULL is a macro, defined in iostream. So, instead of zero use NULL.
	}
};
/*
Node* takeInput(int n, Node* prevPtr) {
	//take n numbers and add them to a Linked List.
	Node* head = NULL; 
	int val;
	for(int i = 0;i<n; ++i) {
		cin >> val;
	

	head = new Node(val);	//new is an operator and not a function. 12 is  a garbage value. COnstructor HAS to take in a argument.
	//head->data = val;
	prevPtr = head;
	head->next = prevPtr;
	prevPtr = 
	}
	return head;
}
*/
Node* takeInput(int n) {
	Node* prevPtr;
	cout<<"once"<<endl;
	Node * head;
	if(!n) return head;

	int val;
	cin >> val;


	if(head)
	head = new Node(val);


	//prevPtr = head;
	head->next = prevPtr;
	prevPtr = head;

	takeInput(n-1);
}

void print(Node* head){
	cout<<"in";
	if(head == NULL)	return;

		cout<<(head->data)<<endl;
		print(head->next);

	//prints the linked list.
}

int main() {
	Node* Node1 = takeInput(4);
	print(Node1);
}