#include "tree.h"

void printAllLeaf(Node* root) {
	if(!root) return;

	if(!root->left && !root->right) {
		cout<<root->data<<' ';
	}

	printAllLeaf(root->left);
	printAllLeaf(root->right);
}

int main() {
	Node* root = takeInput();
	printAllLeaf(root);
}