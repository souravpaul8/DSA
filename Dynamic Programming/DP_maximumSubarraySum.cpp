#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int,int> DP;
 int a[] = {-15,8,-2,1,0,6,-3};

int maxSubarraySum(int i){

    if(i==0){
        return a[0];
    }
    if(DP.find(i)!=DP.end())
        return DP[i];

    int res = max(a[i],a[i] + maxSubarraySum(i-1));

    DP[i] = res;
    return res;
}

int main() {
    int maxm = 0;
    for(int i=0;i<7;i++){
        maxm = max(maxm,maxSubarraySum(i));
    }
    cout << maxm << endl;
    return 0;
}
