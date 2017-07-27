#include "tree.h"
#include <vector>

int i = 0;	//i maintains a indx of curret root of the array
Node* buildtree(Node* preorder[], int preOrderbeg, Node* inorder[], int mid = 0 {
	Node* root = preorder[preOrderbeg];

	if(!root)	return;

	Node** mid = find(inorder, inorder+(sizeof(inorder)/sizeof(Node*)), root);

	std::vector<Node*> v1(preorder+preOrderbeg, preorder);
	root->left = buildtree(preorder, preOrderbeg+1, inorder, mid-1);
}
