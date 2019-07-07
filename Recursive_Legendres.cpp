#include <iostream>
#include <iomanip>
using namespace std;


double recursiveLegendres(double x,int n){

    if(n==0)
        return 1;
    if(n==1)
        return x;
    
    return ((2*n-1)*x*recursiveLegendres(x,n-1) - (n-1)*recursiveLegendres(x,n-2))/n;

}
int main() {

        int m;
        cin >> m;
        while(m--){
            double x;
            int n;
            cin >> x >> n;
            cout << setprecision(4) << recursiveLegendres(x,n) << endl;
        }
        return 0;
}
