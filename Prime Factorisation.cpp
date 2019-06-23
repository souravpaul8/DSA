#include <bits/stdc++.h>
using namespace std;

vector<int> optimisedPrimeSieve(int *p,int n) {

    p[0]=p[1]=0;
    //Since 2 is the only even number which is prime
    p[2]=1;

    //Since 2 is the only even number which is prime
    for(int i=3;i<=n;i+=2) {
        p[i]=1;
    }

    //So we now cross off(assign 0) all elements which are multiples of a prime number
    for(int i=3;i<=n;i+=2){

        //We cross of multiples of number if the number is prime
        if(p[i]){

          //We start with i*i, if a number is n, then its multiples are 2n,3n,4n....(n-1)n but these
			//numbers have already been crossed off since these are multiples of 2,3,4,....(n-1) respectively.
			//Moreover iteration is 2*i because, we are iterating over odd numbers so i*i is odd number and i is also
			//odd number, therefore (i*i)+i is even, checking which is useless.So we iterate to next odd multiples
			//using j=j+(2*i)  
          for(int j=i*i;j<=n;j+=(2*i)){
            p[j]=0;
            }   
        }
    }

    //Push the primes into the vector primes
    vector<int> primes;
    primes.push_back(2);

    for(int i=3;i<=n;i+=2) {
        if(p[i]==1)
            primes.push_back(i);
    }

    return primes;

}

vector<int> factorsPrime(vector<int> &primes,int n) {

    int i=0;
    int p=primes[0];
    vector<int> factors;

    //We check primes upto sqrt(n)
    while(p*p<=n){
        
        //If the prime divides the number
        if(n%p==0){
            //We push into the vector
            factors.push_back(p);
            //We divide n by p until it becomes indivisible by p
            while(n%p==0){
                n=n/p;
            }
        }
            //We move to the next prime
            i=i+1;
            p=primes[i];
    }

    //If there are no other primes upto sqrt(n) that divides n then the only factor is n itself
    if(n!=1)
        factors.push_back(n);

    return factors;
}

int main() {
    int n = 100000;
    int p[100000];
    int m;
    cin >> m;

    //Create a vectors which contains primes upto 1000 
    vector<int> primes = optimisedPrimeSieve(p,1000);

    //Store the primes which divides the number n
    vector<int> factors = factorsPrime(primes,m);

    //Print the numbers present in the vector factors
    for(auto f:factors)
        cout << f << " " << endl;
    
    return 0;
}
