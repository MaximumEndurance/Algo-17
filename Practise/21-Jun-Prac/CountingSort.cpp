#include<iostream>

using namespace std;
int count_arr[1000000] = {};

void countingSort(int arr[], int n) {
    
    for(int i = 0;i<n; ++i)
        count_arr[arr[i]]++;
}

void PrintcountingSort() {
   for(int i = 0;i<36;++i)
   cout<<count_arr[i]<<' ';
}

void print(int arr[], int n) {
    int i = 0;
    while(n) {
    bool flag =0;
    while(count_arr[arr[i]]--) {
        flag = 1;
    cout<<arr[i]<<" ";
    }
    ++i;
    if(flag == 1)
    --n;
    }
    cout<<endl;
}

void Input(int arr[], int n) {
    for(int i = 0;i<n;++i)
        cin >> arr[i];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    Input(arr, n);
    countingSort(arr, n);
    print(arr, n);
    PrintcountingSort();
	return 0;
}