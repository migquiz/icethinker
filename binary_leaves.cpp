//Find the no. of leaves in a binary tree
#include <iostream>
using namespace std;

class binary_tree {
public:
	int count_leaves ();
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

	//root node in the tree
	return 0;
}