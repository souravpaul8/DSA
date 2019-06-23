#include <iostream>
using namespace std;

void multiply(int *a, int &n, int no) {

    int carry = 0;

    for(int i=0;i<n;i++) {

        int product = a[i]*no + carry;
        a[i] = product % 10;
        carry = product/10;
    }

    while(carry) {
        a[n] = carry%10;
        n++;
        carry = carry/10;
    }
}


int bigFactorial(int number) {

    int *a = new int[1000]{0};

    a[0] = 1;
    int n=1;

    for(int i=2;i<=number;i++) {

        multiply(a,n,i);
    }

    for(int i=n-1;i>=0;i--) {

        cout << a[i];
    }

    cout << endl;
    cout << n << " digits" <<endl;

    return 0;

}

int main() {

    bigFactorial(200);

    return 0;

}
