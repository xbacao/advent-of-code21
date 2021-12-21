#include <iostream>
#include <fstream>

using namespace std;

int main(void){
	string str;
	ifstream inpt_file("input");
	int prev, cur;
	uint64_t total=0;

	getline(inpt_file, str);

	prev=stoi(str);

	while (getline(inpt_file, str)) {
	  cur=stoi(str);
	  if(cur>prev){
	  	total++;
	  }
	  prev=cur;
	}

	// Close the file
	inpt_file.close();

	cout << "Total " << total <<endl; 

}