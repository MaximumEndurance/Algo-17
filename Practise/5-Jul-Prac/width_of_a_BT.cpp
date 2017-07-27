#include "tree.h"

int width(Node* root, int count =0 ,int maxcount =0) {
    if(!root) return 1;
    
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if(currNode == NULL) {
            cout<<endl;
            if(count > maxcount) {
            	maxcount = count;
            	count = 0;
            }
            //q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        // cout<<currNode->data<<' ';
        ++count;
        if(currNode->left) q.push(currNode->left);  
        if(currNode->right) q.push(currNode->right);
    }
    return maxcount;

}

int main() {
	Node* root = takeInput();
	cout<<"Width "<<width(root)<<endl;
}