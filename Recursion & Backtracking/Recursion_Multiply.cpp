#include <iostream>
using namespace std;

int Multiply(int a, int b) {

    long long ans;

    if(b==1)
        return a;
    
    ans = a + Multiply(a,b-1);

    return ans;
}

int main() {
    
    int a,b;
    cin >> a >> b;
    if(a<b)
        swap(a,b);
    cout << Multiply(a,b) << endl;
    return 0;
}
