#include <iostream>
using namespace std;

bool LinearSearch(int a[],int key,int size){
    
    if(size==0)
        return false;
    if(a[0]==key)
        return true;
    LinearSearch(a+1,key,size-1);
}

int main() {
    int n;
    cin >> n;
    int arr[] = {1,2,3,4,5,556,78,89,97,34};

    cout << LinearSearch(arr,n,10) << endl;
    
    return 0;
}
