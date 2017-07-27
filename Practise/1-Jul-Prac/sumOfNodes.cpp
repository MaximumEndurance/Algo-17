#include "tree.h"

int sumOfNodes(Node* root, int sum = 0) {
	if(!root) return 0;

	 sum += sumOfNodes(root->left, sum);
	 sum += sumOfNodes(root->right, sum);
	 return sum;
}

int main() {
	Node* root = takeInput();
	cout<<sumOfNodes(root)<<endl;
}