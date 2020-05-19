#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int a[8],b[8];
  char a;
  int k=0,l=0;

  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){

      cin >> a;
      if(a=='*'){
          a[k] = i;
          b[l] = j;
          ++k;
          ++l;
      }
    }
  }

  int x=1;

  for(int i=0;i<8;i++) {
    for(int j=i+1;j<8;j++){

      if(a[i]==a[j] || b[i]==b[j] || abs(a[j]-a[i])==abs(b[j]-b[i])){
        cout << "invalid" << endl;
        goto X;
      }

    }
  }
  X:
  return 0;
}
