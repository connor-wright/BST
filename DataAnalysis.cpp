#include "DataAnalysis.h"

//public function/////////////////////////////////////////////////
void DataAnalysis::runAnalysis() {

	read_data();
	print_data();
}

//private functions////////////////////////////////////////////////

void DataAnalysis::open_data() {

	this->mCsvStream.open("data.csv", fstream::in);
}

void DataAnalysis::read_line(int &units, string &data, string& transaction) {

	char temp[100] = "";
	string s_temp = "";
	this->mCsvStream.getline(temp, 100, ',');
	s_temp = temp;
	//if its the first line
	if (s_temp == "Units") {
		this->mCsvStream.getline(temp, 100,'\n');
	}
	else if (!this->mCsvStream.eof()) {
		units = atoi(temp);
		this->mCsvStream.getline(temp, 100, ',');
		data = temp;
		this->mCsvStream.getline(temp, 100, '\n');
		transaction = temp;
	}
}

void DataAnalysis::read_data() {

	int units = 0;
	string data = "";
	string transaction = "";

	while (!this->mCsvStream.eof()) {
		units = 0;
		data = "";
		transaction = "";
		read_line(units,data,transaction);
		sort_data(units,data,transaction);
	}

	cout << "\tSold" <<endl<<"--------------------"<< endl;
	this->mTreeSold.inOrderTraversal();
	cout << endl;
	cout <<"      Purchased" <<endl<<"--------------------" <<endl;
	this->mTreePurchased.inOrderTraversal();
	cout << endl;
}

void DataAnalysis::sort_data(int &units, string &data, string &transaction) {

	if (transaction == "Purchased")
		this->mTreePurchased.insert(units, data);
	else if (transaction == "Sold")
		this->mTreeSold.insert(units, data);
}

void DataAnalysis::print_data() {

	cout << "Sold most: "<<endl;
	this->mTreeSold.findLargest().printData();
	cout <<endl<< "Sold least: "<<endl;
	this->mTreeSold.findSmallest().printData();
	cout << endl << "Purchased most: "<<endl;
	this->mTreePurchased.findLargest().printData();
	cout << endl << "Purchased least: "<<endl;
	this->mTreePurchased.findSmallest().printData();
}