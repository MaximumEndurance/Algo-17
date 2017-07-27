#include "ll.h"

Node* BubbleSort(Node* head ) {
	Node* prev = NULL;
	Node* curr = head;
	if(head->next)
	Node* ahead = head->next;

	if(curr == NULL) return curr;

	while(ahead != NULL) {
		temp = ahead;

		while(temp != NULL) {

			if(ahead->next != NULL) {
			if((curr->data) > (ahead->data)) {
				Node* temp = ahead->next;
				ahead->next = curr;
				curr = temp;

				prev = ahead;
			}

			else {
				prev = curr;
				curr  = ahead;
				ahead = ahead->next;
			}
		}// outer if
	}
}


int main() {
	
}