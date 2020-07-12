#include <iostream>
#include <cmath>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define ALPHABET_SIZE (26)

//Class representing a node of a Trie
class trieNode {
public:
	trieNode* children[ALPHABET_SIZE];
	// isWordEnd is true if the node represents
	// end of a word
	bool isWordEnd;
};

// Returns new trie node (initialized to NULLs)
trieNode* getNode() {
	trieNode *pNode = new trieNode();
	pNode->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie.  If the
// key is prefix of trie node, just marks leaf node
void insertNode(trieNode* head, string key) {
	trieNode* current = head;
	for (int level = 0; level < key.length(); level++) {
		int index = key[level] - int('a');
		if (!current->children[index])
			current->children[index] = getNode();

		current = current->children[index];
	}
	// mark last node as leaf
	current->isWordEnd = true;
}

// Returns true if key presents in trie, else false
bool search(trieNode* head, string key) {
	int length = key.length();
	trieNode* current = head;

	for (int level = 0; level < length; level++) {
		int index = key[level] - int('a');
		if (!current->children[index])
			return false;

		current = current->children[index];
	}

	return (current != NULL && current->isWordEnd);
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool isLastNode(trieNode* head) {
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (head->children[i])
			return false;
	}
	return true;
}

// Recursive function to print auto-suggestions for given
// node.
void suggestionRecursive(trieNode* head, string currentPrefix) {
	// found a string in Trie with the given prefix
	if (head->isWordEnd) {
		cout << currentPrefix << endl;
	}
	// All children struct node pointers are NULL
	if (isLastNode(head))
		return;

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (head->children[i]) {
			// append current character to currPrefix string
			currentPrefix.push_back(97 + i);
			// recur over the rest
			suggestionRecursive(head->children[i], currentPrefix);
			// remove last character
			currentPrefix.pop_back();
		}
	}
}
// print suggestions for given query prefix
int printAutoSuggestion(trieNode* head, string query) {
	trieNode* current = head;
	int n = query.length();
	// Check if prefix is present and find the
	// the node (of last level) with last character
	// of given string.
	for (int level = 0; level < n; level++) {
		int index = query[level] - int('a');
		// no string in the Trie has this prefix
		if (!current->children[index])
			return 0;
		current = current->children[index];
	}
	// If prefix is present as a word
	bool isWord = (current->isWordEnd == true);
	// If prefix is last node of tree (has no
	// children)
	bool isLast = isLastNode(current);
	// If prefix is present as a word, but
	// there is no subtree below the last
	// matching node.
	if (isWord && isLast) {
		cout << query << endl;
		return -1;
	}
	// If there are are nodes below last
	// matching character
	if (!isLast) {
		string prefix = query;
		suggestionRecursive(current, prefix);
		return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	trieNode* root = new trieNode();
	insertNode(root, "hello");
	insertNode(root, "dog");
	insertNode(root, "hell");
	insertNode(root, "cat");
	insertNode(root, "a");
	insertNode(root, "hel");
	insertNode(root, "help");
	insertNode(root, "helps");
	insertNode(root, "helping");
	int comp = printAutoSuggestion(root, "hel");

	if (comp == -1)
		cout << "No other strings found with this prefix\n";

	else if (comp == 0)
		cout << "No string found with this prefix\n";
	return 0;
}