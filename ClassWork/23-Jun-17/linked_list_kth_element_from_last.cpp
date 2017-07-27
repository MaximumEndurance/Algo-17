#include "ll.h"

Node* kth_from_last(Node* head, int k) {
	Node* first = head, second = head;

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
	int k;
	cin >> k;
	Node* head = insert();
	cout<<kth_from_last(head, k)<<endl;	
}