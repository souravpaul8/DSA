#include<bits/stdc++.h>

using namespace std;

int x,y,GCD;
void ExtendedEuclidsAlgo(int a,int b){

    if(b==0){
        x=1;
        y=0;
        GCD=a;
        return;
    }

    ExtendedEuclidsAlgo(b,a%b);
    int cx = y;
    int cy = x-(a/b)*y;

    x=cx;
    y=cy;
}

int multiModuloInverse(int a, int m){

    ExtendedEuclidsAlgo(a,m);

    return (x+m)%m;
}

int main() {

    cout << multiModuloInverse(8,7) << endl;
    //cout << x << " " << y  << endl;
    return 0;
    
}