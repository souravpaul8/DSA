#include <iostream>

using namespace std;

//Optimised Sieve of Eratosthenes
void optimsedPrimeSieve(int *p,int n){
	
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

int main(){
	
	//Intialising all elements with 0, so all elements considered composite
	int p[10000] = {0};
	
	optimsedPrimeSieve(p,100);
	
	for(int i=1;i<=100;i++) {
		if(p[i]==1)
		cout << i << " ";
 	}
}