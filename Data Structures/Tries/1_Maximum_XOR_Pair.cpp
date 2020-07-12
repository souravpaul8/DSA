#include <iostream>
#include <cmath>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

//Class representing a node of a Trie
class trieNode {
public:
	trieNode* left;
	trieNode* right;
};

//Function to insert node in the Trie
//Each left branch represent 0 bit and right branch 1 bit
//So we insert nodes for each bit, if it is not already present
void insertNode(int n, trieNode* head) {
	trieNode* current = head;
	//Considering operation for max 32 bit numbers
	for (int i = 31; i >= 0; i--) {
		int b = (n >> i) & 1;

		if (b == 0) {
			if (!current->left) {
				current->left = new trieNode();
			}
			current = current->left;
		} else {
			if (!current->right) {
				current->right = new trieNode();
			}
			current = current->right;
		}
	}
}

//For max XOR, we need inverted bits i.e. if it's 0, we need 1 to get 1
//If it's 1, we need 0 to get 1. If that's not present we dont have any choice
//other than going along the same bits
//We dont have to worry about hitting NULL, because if dont get alternate bits, we will always 
//go along the bits of the number itself
int findMaxXorPair(trieNode* head, int* arr, int n) {
	int max_xor = INT_MIN;

	for (int i = 0; i < n; i++) {
		int value = arr[i];
		trieNode* current = head;
		int current_xor = 0;
		for (int j = 31; j >= 0; j--) {
			//Determining bIt value
			int b = (value >> j) & 1;
			// If bit is 0, we wouuld love bit 1, so we move towards right if possible
			if (b == 0) {
				if (current->right) {
					current_xor += pow(2, j);
					current = current->right;
				} else  {
					current = current->left;
				}

			} else {
				if (current->left) {
					current_xor += pow(2, j);
					current = current->left;
				} else  {
					current = current->right;
				}
			}
		}

		if (current_xor > max_xor)
			max_xor = current_xor;
	}

	return max_xor;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	trieNode* head = new trieNode();
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		insertNode(arr[i], head);
	}
	cout << findMaxXorPair(head, arr, n);
	return 0;
}