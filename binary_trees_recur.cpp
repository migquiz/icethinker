//Recursion and Binary Trees
//The basic idea of Binary Tree data structure
//it is a node which points to it's left right
//like a branch in a tree

#include <iostream>
using namespace std;

struct Tree_Node {
	int data;
	Tree_Node * left;
	Tree_Node * right;
};

typedef Tree_Node * treePtr;

//have to implement this on a non recursive way
//in a while or for loop maybe
//the thinking , apply the call to a base case
//then test to see if scalable to a larger case

int get_largest_value (treePtr root) {
	
	if (root == NULL) return 0;
	//when this is true
	if (root->right == NULL && root->left == NULL){
		return root->data;
	}
	//all functions in the stack will be popped out
	//and get the returning values
	int leftMax = get_largest_value (root->left);
	int rightMax = get_largest_value (root->right);
	int maxNum = root->data;
	if (leftMax > maxNum) maxNum = leftMax;
	if (rightMax > maxNum) maxNum = rightMax;
	return maxNum;	
}

//implementation of finding the max value in a binary
//using while construct //TO-DO
//this code is reasonable enough have to improve this later
void while_max_value (treePtr root) {
	
	if (root->right != NULL && root->left != NULL) {
		cout << root->data << endl;
	}

	//assign root to traverse the most right sub tree
	treePtr right_sub = root;
	//the other left node in the right sub tree
	treePtr lefty = NULL;

	while (right_sub->right != NULL && right_sub->left != NULL) {
		
		//to access the data in the right sub parent tree	
		right_sub = right_sub->right;
		cout << right_sub->data << endl;
		//so every left node will be traversed
		lefty = right_sub;
		while (lefty->right != NULL && lefty->left != NULL) {
			lefty = lefty->left;
			cout << lefty->data << endl;
		}
	}

	//assign root to traverse the most left sub tree
	treePtr left_sub = root;
	//the other right node in the left sub tree
	treePtr righty = NULL;
	while (left_sub->right != NULL && left_sub->left != NULL) {
		
		left_sub = left_sub->left;
		cout << left_sub->data <<endl;
		
		righty = left_sub;
		while (righty->right != NULL && righty->left != NULL) {
			righty = righty->right;
			cout << righty->data << endl;
		}
	} 
}

int main (int argc, char ** argv) {

	//root node in the tree
	Tree_Node * root_node = new Tree_Node;
	root_node->data = 1;
	root_node->left = NULL;
	root_node->right = NULL;

	//left subtree
	Tree_Node * left_sub_parent_node = new Tree_Node;
	left_sub_parent_node->data = 5;
	left_sub_parent_node->left = NULL;
	left_sub_parent_node->right = NULL;

	Tree_Node * left_one = new Tree_Node;
	left_one->data = 7;
	left_one->left = NULL;
	left_one->right = NULL;

	Tree_Node * left_two = new Tree_Node;
	left_two->data = 6;
	left_two->left = NULL;
	left_two->right = NULL;	

	Tree_Node * left_three = new Tree_Node;
	left_three->data = 9;
	left_three->left = NULL;
	left_three->right = NULL;	

	Tree_Node * left_four = new Tree_Node;
	left_four->data = 10;
	left_four->left = NULL;
	left_four->right = NULL;	

	//right subtree
	Tree_Node * right_sub_parent_node = new Tree_Node;
	right_sub_parent_node->data = 2;
	right_sub_parent_node->left = NULL;
	right_sub_parent_node->right = NULL;

	Tree_Node * right_one = new Tree_Node;
	right_one->data = 4;
	right_one->left = NULL;
	right_one->right = NULL;

	Tree_Node * right_two = new Tree_Node;
	right_two->data = 3;
	right_two->left = NULL;
	right_two->right = NULL;

	Tree_Node * right_three = new Tree_Node;
	right_three->data = 8;
	right_three->left = NULL;
	right_three->right = NULL;

	Tree_Node * right_four = new Tree_Node;
	right_four->data = 11;
	right_four->left = NULL;
	right_four->right = NULL;

	Tree_Node * right_five = new Tree_Node;
	right_five->data = 12;
	right_five->left = NULL;
	right_five->right = NULL;

	Tree_Node * right_six = new Tree_Node;
	right_six->data = 13;
	right_six->left = NULL;
	right_six->right = NULL;

	root_node->left = left_sub_parent_node;
	root_node->right = right_sub_parent_node;

	right_sub_parent_node->right = right_one;
	right_sub_parent_node->left = right_two;

	right_one->right = right_three;
	right_one->left = right_four;
	right_two->left = right_five;
	right_two->right = right_six;

	left_sub_parent_node->right = left_one;
	left_sub_parent_node->left = left_two;

	left_two->left = left_three;
	left_two->right = left_four;

	cout << "The Largest Value in The Binary Tree: " << get_largest_value (root_node) << endl;
	while_max_value (root_node);

	return 0;
}