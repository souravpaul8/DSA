#include <iostream>

using namespace std;

set<string> setPerm;
https://github.com/souravpaul8/MyCode

int noOfPath(int a,int b){

    if(a==1 || b==1)
        return 1;

    return noOfPath(a,b-1) + noOfPath(a-1,b);
}

int main() {
	int t;
    cin >> t;
    while(t--){
      int a,b;
      cin >> a >> b;
      cout << noOfPath(a,b) << endl;
    }
    
	return 0;
}
