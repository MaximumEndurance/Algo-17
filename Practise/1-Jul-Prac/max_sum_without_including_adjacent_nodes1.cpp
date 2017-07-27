
#include <utility>
#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node * takeInput(){
	//function to take Input as a tree --levelwise
	int data;
	cin >> data;
	if (data == -1) return NULL;

	Node * root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		//there is a node with potential to become parent
		Node *curParent = q.front();
		q.pop();

		int leftData;	cin >> leftData;
		//left child exists, hence create and attach to the parent
		//Also, this child can become Parent in the near future ;)
		if (leftData != -1){
			Node * tmp = new Node(leftData);
			curParent->left = tmp;
			q.push(tmp);
		}

		//similarly for right child
		int rightData; 	cin >> rightData;
		if(rightData != -1){
			Node * tmp = new Node(rightData);
			curParent->right = tmp;
			q.push(tmp);
		}
	}
	return root;
}

void print(Node* root) {
	if(root == NULL)	return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* currNode = q.front();

		q.pop();

		if(currNode == NULL) {
			cout<<endl;
			q.pop();

			if(!q.empty()) {
				q.push(NULL);
			}
			continue;
		} 

		cout<<(currNode->data)<<endl;

		if(currNode->left) {
			q.push(currNode->left);
		}

		if(currNode->right) {
			q.push(currNode->right);
		}
		}  
}

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
	cout<<"inc "<<p.first<<" ex "<<p.second<<endl;

	return p;
}

int main() {
	Node* root = takeInput();
	print(root);
	pi p = max_sum(root);

	cout<<"ans "<<(max(p.first, p.second))<<endl;
}