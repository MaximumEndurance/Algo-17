#include "generic-tree.h"

typedef vector<Node*> vN;

vN pushInVec(Node* root) {

	vN vec;

	if(!root) return vec;

	queue<Node*> q;

	q.push(root);
	//q.push(NULL);

	while(!q.empty()) {
		Node * currNode = q.front();
		q.pop();

		vec.push_back(currNode);

	for(vector<Node*>::iterator ii = currNode->vec.begin(); ii!=currNode->vec.end(); ++ii) {
		q.push(*ii);

		}
	}
	return vec; 
}

int main() {
	Node* root1 = takeInput();
	Node* root2 = takeInput();

	vN v1 = pushInVec(root1);
	vN v2 = pushInVec(root2);

	//cout << v1.size() <<' '<<v2.size()<<endl;

	if((v1.size()!=v2.size())) {
	cout<<"false"<<endl;
	return 0;
	}

	vector<Node*>::iterator ii = v1.begin();
	vector<Node*>::iterator jj = v2.begin();
	
	for(; ii!=v1.end(); ++ii, ++jj) {
		//cout<<(*ii)->data<<' '<<(*jj)->data<<endl;
		if((*ii)->data != (*jj)->data)
			break;
	}

	if(ii == v1.end()) {
		cout<<"true"<<endl;

	}
	else {
	cout<<"false"<<endl;
	}

}