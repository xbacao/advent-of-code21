#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void do_iteration(vector<int>& v){
	int pushes_needed=0;

	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		if(!(*it)){
			*it=6;
			pushes_needed++;
		} else {
			(*it)--;
		}
	}

	for(int i=0;i<pushes_needed;i++){
		v.push_back(8);
	}
}

void print_arr(vector<int>& v, int day){
	vector<int>::iterator it;
	if(!day)
		cout << "Initial state: ";
	else{
		cout << "After "<< setw(2) << day << " "<< setw(4);
		if(day==1)
			cout<<"day";
		else
			cout << "days";
		cout << ": ";
	}

	for(it=v.begin();it!=v.end()-1;it++){
		cout << *it << ",";
	}
	cout << *it << endl; 
}

int main(int argc, char** argv){
	string str, sb_str;
	size_t c_pos=0, n_pos=0;
	vector<int> vec;
	vector<int>::iterator it;
	int n_days;

	if(argc!=3){
		cout << "bad args!"<< endl;
		exit(1);
	}

	str=string(argv[1]);
	n_days=atoi(argv[2]);

	do{
		n_pos=str.find(',',c_pos);
		sb_str=str.substr(c_pos, n_pos-c_pos);
		vec.push_back(stoi(sb_str));
		c_pos=n_pos+1;
	} while (n_pos!=string::npos);
	
	print_arr(vec, 0);
	for(int i=1;i<=n_days;i++){
		do_iteration(vec);
	  //print_arr(vec, i);
	}

	cout << vec.size() << "fishes" << endl;
}