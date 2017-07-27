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

Node * takeInputLevel(){
	//function to take Input as a tree --levelwise
	int data;
	cin >> data;
	if (data == -1) return NULL;

	Node * root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		// cout<<"in"<<endl;
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


int height(Node* root) {
	//cout<<"in"<<endl;
	if(!root) return 0;
	return 1+max(height(root->left), height(root->right));

}

void reverse(Node* root) {
	if(root == NULL)	return;

	Node * temp =root->right;
	root->right = root->left;
	root->left = temp;

	reverse(root->left);
	reverse(root->right);
}


void printLevel(Node * root){
	queue<Node * > q;
	q.push(root);
	q.push(NULL);

	while(q.empty() == false){
		//I have atleast one node to print
		Node* cur = q.front();
		q.pop();
		
		//delimiter case
		if(cur == NULL){
			cout << endl;
			if (!q.empty()){
				q.push(NULL);
			}
			continue;
		}


		cout << cur->data << " ";
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
}

bool findInTree(Node* root, int key) {
	if(!root) return false;

	if(root->data == key) {
		return true;
	}
	else {
		return (findInTree(root->left, key) || findInTree(root->right, key));
	}
}

int main() {
	Node* root = takeInputLevel();
	//printLevel(root);
	//cout<<(1+ height(root->left) + height(root->right))<<endl;
	reverse(root);
	printLevel(root);
}
