#include <iostream>

using namespace std;

int arr[10];
int mem[10];

int max_sum(int i){

    if(i==0)
        return arr[i];
    
    if(mem[i]!=-1)
        return mem[i];

    int res = max(arr[i],arr[i]+max_sum(i-1));
    mem[i] = res;

    return res;
}

int best_sum(int n){

    int maximum = 0;
    for(int i=0;i<n;i++){
        maximum = max(maximum,max_sum(i));
    }

    return maximum;
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<10;i++)
        mem[i] = -1;
    cout << best_sum(n) << endl;
}
