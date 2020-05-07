/*Given a collection of numbers containing duplicates, print all possible permutations for the given collection of numbers
in a lexicographic manner. Make sure that no two permutations are same.
Sample Input
3
1 1 3
Sample Output
1 1 3 
1 3 1 
3 1 1 
*/

#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

void display(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        cout << a[i] << "  "; 
    } 
    cout << endl; 
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	string s="";
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	do {
		display(arr,n);
	} while (next_permutation(arr, arr+n));
	return 0;
}
