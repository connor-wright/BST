#pragma once
#include "BST.h"
#include <fstream>

using std::fstream;

class DataAnalysis {

public:

	//constructor
	DataAnalysis() {

		mTreeSold;
		mTreePurchased;
		open_data();
	}
	void runAnalysis();

private:

	//data members
	BST mTreeSold;
	BST mTreePurchased;
	fstream mCsvStream;

	//private functions
	void open_data();
	void read_line(int &units,string &data,string& transaction);
	void read_data();
	void sort_data(int &units, string &data,string &transaction);
	void print_data();
};