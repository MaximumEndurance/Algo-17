#include "ll.h"

Node* kth_from_last(Node* head, int k) {
	Node* first = head;
	Node* second  = head;

	while(k--) {
		second = second->next;
	}

	while(second->next) {
		second = second->next;
		first = first->next;
	}
	return first;
}

int main() {
	Node* head = insert();

	int k;
	cin >> k;
	cout<<(kth_from_last(head, k-1))->data<<endl;	
}