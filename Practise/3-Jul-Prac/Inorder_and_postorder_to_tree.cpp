#include "tree.h"

int getIndexOf(int in[], int beg, int end, int x) {

	if(beg> end)	{
		return -1;
	}
	if(in[beg] == x)	return beg;

	return getIndexOf(in, beg+1, end, x);
}

int index;

Node* iAndPToBST(int in[], int post[], int inOrderBeg, int inOrderEnd) {

	if(index<0 || inOrderBeg > inOrderEnd) {
		return NULL;
	}

	Node* root = new Node(post[index]);

	int idx = getIndexOf(in, inOrderBeg, inOrderEnd, post[index--]);

	root->right = iAndPToBST(in, post, idx+1, inOrderEnd );

	root->left = iAndPToBST(in, post, inOrderBeg, idx-1 );
	
	return root;


}

int main() {
	int n;
	cin >> n;
	int post[n], i=0;
	while(n--)  {
		cin >> post[i++];
	}

	int m;
	cin >> m;
	int in[m];
	i=0;
	while(m--) {
		cin >> in[i++];
	}
	index = sizeof(post)/sizeof(int)-1;
	Node* root = iAndPToBST(in, post, 0, sizeof(post)/sizeof(int)-1);
	printWithEnd(root);
	// print(root);
}