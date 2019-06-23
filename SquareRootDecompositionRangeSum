#include <iostream>
#include <cmath>

using namespace std;

int query(int blocks[],int a[],int l,int r,int rn){
    int sum=0;
    while(l<r && l!=0 && l%rn!=0){
        sum+=a[l];
        l++;
    }

    while(l+rn<=r){
        int blockId = l/rn;
        sum+=blocks[blockId];
        l+=rn;
    }

    while(l<=r){
        sum+=a[l];
        l++;
    }
    return sum;
}

void update(int blocks[], int a[],int index,int value,int rn){

    int blockId = index/rn;
    blocks[blockId] += (value-a[index]);
    a[index] = value; 
}

int main() {
    int a[] = {1,3,5,2,7,6,3,1,4,8};
    int sz = sizeof(a)/sizeof(a[0]);

    int rn = sqrt(sz);

    int blocks[rn+1]={0};

    int blockId=-1;
    for(int i=0;i<sz;i++){

        if(i%rn==0)
            blockId++;
        blocks[blockId] = blocks[blockId] + a[i];
    }

    int l,r;
    cin >> l >> r;
    update(blocks,a,2,15,rn);
    cout << query(blocks,a,l,r,rn) << endl;
    return 0;
    }
