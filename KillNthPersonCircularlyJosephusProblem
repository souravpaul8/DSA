#include <bits/stdc++.h>
using namespace std;
int josephus(int n, int k);
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
int josephus(int n, int k)
{
   //Your code here
   vector<int> s;
   for(int i=1;i<=n;i++){
       s.push_back(i);
   }
    int count =0;
   while(s.size()!=1){
       count = (count + k-1)%s.size();
       s.erase(s.begin()+count);
   }
   return s[0];
}
