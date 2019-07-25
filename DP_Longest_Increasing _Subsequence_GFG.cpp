#include <iostream>

using namespace std;

int a[1000];
int mem[1000];

int lis(int i){
    if(i==0)
        return 1;
    
    if(mem[i]!=-1)
        return mem[i];
    
    int res = 1;
    for(int j=0;j<i;j++){
        if(a[j]<a[i])
           res = max(res,1+lis(j));
    }
    mem[i] = res;
    return res;
}

int lis_help(int n){
    int maximum =0;
    for(int i=0;i<n;i++){
        maximum = max(maximum,lis(i));
    }

    return maximum;
}

int main() {
    
    int t;
    cin >> t;
    while(t--){
            int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<=n;i++)
        mem[i] = -1;

    cout << lis_help(n) << endl;
    }
    return 0;
}
