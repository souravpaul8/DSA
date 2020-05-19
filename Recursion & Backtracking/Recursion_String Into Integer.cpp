#include <bits/stdc++.h>
using namespace std;

int String_to_Int(char a[],int n) {

    int ans;
    if(n<1)
        return 0;
    
    ans = ((int)a[0]-48)*pow(10,n-1) + String_to_Int(a+1,n-1);

    return ans;

}



int main() {
    string a;
    cin >> a;
    char arr[a.length()];
    strcpy(arr, a.c_str()); 
    cout << String_to_Int(arr,a.length()) << endl;
    return 0;
}
