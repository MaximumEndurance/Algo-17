#include <stack>
#include "bst.h"


class ll {
public:
	int data;
	ll* next;

	ll(int val) {
		data = val;
	}
};

ll* convertToBST(Node* root, ll * head = NULL) {
	ll* temp;

	if(!root) {
		return NULL;
	}
		convertToBST(root->left, temp);

	ll* newll = new ll(root->data);
	if(!head) {
		temp = newll;
		head = temp;
		return convertToBST(root->left, temp); 
	}

	temp->next = newll;

	convertToBST(root->right, temp);
	return head;
}

void voidPrintLL(ll* head) {
	if(!head){
		cout<<endl;
		return;
	}

	cout<<head->data<<" ";

}
int main() {
	Node* root = takeInput();
	cout<<root->data<<endl;
	ll* newll = convertToBST(root);
	cout<<newll->data<<endl;
	voidPrintLL(newll);
}