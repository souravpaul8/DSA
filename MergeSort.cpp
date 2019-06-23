#include <iostream>
using namespace std;

void merge(int input1[], int input2[], int input[],int size1, int size2) {
  
  int i=0;
  int j=0;
  int k=0;
  
  while(i<size1 && j<size2) {
    
    if(input1[i]<input2[j]){
      input[k]=input1[i];
      ++i;
    }else{
      input[k]=input2[j];
      ++j;
    }
     ++k;
  }
  
  while(i<size1){
    input[k]=input1[i];
    ++k;
    ++i;
  }
  
    while(j<size2){
    input[k]=input2[j];
    ++k;
    ++j;
  }
}


void mergeSort(int input[], int size){
	// Write your code here
  
    if(size<= 1)
      return;
    
  	int mid = (size/2);
    
    int input1[mid]={0};
  	int input2[size-mid]={0};   
    
    
  	for(int i=0;i<mid;i++)
      input1[i]= input[i];
  	
  	int k=0;
  	for(int i=mid;i<size;i++){
      input2[k] = input[i];
      k++;
    }

  
    int size1s = sizeof(input1)/sizeof(int);
    int size2s = sizeof(input2)/sizeof(int);
    
    mergeSort(input1,size1s);
    mergeSort(input2,size2s);
  	
  	merge(input1,input2,input,size1s,size2s);
        
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
