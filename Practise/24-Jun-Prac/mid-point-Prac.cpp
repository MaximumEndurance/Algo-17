#include "ll.h"

Node* midPoint(Node* head) {
	Node* fast = head;
	Node* slow = head;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

		return slow;
	
}

int main() {
	Node* head = insert();

	print(head);

	Node* ans = midPoint(head);

	cout<< (ans->data) <<endl;
}