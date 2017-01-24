#include "BST.h"
#include "TransactionNode.h"


//constructor
BST::BST() {
	
	this->mpRoot = nullptr;
}

//destructor
BST::~BST() {

	destroyTree(mpRoot);
}

//setter
void BST::set_pRoot(Node *new_root) {

	mpRoot = new_root;
}

//getter
Node* &BST::get_pRoot() {

	return mpRoot;
}

//other functions
void BST::insert(int units, string data) {

	insert(mpRoot, units, data);
}

void BST::inOrderTraversal() {

	inOrderTraversal(mpRoot);
}

//goes the furthest left on the tree
TransactionNode & BST::findSmallest() {

	Node* p_temp = mpRoot;
	while (p_temp->get_pLeft() != nullptr) {
		p_temp = p_temp->get_pLeft();
	}
	//transforms p_temp to a transaction node pointer type and dereferences it so we can return a referece
	//ok to return reference because the tree exists outside of the scope of this function
	return *(dynamic_cast<TransactionNode *>(p_temp));
}

//goes the furthest right on the tree
TransactionNode & BST::findLargest() {

	Node* p_temp = mpRoot;
	while (p_temp->get_pRight() != nullptr) {
		p_temp = p_temp->get_pRight();
	}
	return *(dynamic_cast<TransactionNode *>(p_temp));
}

//private functions
void BST::destroyTree(Node *& curr_node) {

	if (curr_node != nullptr) {
		destroyTree(curr_node->get_pLeft());
		destroyTree(curr_node->get_pRight());
		delete curr_node;
	}
}

void BST::insert(Node *&curr_node,int units,string data) {

	//reusing code from pa6/////////////////////////////////////////////////
	if (curr_node == nullptr) {
		curr_node = new TransactionNode(data,units);
	}
	//go left
	else if (units<(dynamic_cast<TransactionNode*>(curr_node))->get_units()) {
		insert(curr_node->get_pLeft(), units, data);
	}
	//go right
	else if (units>(dynamic_cast<TransactionNode*>(curr_node))->get_units()) {
		insert(curr_node->get_pRight(), units, data);
	}
	//find copy (should no happen)
	else if (units == (dynamic_cast<TransactionNode*>(curr_node))->get_units()) {
		cout << "we have a copy" << endl;
	}
	//if we hit this something is seriously wrong
	else {
		cout << "fix your code!" << endl;
	}
}

void BST::inOrderTraversal(Node *curr_node) {

	if (curr_node!= nullptr) {

		inOrderTraversal(curr_node->get_pLeft());
		curr_node->printData();
		inOrderTraversal(curr_node->get_pRight());
	}
}