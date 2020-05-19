#include <iostream>

using namespace std;

void BubbleSort(int arr[],int j,int n){

  if(n==1)
    return;

  if(j==n-1)
    BubbleSort(arr,0,n-1);

  if(arr[j]>arr[j+1])
    swap(arr[j],arr[j+1]);
  BubbleSort(arr,j+1,n);

  return;
}

int main(){
  int arr[] = {5,4,7,8,1};
  BubbleSort(arr,0,5);
  for(int i=0;i<5;i++)
    cout << arr[i] << endl;
  return 0;
}
