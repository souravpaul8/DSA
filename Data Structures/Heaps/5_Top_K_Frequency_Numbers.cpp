//Given an array of n numbers and a positive integer k.
//The problem is to find k numbers with most occurrences,
//i.e., the top k numbers having the maximum frequency.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999

// funnction to print the k numbers with most occurrences
void topKFrequencyNumbers(int k, int noOfElements, int elements[]) {
	// unordered_map 'frequencyMap' implemented as frequency hash table
	unordered_map<int, int> frequencyMap;

	for (int i = 0; i < noOfElements; i++) {
		frequencyMap[elements[i]]++;
	}

	//priority queue 'pq' implemented as min heap
	// element with the minm frequency is at the top of 'pq'
	// As soon as size exceeds k we pop the largest element
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (auto i = frequencyMap.begin(); i != frequencyMap.end() ; i++) {
		pq.push({i->second, i->first});
		if (pq.size() > k) {
			pq.pop();
		}
	}

	//Printing the Results
	cout << "Top K frequency elements : ";
	for (int i = 0; i < k; i++) {
		cout << pq.top().second << " ";
		pq.pop();
	}
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int noOfElements, k, x;
	cin >> noOfElements >> k;
	int elements[noOfElements];
	for (int i = 0; i < noOfElements; i++) {
		cin >> elements[i];
	}
	topKFrequencyNumbers(k, noOfElements, elements);
	return 0;
}