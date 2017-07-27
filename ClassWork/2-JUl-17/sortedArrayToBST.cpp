#include "bst.h"

Node* arrayToBST(int arr[], int beg, int end) {
	if(beg > end) {
		return NULL;
	}
	int mid = (beg+end)/2;

	Node* root = new Node(arr[mid]);

	root->left = arrayToBST(arr, beg, mid-1);
	root->right = arrayToBST(arr, mid+1, end);
}

int main() {
	int arr[10000];

	int num, i=0;
	while(cin >> num && num != -1) {
		arr[i++] = num;
	}
	Node* root = arrayToBST(arr, 0, i-1);
	print(root);
}