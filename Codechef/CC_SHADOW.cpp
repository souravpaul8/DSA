#include <iostream>
#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

long long calculate_sum(long long a, long long N) 
{ 
    long long m = N / a; 
 
    long long sum = m * (m + 1) / 2; 
  
    long long ans = a * sum; 
  
    return ans; 
} 
 

int main()
{
int t;
cin>>t;
while(t--)
{
    long long A,B,L,R;

    cin>>A>>B>>L>>R;
    if(L>R)
    swap(L,R);

    long long sumA= calculate_sum(A,R) - calculate_sum(A,L-1);
    //cout << sumA << " ";
    long long sumB=calculate_sum(B,R) - calculate_sum(B,L-1);
    //cout << sumB << endl;
    long long PS=sumA+sumB;
     
    long long X = gcd(A,B);
    //cout << X << " ";
    long long lcm = (A/X)*B;
    //cout << lcm <<endl;

    long long sumlcm = calculate_sum(lcm,R) - calculate_sum(lcm,L-1) ;
    //cout << sumlcm << endl;

    if(abs(PS-sumlcm)%2==0 && (PS%2==0||PS%3==0))
       cout<<"TRUE LOVE"<<endl;
    else  if(abs(PS-sumlcm)%2==0 || (PS%2==0||PS%3==0))
        cout<<"LOVE"<<endl;
    else
        cout<<"FAKE LOVE"<<endl;
    
}

  return 0;
}
