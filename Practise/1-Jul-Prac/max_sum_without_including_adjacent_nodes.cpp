#include "tree.h"
#include <utility>

typedef pair<int, int> pi; 

pi max_sum(Node* root) {
	if(!root) {
		pi p(0,0);
		return p;
	}

	pi left = max_sum(root->left);
	pi right = max_sum(root->right);

	int including = root->data + left.second + right.second;
	int excluding = max(left.first, left.second) + max(right.first, right.second);

	pi p(including, excluding);
	return p;
}

int main() {
	Node* root = takeInput();
	print(root);
	pi p = max_sum(root);

	cout<<(max(p.first, p.second))<<endl;
}