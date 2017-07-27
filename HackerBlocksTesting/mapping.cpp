#include <iostream>
using namespace std;

char result[1000] ={};
int count = 0;

void phone(char str[], int beg, int res_index) {

if(str[beg] == '\0') {
    result[res_index] = '\0';
    cout<<result<<endl;
    ++count;
    return;
}

    int digit1 = str[beg] - '0';
    char c = digit1 + 'A' -17;
    result[res_index] = c;
    
    phone(str, beg+1, res_index+1);
    
    // if(str[beg+1] == '\0')
    //     return;
        
    int digit2 = str[beg+1] - '0';
    int num1 = digit1*10 + digit2;
    if(num1 <= 26) {
        char c2 = num1 + 'A' - 17;
        result[res_index+1] = c2;
        phone(str, beg+2, res_index+1);
    }
}


int main()
{
// int t;
// cin >> t;

// while(t--) {
//     count = 0;
    int n;
    cin >> n;
    
    char str[n];
    cin >> str;
    
    phone(str, 0 , 0);
    cout<<count<<endl;
//}
return 0;
}
