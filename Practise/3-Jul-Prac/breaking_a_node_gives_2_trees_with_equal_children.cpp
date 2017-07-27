#include "tree.h"


unsigned getNoOfChildren(Node* root) {
	if(!root)	return 0;

	return (1+getNoOfChildren(root->left)+getNoOfChildren(root->right));
}

Node* ans = NULL;

bool areTwoChildrenPossible(Node* root) {
	if(!root)	return 0;

	int no_of_left = getNoOfChildren(root->left);
	int no_of_right = getNoOfChildren(root->right);

	if(no_of_right - no_of_left == 0){
		return true;
		ans = root;
	}

	if(abs(no_of_right - no_of_left == 1))	{
		return false;
	}

	return (areTwoChildrenPossible(root->left) && areTwoChildrenPossible(root->right));
}

int main() {
	Node* root= takeInput();
	cout<<(areTwoChildrenPossible(root) ? ans->data : "No such node")<<endl;
}