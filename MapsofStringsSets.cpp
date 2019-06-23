#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;
    map<string,set<int> > m;
    string place;
    int year;
    for(int i=0;i<n;i++){
        cin >> place;
        cin >> year;
        m[place].insert(year);
    }

    map<string,set<int> >::iterator row;
    set<int>::iterator col;

    for(auto pair:m){
        if(pair.first=="Iceland")
    }

    cout <

    return 0;
}
