#include <bits/stdc++.h>

using namespace std;

int INF = 100000;
int d[10];
int mem[10][10000];

int minimumCoin(int i,int x){

  if(x<0)
    return INF;
  if(x==0)
    return 0;
  if(i==-1)
    return INF;

  if(mem[i][x]!=-1)
    return mem[i][x];

  int res = INF;
  res = min(res,1+minimumCoin(i,x-d[i]));
  res = min(res,minimumCoin(i-1,x));
  
  mem[i][x] = res;
  return res;
  
}

int main(){

  memset(mem, -1, sizeof(mem));
  for(int i=0;i<4;i++){
      cin >> d[i];
  }
  int value = 11;

  cout << minimumCoin(3,value);
  
  return 0;
}
