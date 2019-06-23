#include <iostream>
using namespace std;

int Tiling(int n){

    if(n==1 || n==2 || n==3 || n==4)
        return n;

    int count = Tiling(n-1) + Tiling(n-4);

    return count;

}

int main() {

    int n;
    cin >> n;

    cout << Tiling(n) << endl;

    return 0;
}
