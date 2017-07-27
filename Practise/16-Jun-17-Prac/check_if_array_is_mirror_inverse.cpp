#include <iostream>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0;i<n;++i) {
        cin >> a[i];
    }
    
    int j = n-1, i;
    
    for(i=0, j; i<n/2 && j>(n-1)/2; ++i, --j){
        if(a[i]!=a[j]  )    break;
    }
    
    if(i>=n/2 || j<=(n-1)/2)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
}
