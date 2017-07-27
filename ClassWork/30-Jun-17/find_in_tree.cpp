#include "tree.h"

class Pair {
public:
	int leftNodes;
	int rightNodes;

	Pair(int x , int y) {
		leftNodes = x;
		rightNodes = y;
	}
};


int countNodes(Node * root){
	if (root == NULL){
		return 0;	//empty tree has zero nodes!
	}

	int leftCount = countNodes(root->left);	//get count of left SUBTREE
	int rightCount = countNodes(root->right);
	return leftCount + 1 + rightCount; //return count of WHOLE tree
}

bool isBalanced(Node* root) {
	if(!root) {
		Pair p(0, 0);
		return p;
	}

	bool isRootBalanced = abs((p.leftNodes - p.rightNodes) < 2) ? 1 :0; 

	return (isBalanced(root->left) && isBalanced(root->right);



	// int leftNodes = countNodes(root->left);
	// int rightNodes = countNodes(root->right);

	// if(abs(leftNodes - rightNodes) < 2) {
	// 	return false;
	// }

	// else {
	// 	return true;

	// }
}

int main() {
	Node* root = takeInputLevel();

	cout<<isBalanced(root)<<endl;
}