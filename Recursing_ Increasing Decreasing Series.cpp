#include <iostream>
using namespace std;

void Decreasing(int n){

    if(n<1)
    return;

    cout << n << " ";
    Decreasing(n-1);
}

void Increasing(int n){

    if(n==1){
        cout << "1" << " ";
        return;
    }
    Increasing(n-1);
    cout << n << " ";

}

int main() {
    int n;
    cin >> n;
    Increasing(n);
    cout << "\n";
    Decreasing(n);

    return 0;
}
