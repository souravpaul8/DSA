#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999

//Class representing a node in BST
class Node {
public:
	int key;
	Node* left;
	Node* right;

	//Default Constructor
	Node() {
		key = 0;
		left = NULL;
		right = NULL;
	}

	//Parameterised Constructor
	Node(int val) {
		key = val;
		left = NULL;
		right = NULL;
	}
};

//Class representing the BST
class Tree {
private:
	Node* root;

public:
	//Parameterised Constructor to create a BST
	Tree(int rootValue) {
		root = new Node(rootValue);
	}

	//Function to return root
	Node* getRoot() {
		return root;
	}

	Node* insertNode(Node* root, int key) {
		// Insert the first node, if root is NULL.
		if (root == NULL) {
			return new Node(key);
		} // Insert data.
		else if (key < root->key) {
			// Insert left node data, if the 'value'
			// to be inserted is greater than 'root' node data.
			// Process left nodes.
			root->left = insertNode(root->left, key);
		}
		else if (key > root->key) {
			// Insert right node data, if the 'value'
			// to be inserted is greater than 'root' node data.
			// Process right nodes.
			root->right = insertNode(root->right, key);
		}
		// Return 'root' node, after insertion.
		return root;
	}

	/* Given a non-empty binary search tree, return the node with minimum
	key value found in that tree. Note that the entire tree does not
	need to be searched. */
	Node* minValueNode(Node* root) {
		Node* current = root;
		/* loop down to find the leftmost leaf */
		while (current && current->left != NULL)
			current = current->left;
		return current;
	}

	/* Given a non-empty binary search tree, return the node with maximum
	key value found in that tree. Note that the entire tree does not
	need to be searched. */
	Node* maxValueNode(Node* root) {
		Node* current = root;
		/* loop down to find the rightmost leaf */
		while (current && current->right != NULL)
			current = current->right;
		return current;
	}

	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	Node* deleteNode(Node* root, int key) {
		// base case
		if (root == NULL) {
			return root;
		}
		// If the key to be deleted is smaller than the root's key,
		// then it lies in left subtree
		if (key < root->key) {
			root->left = deleteNode(root->left, key);
		}
		// If the key to be deleted is greater than the root's key,
		// then it lies in right subtree
		else if (key > root->key) {
			root->right = deleteNode(root->right, key);
		}
		// if key is same as root's key, then This is the node
		// to be deleted
		else {
			// node with only one child or no child
			if (root->left == NULL) {
				Node* temp = root->right;
				delete root;
				return temp;
			} else if (root->right == NULL) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			Node* temp = minValueNode(root->right);
			// Copy the inorder successor's content to this node
			root->key = temp->key;
			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
		return root;
	}

	// Inorder traversal function.
	// This gives data in sorted order.
	void inOrder(Node *root) {
		if (root != NULL)
		{
			inOrder(root->left);
			cout << root->key << " ";
			inOrder(root->right);
		}
	}

	// Preorder traversal function.
	void preOrder(Node* root) {
		if (root != NULL) {
			cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	// Postorder traversal function.
	void postOrder(Node* root) {
		if (root != NULL) {
			postOrder(root->left);
			postOrder(root->right);
			cout << root->key << " ";
		}
	}

	void levelOrder(Node* root) {
		if (root == NULL)
			return;

		// Create an empty queue for
		// level order tarversal
		queue<Node*> nodeQueue;

		// to store front element of
		// queue.
		Node* current;
		// Enqueue Root and NULL node.
		nodeQueue.push(root);
		nodeQueue.push(NULL);

		while (nodeQueue.size() > 1) {
			current = nodeQueue.front();
			nodeQueue.pop();
			// condition to check
			// occurrence of next
			// level.
			if (current == NULL) {
				nodeQueue.push(NULL);
				cout << endl;
			} else {
				// pushing left child of
				// current node.
				if (current->left)
					nodeQueue.push(current->left);
				// pushing right child of
				// current node.
				if (current->right)
					nodeQueue.push(current->right);

				cout << current -> key << " ";
			}
		}
	}

	bool search(Node* root, int key) {
		// Base Cases: root is null
		if (root == NULL)
			return false;
		//key is present at root
		if (root->key == key)
			return true;
		// Key is greater than root's key
		if (root->key < key)
			return search(root->right, key);
		// Key is smaller than root's key
		return search(root->left, key);
	}

	int height(Node* root) {
		if (root == NULL)
			return 0;
		else {
			/* compute the depth of each subtree */
			int leftHeight = height(root->left);
			int rightHeight = height(root->right);
			/* use the larger one */
			if (leftHeight > rightHeight)
				return (leftHeight + 1);
			else
				return (rightHeight + 1);
		}
	}
	// Function to check if a binary tree is a BST. Note that this
	// code allows for duplicate keys.
	bool isBST(Node* root, int min, int max) {
		// Base case. An empty tree is a BST.
		if (root == NULL)
			return true;
		// Checking if a key is outside the permitted range.
		if (root->key < min || root->key > max)
			return false;
		// Sending in updates ranges to the right and left subtree
		return isBST(root->right, root->key, max) && isBST(root->left, min, root->key);
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Tree BST(50);
	BST.insertNode(BST.getRoot(), 30);
	BST.insertNode(BST.getRoot(), 20);
	BST.insertNode(BST.getRoot(), 40);
	BST.insertNode(BST.getRoot(), 70);
	BST.insertNode(BST.getRoot(), 60);
	BST.insertNode(BST.getRoot(), 80);

	BST.inOrder(BST.getRoot());

	cout << endl;

	BST.deleteNode(BST.getRoot(), 40);
	BST.inOrder(BST.getRoot());
	cout  << endl;
	BST.levelOrder(BST.getRoot());
	cout  << endl;
	BST.preOrder(BST.getRoot());
	cout  << endl;
	BST.postOrder(BST.getRoot());
	cout << endl;
	int min = numeric_limits<int>::min();
	int max = numeric_limits<int>::max();
	cout << BST.isBST(BST.getRoot(), min, max) << endl;
	return 0;
}