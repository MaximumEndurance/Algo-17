#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
    int data;
    vector<Node*> vec;
    
    Node(int val) {
        data = val;
    }
};
Node* InputIt() {
    int data;
    cin >> data;

    Node* root = new Node(data);

    int children;
    cin >> children;

    if(children == 0){
        return root;
    }
    //cout<<root->data<<endl;
    while(children--) {
        //cout<<'1'<<endl;
        Node* newNode = InputIt();
        root->vec.push_back(newNode);
    }
    return root;
}

// Node* input(Node* root = NULL, int children = 0) {
//             int data;
    
//     if(root == NULL) {
//         cin >> data;
//         root = new Node(data);
        
//         cin >> children;
//     }

//     if(children == 0)
//         return NULL;
//     cout<<children<<endl;
//     int i =0;
//     while(i < children) {
//         cin >> data;
//        Node* child = new Node(data);
        
//         root->vec.push_back(child);
//         cin >> children;
//         // vector<Node*> newVec = (root->vec);
//         cout<<"ye  "<<(root->vec[0]->data)<<endl;

//         root->vec[i] =  input(root->vec[i], children);
//         ++i;
//         cout<<"i "<<i<<endl;        
//     }

//     return root;
// } 
std::vector<int> vec;
    void InOrder(Node* root) {
    if(root == NULL)    return ;
    
    vector<Node*>::iterator ii;
    for(ii = root->vec.begin(); ii!= root->vec.end(); ++ii) {
        
            vec.push_back((*ii)->data);
        

        InOrder((*ii));
    }
    
}

bool logic(int x, int y) {
    return (x == y);
}
int main() {
    Node* root  = InputIt();
    int num;
    cin >> num;
    //  cout<<"root "<<root->data<<endl;
    InOrder(root);
     //cout<<"j"<<endl;
    std::vector<int>::iterator ii = find(vec.begin(), vec.end(), num);

        std::vector<int>::iterator greater;

    for(greater = vec.begin(); greater!=vec.end(); ++greater) {
        cout<<"ele "<<(*greater)<<endl;
    }

    for(greater = ii; greater!=vec.end(); ++greater) {
        cout<<*greater<<endl;
        if((*greater) > num) {
            break;
        }
    } 
    cout<<*greater<<endl;
    cout<<((greater == vec.end()) ? -1 : *greater)<<endl;

    return 0;
}