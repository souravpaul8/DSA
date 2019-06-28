#include <iostream>
#include <map>
using namespace std;

map<long long,long long> DP;

long long nThFibonacciDP(int n){

    if(n<=2)
        return 1;
    
    if(DP.find(n)!=DP.end())
        return DP[n];
    
    long long res = nThFibonacciDP(n-1) + nThFibonacciDP(n-2);

    DP[n] = res;
    return res;
}https://github.com/souravpaul8/MyCode

int main() {
    int n;
    cin >> n;
    cout << nThFibonacciDP(n) << endl;
    return 0;
}
