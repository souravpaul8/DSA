#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

template<typename T>
class Graph{
  unordered_map<T,list<T>> adjList;

public:
  Graph(){

  }
  void addEdge(T u,T v,bool bidir=true){
    adjList[u].push_back(v);
    if(bidir){
      adjList[v].push_back(u);
    }
  }

  void print(){

    for(auto i:adjList){
      cout << i.first << "->";
      for(auto entry:i.second)
        cout << entry << ",";
      cout << endl;
    }
  }
};

int main(){

  Graph<string> g;
  g.addEdge("Putin","Trump",false);
  g.addEdge("Putin","Modi",false);
  g.addEdge("Putin","Pope",false);
  g.addEdge("Modi","Trump",true);
  g.addEdge("Modi","Yogi",true);
  g.addEdge("Yogi","Prabhu",false);
  g.addEdge("Prabhu","Modi",false);

  g.print();

  cout << endl;

  Graph<int> g2;
    g2.addEdge(0,1);
    g2.addEdge(0,4);
    g2.addEdge(4,3);
    g2.addEdge(1,4);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(1,3);

    g2.print();
}
