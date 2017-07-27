#include "bst.h"

bool isBST(Node* root, int minVal, int maxVal) {
	if(!root) {
		return true;
	}
	
	return ((root->data>=minVal && root->data<=maxVal) &&
		isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal));
		//notice importance of shortcircuting here.
}

int main() {
	Node* root = takeInput();
	cout<<isBST(root, -1, 100000)<<endl; 
}