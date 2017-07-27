#include "ll.h"

Node* newNode;


Node* reverse(Node* head, int k) {

	static Node* temp2= head;

	if(k==0 && head->next == NULL) {
		temp2 = head->next;
		return head;
	}

	if(head->next==NULL) {	//remember the "==". last time placing a a single '=' took minutes to debug.
		return head;
		}
			
	newNode = reverse(temp2->next, k-1);
		
	temp2->next->next = temp2;
	temp2->next = NULL;
	
	return newNode;
}

int main() {
	Node* head = insert();
	int k;
	cin >> k;
	print(head);
	Node* ans = reverse(head, k);
	print(ans);
}

