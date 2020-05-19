#include <iostream>
using namespace std;

int EuclidsAlgo(int a, int b){

    if(b==0)
        return a;
    EuclidsAlgo(b,a%b);
}

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

int main() {

    ExtendedEuclidsAlgo(18,30);
    cout << x << " " << y  << endl;
    return 0;
    
}
