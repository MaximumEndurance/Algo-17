#include "ll.h"
#include <time.h>
#include <cstdlib>

Node* intersection_point(Node* head1, Node* head2) {

	if(head1 == NULL || head2 == NULL) {
		cout<< "No such point exists"<<endl;
		return NULL;
	}
	Node* temp2 = head2;

	while(temp2 != NULL) {
		if(temp2->data == head1->data) {
			return head1;
		}
		temp2 = temp2->next;
	}

	return intersection_point(head1->next, head2);

}

void generate_intersection(Node* head1, Node* head2) {
	int len1 = length(head1);
	int len2 = length(head2);

	srand(time(0));

	//int loop_times = rand()%(len1-1) + 1;
	int loop_times = 1;
	cout<<"loop_times "<<loop_times<<endl;
	while(loop_times--) {
		head1 = head1->next;

	}

	while(head2->next!=NULL){
		head2 = head2->next;
	}
	head2->next = head1;
}

int main() {
	Node* head1 = insert();
	Node* head2 = insert();

	generate_intersection(head1, head2);

	print(head1);
	print(head2);
	Node* ans = intersection_point(head1, head2);

	cout<<(ans->data)<<endl;
}