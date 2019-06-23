#include <iostream>

using namespace std;

string arr[] = {"zero", "one" , "two" , "three" , "four", "five", "six", "seven", "eight","nine" };

void IntToString(int n){

    string a = "";
    if(n==0)
        return;
     
     IntToString(n/10);

     cout << arr[n%10] << " ";
}

using namespace std;
int main() {
    int n;
    cin >> n;
    IntToString(n);
    return 0;
}
