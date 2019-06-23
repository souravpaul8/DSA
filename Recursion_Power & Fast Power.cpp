#include <iostream>
using namespace std;

long long FastPower(int a,int b){
    long long ans;
    if(b==0)
        return 1;
    ans = FastPower(a,b/2);
    ans *= ans;
    if(b%2==0)
        return ans;
    else
        return a*ans;
}

long long power(int a, int b){

    long long ans;
    if(b==0)
        return 1;
     ans = a*power(a,b-1);

     return ans;
}

int main() {
    int a;
    int b;
    cin >> a >> b;
    cout << FastPower(a,b);
}
