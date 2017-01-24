#pragma once

#include"TransactionNode.h"

class BST {

public:

	//constructor
	BST();

	//destructor
	~BST();

	//setter
	void set_pRoot(Node *new_root);

	//getter
	Node* &get_pRoot();

	//other functions
	void insert(int units, string data);
	void inOrderTraversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();

private:
	//data members
	Node* mpRoot;

	//functions
	void destroyTree(Node *& curr_node);
	void insert(Node *&curr_node, int units, string data);
	void inOrderTraversal(Node *curr_node);
};
