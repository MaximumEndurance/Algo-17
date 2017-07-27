#include <iostream>

using namespace std;

char result[100] = {};
void mapped_strings(char str[], int beg, int res_index) {
    
    if(str[beg] == '\0') {
        result[res_index] = '\0';
        cout<<result<<endl;
        return;
        }
    
    int dig1 = str[beg] - '0';
    char c = dig1 + 'A' - 1;
    
    result[res_index] = c;
    
    mapped_strings(str, beg+1, res_index+1);
    
    int dig2 = str[beg] - '0';
    int num = dig1*10 + dig2;

    if(num <=26) {
        char c1 = num + 'A' - 1;
        result[res_index] = c;
        result[res_index+1] = c1;
        
        mapped_strings(str, beg+2, res_index+2);
    }

}
int main() {
    char arr[100];
    
    cin >> arr;
    mapped_strings(arr, 0, 0);
	return 0;
}