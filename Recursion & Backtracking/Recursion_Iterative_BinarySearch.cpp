#include <iostream>

using namespace std;

int BinarySearchIterative(int a[],int l,int r,int n){

  while(l<=r){

    int mid = (l+r-1)/2;

    if(a[mid]==n)
      return mid;

    if(a[mid]>n)
      r = mid-1;

    if(a[mid]<n)
      l= mid+1;
  }

  return -1;
}

int BinarySearch(int a[],int l,int r,int n){

  if(r>=l){

    int mid = (l+r-1)/2;

    if(a[mid]==n)
      return mid;

    if(a[mid]>n)
      return BinarySearch(a,l,mid-1,n);

    return BinarySearch(a,mid+1,r,n);

  }

  return -1;

}

int main(){

int arr[6] = {1,2,3,4,5,6};

cout << BinarySearchIterative(arr,0,5,4) << endl;

 return 0;

}
