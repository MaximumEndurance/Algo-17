#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void print(Node* head) {
    if(!head) return;
    
    cout<<head->data<<' ';
    print(head->next);

}

Node* delete_kth(Node* head, int k) {

    if(head == NULL) {
        return NULL;
    }

    if(k==0){
        head = head->next;
        return head;
    }

    k -= 1;
    Node* temp = head;
    
    while(temp && k--) {
        temp = temp->next;
    }
    if(temp && temp->next) {
    temp->next = temp->next->next;
    }
    return head;
}

int main() {
    int n, q;
    cin >> n;
    cin >> q;
    
    if(n==0) return 0;
    
     Node* head = NULL;
     Node* temp;
     int data;
     cin >> data;
     head = new Node(data);
     temp =head;
     n -= 1;
     
    while(n>0) {
        int data;
        
        cin >> data;
        temp->next = new Node(data);
        temp = temp->next;
        --n;
    }
   
    while(q--) {
        int k;
        cin >> k;
        head = delete_kth(head, k);
        print(head);
        cout<<endl;
    }
    
	return 0;
}