#include <bits/stdc++.h>
using namespace std;

string PhoneDigits[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void RecursivePhoneDigit(int arr[],string chosen,int n){
    if(n==0)
        cout << chosen << " ";
    else{
        for(int itr = 0;itr<PhoneDigits[arr[0]].length();itr++){
            //Choose
            char c = PhoneDigits[arr[0]][itr];
            chosen += c;
            //Recursive Call
            RecursivePhoneDigit(arr+1,chosen,n-1);

            //unchoose
            chosen.erase(chosen.length()-1,1);
        }
    }


}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        RecursivePhoneDigit(arr,"",n);
        cout << endl;
	}
	return 0;
}
