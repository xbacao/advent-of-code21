#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	string str;
	ifstream inpt_file("input");
	int cur;
	uint64_t total=0;
	int prevs[3];
	int i=0;

	while (getline(inpt_file, str)) {
	  cur=stoi(str);

	  if(i<3){
	  	prevs[i++]=cur;
	  	continue;
	  }

	  if(cur+prevs[2]+prevs[1]>prevs[2]+prevs[1]+prevs[0])
	  	total++;
	  
	  prevs[0]=prevs[1];
	  prevs[1]=prevs[2];
	  prevs[2]=cur;

	}

	// Close the file
	inpt_file.close();

	cout << "Total " << total <<endl; 

}