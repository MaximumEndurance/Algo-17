#include "bst.h"

Node* LCA_in_BST(Node* root, Node* n1, Node* n2) {
	if(!root)	return NULL;

	if((root->data <= max(n1->data, n2->data)) && (root->data >= min(n1->data, n2->data))) {
		return root;
	}
	else if((root->data < n1->data) && (root->data < n2->data)) {
		return LCA_in_BST(root->right, n1, n2);
	}
	else {
		return LCA_in_BST(root->left, n1, n2);
	}
}


int main() {
	Node* root  = takeInput();
	int data1, data2;

	cin >> data1 >> data2;
	
	Node* n1 = 	new Node(data1);
	Node* n2 = 	new Node(data2);

	Node* ans = LCA_in_BST(root, n1, n2);
	cout<<(ans->data)o<<endl;
}