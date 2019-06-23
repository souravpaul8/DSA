#include <iostream>
#include <queue>

using namespace std;

int main(){

 string c;
 vector<long long> vec;
 while(cin >> c){
   if(c=="#"){
     int mid;
     int size = vec.size();
     if(size%2==0){
       mid = (size/2)+1;
     }else{
       mid = (size+1)/2;
     }

     long long num = vec[mid-1];
     cout << num << endl;

     for(int i=mid-1;i<size-1;i++)
        vec[i]=vec[i+1];
     vec.resize(size-1);
   }else{

     vec.push_back(stoi(c));
   }
 }

  return 0;
}
