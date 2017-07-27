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

void print(Node* root) {
    if(!root) return;
    
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if(currNode == NULL) {
            cout<<endl;
            //q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout<<currNode->data<<' ';
        
        if(currNode->left) q.push(currNode->left);  
        if(currNode->right) q.push(currNode->right);
    }

}

Node* insertInBST(Node* root, int num) {
    if(!root)   {
        root = new Node(num);
        return root;
    }

    if(root->data > num) {
        root->left=insertInBST(root->left, num);
    }
    else {
        root->right=insertInBST(root->right, num);
    }
    return root;
}

Node* takeInput() {
    int num;
    Node* root = NULL;
    int n;
    cin >> n;
    while(cin >> num && (n--)) {
    root = insertInBST(root, num);
    }
    return root;
}


Node* LCA_in_BST(Node* root, Node* n1, Node* n2) {
	if(!root)	return NULL;

	if((root->data <= max(n1->data, n2->data)) && (root->data >= min(n1->data, n2->data))) {
		return root;
	}
	else if((root->data < n1->data) && (root->data < n2->data)) {
		return LCA_in_BST(root->right, n1, n2);
	}
	else {
		return LCA_in_BST(root->left, n1, n2);
	}
}


int main() {
	Node* root  = takeInput();
	int data1, data2;
	cin >> data1 >> data2;
	
	Node* n1 = 	new Node(data1);
	Node* n2 = 	new Node(data2);

	Node* ans = LCA_in_BST(root, n1, n2);
	cout<<ans->data<<endl;
}   