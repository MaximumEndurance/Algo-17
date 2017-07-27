#include "tree.h"
#include <stack>
#include <algorithm>

		std::vector<int> v;

void printStack(stack<Node*> s) {

	if(s.empty()) {
		reverse(v.begin(), v.end());
		for(vector<int>::iterator ii= v.begin(); ii!=v.end();++ii) {
			cout<<(*ii)<<' ';
		}
		cout<<endl;
		return;
	}
	v.push_back((s.top()->data));
	s.pop();
	printStack(s);
}

int getsum(stack<Node*> s, int sum = 0) {


	if(s.empty()) {
		// cout<<sum<<endl;
		return sum;
	}
	sum += s.top()->data;
	s.pop();
	return getsum(s, sum);
}


void printAllPaths(Node* root, stack<Node*>& s, int k) {
	if(!root)	return;

	s.push(root);

	if(root->left==NULL && root->right == NULL) {
		// cout<<"s "<<s.size()<<endl;
		int sum =getsum(s);
		// cout<<"Sum "<<sum<<endl;
		if(getsum(s) == k) {
		printStack(s);
		}

		s.pop();
		return;
	}

	printAllPaths(root->left, s, k);
	printAllPaths(root->right, s, k);
	s.pop();	//jab dono left and right chilren cater ho gaye, then move up. Matalb parent ko hata do.
}

int main(int argc, char const *argv[])
{
	Node* root= NULL;
	inputTandF(root);

	stack<Node*> s;

	int k;
	cin >> k;

	printAllPaths(root, s, k);

	return 0;
}