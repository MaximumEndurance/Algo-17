#include "ll.h"

Node* mid(Node* head) {
	Node* slow = head;
	Node* fast  = head;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node* merge(Node* left, Node* right) {

	if(left == NULL)
		return right;

	else if(right == NULL)
		return left;

	if(left->data < right->data) {
		left->next = merge(left->next, right);

	}
	else {
		right->next = merge(left, right->next);
	}
}

Node* mergeSort(Node* beg, Node* end) {
		Node* mid = mid(beg);

		return mergeSort(mid->next, end);
		mid->next = NULL;
		return mergeSort(beg, mid);
	

} 