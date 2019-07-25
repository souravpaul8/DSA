#include <iostream>

using namespace std;

#define inf 1000000007

int arr[1000000];
int mem[1000000];
int n;

int min_coin(int v){

    if(v==0)
        return 0;
    if(v<0)
        return inf;
    
    if(mem[v]!=-1)
       return mem[v];
    
    int minimum = inf;
    for(int i = 0;i<n;i++){
         minimum = min(minimum,1+min_coin(v-arr[i]));
    }
    mem[v] = minimum;

    return minimum;
}

int main() {
    int t;
    cin >> t;
    while(t--){
     int v;
    cin >> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<=v;i++)
        mem[i] = -1;
    if(min_coin(v)!=inf)
        cout << min_coin(v) << endl;
    else
        cout << "-1" << endl;
    }
    
    return 0;
}
