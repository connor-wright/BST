#pragma once

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

class Node {

public:

	//constructor defined in header
	Node(const string &newData="") {

		mData = newData;
		mpLeft = nullptr;
		mpRight = nullptr;
	}

	//destructor
	~Node() {

		//not quite sure what Andy wants here?
	}

	//setters defined in header
	void set_Data(string &newData) {

		this->mData = newData;
	}
	void set_pRight(Node* new_pRight) {

		this->mpRight = new_pRight;
	}
	void set_pLeft(Node* new_pLeft) {
		
		this->mpLeft = new_pLeft;
	}

	//getters defined in the header
	string get_Data()const {

		return this->mData;
	}
	//cant make these two constant because i am returning a reference
	//reference allows me to change where the pointer is pointing to
	Node*& get_pRight() {

		return this->mpRight;
	}
	Node*& get_pLeft() {

		return this->mpLeft;
	}

	//other member functions

	//dont want to make changes here
	virtual void printData()const =0;

protected:

	string mData;
	Node *mpLeft;
	Node *mpRight;

};