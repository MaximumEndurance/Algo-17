#include "ll.h"

static Node* head = NULL;

int count  = 0;	

Node* merge(Node* left1, Node* left2) {

	if(left1 == NULL) {
		
		return left2;
	}

	if(left2 == NULL) {
		return left1;
	}

	if(left1->data < left2->data) {
		left1->next = merge(left1->next, left2);
	}

	else {
		left2->next = merge(left1, left2->next);
	}
}


int main() {

	Node* head1 = insert();
	Node* head2 = insert();
	print(head1);
	print(head2);
	Node* ans = merge(head1, head2);
	print(ans);

}