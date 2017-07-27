#include "tree.h"

bool search(Node* root, int val) {
	if(!root)	return 0;

	if(root->data == val)
		return 1;

	return (search(root->left, val) || search(root->right, val));
}

Node* LCA_in_BT(Node* root, Node* n1, Node* n2) {
	if(!root)	return NULL;

	bool onLeft1 = search(root->left, n1->data);
	bool onRight1 = search(root->right, n2->data);

	bool onLeft2 = search(root->left, n2->data);
	bool onRight2 = search(root->right, n1->data);

	if((onLeft1 && onRight1) || (onLeft2 && onRight2)) {
		return root;
	}

	if(onLeft1 && onLeft2) {
	return LCA_in_BT(root->left, n1, n2);
}
	if(onRight1 && onRight2) {
	return LCA_in_BT(root->right, n1, n2);
}
return root;

}

int main() {
	Node* root = takeInput();
	print(root);

	int data1; int data2;
	
	cin >>data1 >>data2;

	Node* n1  =new Node(data1);
	Node* n2 = new Node(data2);
	Node* ans = LCA_in_BT(root, n1, n2);

	cout<<ans->data<<endl;
}