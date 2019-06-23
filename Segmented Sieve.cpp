#include <bits/stdc++.h>

using namespace std;

//Optimised Sieve of Eratosthenes
void optimsedPrimeSieve(long long *p, long long n){
	
	//Since 2 is the only even number which is prime
	p[2]=1;
	
	//Considering all odd numbers as prime, hence 1
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
			for(int j=i*i;j<=n;j+=2*i){
				p[j]=0;
			}
		}
	}
	
	return;

}

//If we need to count the prime numbers between very large numbers between a and b;
int segmentedSieve(long long a, long long b, long long *p){
	//We store the prime numbers upto sqrt(b) in array p
	
	//The array in which we store if a nuber between a and b is prime or not
	bool pp[b-a+1];
    //Initialise each element with 1
	memset(pp,1,sizeof(pp));
	
	for(long long i=2;i*i<=b;i++){
		for(long long j = a;j<=b;j++){
			if(p[i]){
				if(j==i)
					continue;
				if(j%i==0)
					pp[j-a] = 0;
			}
		}
	}
	
	int res = 1;
	for(long long i = a;i<b;i++) {
		res+=pp[i-a];
	}
	
	return res;
		
	
}

int main(){
	
	//Intialising all elements with 0, so all elements considered composite
	long long p[100000] = {0};
	
	optimsedPrimeSieve(p,10000);

    cout << segmentedSieve(1000000,1100000,p) << endl;
	
	
}