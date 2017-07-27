#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = NULL;
	}
};


Node* takeInput() {
	Node* head = NULL;
	int val  =0;
	while(val != -1) {
		
		cin >> val;

		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;

	}
	return head;
}

void printNode(Node* head) {
	Node* temp = head;
	while(temp != NULL) {
		cout<<(temp->data)<<"-->";
		temp =  temp->next;
	}
}

int main() {
	
	Node* head = takeInput();
	printNode(head);
}