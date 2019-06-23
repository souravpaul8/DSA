#include <iostream>
#include <vector>

using namespace std;

struct union_find {
    vector<int> parent;
    union_find(int n){
      parent = vector<int>(n);
      for(int i=0;i<n;i++)
          parent[i]=i;
    }
    int find(int x){
      if(parent[x]==x)
          return x;
      parent[x] = find(parent[x]);
      return parent[x];
    }
    void unite(int x,int y){
      parent[find(x)] = find(y);
    }
    bool connected(int x,int y){
      return find(x)==find(y);
    }
};

int main(){
  std::ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  union_find uf(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    uf.unite(a-1,b-1);
  }
  bool stat = true;
  for(int i=1;i<n;i++){
    if(!uf.connected(0,i)){
      cout << i+1 << endl;
      stat = false;
    }
  }
  if(stat==true)
    cout << "Connected" << endl;
   return 0;
}
