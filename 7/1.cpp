#include <iostream>
#include <fstream>
#include <map>
#include <math.h>

using namespace std;

int main(void){
	string str;
	ifstream inpt_file("input");
	map<uint64_t,uint64_t> mp;
	size_t c_pos, n_pos;
	uint64_t key;
	double total=0, tmp, best_align;

	//read

	while (getline(inpt_file, str)) {
		n_pos=c_pos=0;
		do {
			n_pos=str.find(",", c_pos);
			key=stoul(str.substr(c_pos, n_pos-c_pos));
			cout << "got " << key << endl;
			if(mp.find(key)!=mp.end())
				mp[key]+=1;
			else
				mp[key]=1;
			c_pos=n_pos+1;
			total++;
		} while (n_pos!=string::npos);
	}

	//print

	for(map<uint64_t,uint64_t>::iterator it=mp.begin();it!=mp.end();it++){
		cout << it->first << " -- " << it->second <<endl;
	}
	cout << "total "<< total << endl;

	tmp=0;
	for(map<uint64_t,uint64_t>::iterator it=mp.begin();it!=mp.end();it++){
		if(tmp+it->second > round(total/2)){
			best_align=it->first;
			break;
		}
		tmp+=it->second;
	}




	uint64_t fuel=0;
	for(map<uint64_t,uint64_t>::iterator it=mp.begin();it!=mp.end();it++){
		fuel+=abs(it->first-best_align)*it->second;
	}

	cout << "Best align " <<best_align <<" using " << fuel << " fuel"<<endl;

}