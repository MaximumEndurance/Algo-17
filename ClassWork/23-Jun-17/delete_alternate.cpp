#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedList.h"

using namespace std;

Node* temp = NULL;

Node* deleteAlt(Node* temp) {
	if(temp == NULL)
		return NULL;

	if(temp->next == NULL)
		return temp;

	cout<<temp->data<<endl;


	return deleteAlt(temp->next->next);
}

int main() {
	int n;
	 cin >> n;
	 Node* head = takeInput(n);

	 print(head);
	 Node* temp = deleteAlt(head);
	 print(temp);
}