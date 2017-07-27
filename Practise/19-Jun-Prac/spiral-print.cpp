#include <iostream>
using namespace std;


int arr[10000][10000]= {};

void spiral_clockwise(int top, int bottom , int left, int right){
    //int top = 0, bottom =n-1, left= 0, right = n-1;
    
    if(top>bottom && left>right) return;
    
    if(top<=bottom){
    for(int i=left;i<=right; ++i){
        cout<<arr[top][i]<<", ";
    }
    }
    
    if(left<right)
    for(int i = top;i<bottom;++i){
        cout<<arr[i][right]<<", ";
    }
    
    if(top < bottom)
    for(int i = right;i>left;--i){
        cout<<arr[bottom][i]<<", ";
    }
    
    if(left < right)
    for(int i = bottom; i>top; --i){
        cout<<arr[i][left]<<", ";
    }
    spiral_clockwise(top-1, bottom-1, left-1, right-1);
}

int main() {
    int m ,n;
    cin >> m >> n;
    

    //const int a = m;
    //const int b = n;
    
    for(int i=0;i<m;++i){
        for(int j = 0; j<n; ++j)
        cin >> arr[i][j];
    }
    
    spiral_clockwise(0, m-1, 0, n-1);
    cout<<"END"<<endl;
}
