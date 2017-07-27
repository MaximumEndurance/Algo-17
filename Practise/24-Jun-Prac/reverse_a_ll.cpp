#include "ll.h"

Node* newNode;

Node* reverse(Node* head) {

	if(head== NULL || head->next == NULL) {	//remember the "==". last time placing a a single '=' took minutes to debug.
		return head;
			}
			
	newNode = reverse(head->next);
		
	head->next->next = head;
	head->next = NULL;
	
	return newNode;
}

int main() {
	Node* head = insert();
	print(head);
	Node* ans = reverse(head);
	print(ans);
}

