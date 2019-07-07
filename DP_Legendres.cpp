#include <iostream>
#include <iomanip>
using namespace std;

double leg[10];


void dpLegendres(double x,int n){

    leg[0]=1;
    leg[1] = x;

    for(int i=2;i<=n;i++){
        leg[i] = ((2*i-1)*x*leg[i-1] - (i-1)*leg[i-2])/i;
    }
    
}
int main() {

        int m;
        cin >> m;
        while(m--){
            double x;
            int n;
            cin >> x >> n;
            dpLegendres(x,n);
            cout << setprecision(4) << leg[n] << endl;
        }

        return 0;
}
