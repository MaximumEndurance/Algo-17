#include <iostream>

using namespace std;

class stack {
    int *a;
    int curr_index;
    int default_size;
public:
    //int default_size;
    stack() {
        a = new int[2];
        curr_index = 0;
    }

    void reAssign() {
        default_size = sizeof(a)/sizeof(int)*2;
        int* buffer = new int[default_size];

        for(int i=0;i<default_size/2;++i) {
            buffer[i] = a[i];
        }

        delete [] a;

        a = buffer;

    }

    void push(int elem) {

        default_size = sizeof(a)/sizeof(int)*2;

        if(curr_index < default_size) {
            a[curr_index] = elem;
        }

        else {
            reAssign();

            a[curr_index] = elem;
        }
        ++curr_index;
    }

    int top() {

        if(curr_index == 0) {
            return 0;
        }

        return a[curr_index-1];
    }

    int pop() {

        curr_index -= 1;

        return a[(curr_index)];
    }

    void print() {

        for(int i = 0;i<curr_index; ++i) {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }

    friend ostream& operator<<(ostream& obj,stack s1);
};


friend ostream& operator<<(ostream& obj,stack s1) {
            for(int i = 0;i<curr_index; ++i) {
            obj<<a[i]<<' ';
        }
        cout<<endl;
        return obj;
    
    }

int main() {

    stack s1;

    s1.print();
    s1.push(20);

    cout<<s1;

    //s1.print();
    s1.pop();

    s1.print();
    s1.push(40);



    s1.print();
    s1.push(60);

    s1.print();
}