#include "ll.h"

void alternate_merging(Node* &head1, Node* &head2) {



	if(head1 == NULL) {
		return ;
	}

	if(head2 ==NULL){
		return ;
	}
	cout<<(head1->data)<<' '<<(head2->data)<<endl;

	Node* temp2 = head2->next;
	Node* temp1 = head1->next;

	head1= head2;

	head2 = temp1;

	alternate_merging(temp1, temp2);
}

int main() {
	Node* head1 = insert();
	Node* head2 = insert();

	print(head1);
	print(head2);

	alternate_merging(head1, head2);
	print(head1);
}