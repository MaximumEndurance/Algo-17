#include "tree.h"

int search(int in[], int beg, int end, int x) {

	if(beg> end)	{
		return -1;
	}
	if(in[beg] == x)	return beg;

	return search(in, beg+1, end, x);
}

int i = 0;
int inorder_end;

Node* pre_and_in_to_BST(int pre[], int in[], int inBeg, int inEnd) {
	

	if(i > inorder_end || inBeg > inEnd) {
		return NULL;
	}

	Node* root = new Node(pre[i]);
	int idx_to_break_inorder_array_at = search(in, inBeg, inEnd, pre[i]);
	++i;
	root->left = pre_and_in_to_BST(pre, in, inBeg, idx_to_break_inorder_array_at - 1);
	root->right= pre_and_in_to_BST(pre, in, idx_to_break_inorder_array_at + 1, inEnd); 
	return root;
}

int main() {
	int n;
	cin >> n;
	int pre[n], i=0;
	while(n--)  {
		cin >> pre[i++];
	}

	int m;
	cin >> m;
	int in[m];
	i=0;
	while(m--) {
		cin >> in[i++];
	}
	i=0;	
	inorder_end = sizeof(pre)/sizeof(int) -1;
	//index = sizeof(post)/sizeof(int)-1;
	Node* root = pre_and_in_to_BST(pre, in, 0, sizeof(pre)/sizeof(int)-1);
	printWithEnd(root);
	// print(root);
}