#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	int data;
	vector<Node*> vec;

	Node(int val) {
		data = val;
	}
};

Node* buildTree() {
	int data;
	cin >> data;

	Node* root = new Node(data);
	int children;
	cin >> children;

	while(children--) {
		Node* newNode = buildTree();
		root->vec.push_back(newNode);
	}
	return root;
}


int sumAtKLevel(Node* root, int k, int level=0, int sum=0) {
	if(!root) return 0;

	queue<Node*> q;

	q.push(root);
	q.push(NULL);


	while(!q.empty()) {
		Node * currNode = q.front();
		q.pop();

		if(currNode == NULL) {
			//cout<<endl;
			++level;
			if(!q.empty()) {
				q.push(NULL);
			}
			continue;
		}

	if(level == k) {
 	sum+=currNode->data;
 }
	for(vector<Node*>::iterator ii = currNode->vec.begin(); ii!=currNode->vec.end(); ++ii) {
		q.push(*ii);

	}
	}
	return sum;
}

int main() {
	Node* root = buildTree();
	int k;
	cin >> k;
	cout<<sumAtKLevel(root, k)<<endl;
}