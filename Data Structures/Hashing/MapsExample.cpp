#include<iostream>
#include<unordered_map>
#include<vector>
#include <sstream>
#include<string>

using namespace std;

int main(){

  int m,n;
  cin >> m >> n;

  std::unordered_map<string, int> map;
  string role;
  int value;

  for(int i=0;i<m;i++){

    cin >> role >> value;
    map.insert( std::pair<string,int>(role,value) );
  }

  string arr[n+1];
  for(int i=0;i<n;i++){
    string c;
    string s="";
    while(cin>>c && c[c.length()-1]!='.'){
            s= s+c+" ";
    }
    arr[i] = s;
  }

  for(int i=0;i<n;i++){
      istringstream ss(arr[i]);
      string token;
      std::vector<string> vec;
      int total=0;

      while(getline(ss,token,' ')){
        vec.push_back(token);
      }

      for(int i=0;i<vec.size();i++){
        total = total+ map[vec[i]];
      }

      cout << total << endl;

  }
  return 0;
}
