#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> setPerm;

void permutations(string s, string perm){
    
    if(s.empty()){
        setPerm.insert(perm);
    }else{
          for(int i=0;i<s.length();i++){
        //Choose
        char c = s[i];
        perm = perm + c;
        s = s.erase(i,1);
        //Permutation
        permutations(s,perm);
        //Unchoose
        s = s.insert(i,1,c);
        perm.erase(perm.length()-1,1);
    }

    }
}

int main() {
	int t;
    cin >> t;
    while(t--){
      string s;
      cin >> s;
      permutations(s,"");
      for(auto itr= setPerm.begin();itr!=setPerm.end();itr++){
          cout << *itr << " ";
      }
      setPerm.clear();
      cout << endl;
    }
    
	return 0;
}
