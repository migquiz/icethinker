//Find the no. of leaves in a binary tree
#include <iostream>
#include <stack>
using namespace std;

class binary_tree {
public:
	binary_tree ();
	int count_leaves ();
	int stackBasedCountLeaves ();
private:
	
	struct binary_tree_node {
		int data;
		binary_tree_node * left;
		binary_tree_node * right;
	};

	typedef binary_tree_node * treePtr;
	treePtr _root;
	int _count_leaves(treePtr _root);

};

binary_tree::binary_tree() {
	_root = NULL;
}

int binary_tree::_count_leaves (treePtr _root) {
	if (_root == NULL) {
		return 0;
	}
	if (_root->right == NULL && _root->left == NULL) {
		return 1;
	}
	int left_count = _count_leaves(_root->left);
	int right_count = _count_leaves(_root->right);
	return left_count + right_count;
}

int binary_tree::count_leaves () {
	return _count_leaves(_root);
}

int binary_tree::stackBasedCountLeaves () {
	if (_root == NULL) return 0;
	int leafCount = 0;
	stack<binary_tree_node *> nodes; // a stack of binary node pointers
	nodes.push(_root);
	while (!nodes.empty()) {
		//pass a copy of the node from the stack
		treePtr currentNode = nodes.top(); //get the value (address) of the topmost layer in the stack
		nodes.pop(); //pop or remove that pointer on the stack //
		if (currentNode->left == NULL && currentNode->right == NULL)
			leafCount++; //a leaf has no branches , right? yes.
		else {
			if (currentNode->right != NULL) nodes.push(currentNode->right);
			if (currentNode->left != NULL) nodes.push(currentNode->left);
		}
	}
	return leafCount;
}
	
/*
int indie_count_leaves(treePtr rootPtr) {
	if (rootPtr == NULL) {
		return 0;
	}
	if (rootPtr->right == NULL && rootPtr->left == NULL) {
		return 1;
	}
	int left_count = indie_count_leaves(rootPtr->left);
	int right_count = indie_count_leaves(rootPtr->right);
	return left_count + right_count;
}
*/
int main (int argc, char ** argv) {

	//instantiate an object for the binary tree class
	binary_tree bin_tree;
	cout << bin_tree.count_leaves() << endl;

	//root node in the tree
	return 0;
}