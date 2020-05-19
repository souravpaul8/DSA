#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 

using namespace std;

struct cmpr{
        bool operator()(pair<int,int> l,pair<int,int> r){
        return l.second<r.second;
    }
}cmp;



int main() {

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<pair<int,int>> vec;

        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            vec.push_back(make_pair(a,b));
        }

        sort(vec.begin(),vec.end(),cmp);
        
        int fin0 = vec[0].second;

        int count = 1;
        int i=1;

        for(int i=1;i<vec.size();i++){
            if(vec[i].first>=fin0){
                fin0 = vec[i].second;
                ++count;
            }
        }

        cout << count << endl;
    }
    return 0;
}
