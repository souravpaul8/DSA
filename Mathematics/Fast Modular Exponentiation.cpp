#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll FastModExpo(ll a, ll b, ll m){

    ll res = 1;

    while(b>0) {

        if(b&1){
            res = (res*a)%m;  
        }

        a = (a*a)%m;
        b = b >> 1;
    }

    return res;
}

int main() {
    cout<<FastModExpo(20,50,99);
    return 0;
}
