#include <iostream>
#include <iomanip>

using namespace std;

double mem[10];

double memLegendres(double x,int n){

    if(n==0)
        return 1;
    if(n==1)
        return x;
    
    if(mem[n]!=-1)
        return mem[n];
    
    double res = ((2*n-1)*x*memLegendres(x,n-1) - (n-1)*memLegendres(x,n-2))/n;

    mem[n] = res;

    return res;
}

int main() {

        int m;
        cin >> m;
        while(m--){
            double x;
            int n;
            cin >> x >> n;
            for (int i = 0; i < 10; i++) mem[i] = -1;
            cout << setprecision(4) << memLegendres(x,n) << endl;
        }
        return 0;
}
