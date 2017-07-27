#include "ll.h"

void deleteAlt(Node* head) {
	if(head == NULL) {
		return;
	}

	if(head->next == NULL){
		return;
	}

	head->next = head->next->next;
	deleteAlt(head->next);
} 

int main() {
	Node* head = insert();

	deleteAlt(head);
	print(head);
}