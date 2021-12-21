#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

void do_print(map<int,uint64_t>& m){
	uint64_t total=0;
	for(int i=0;i<=8;i++){
		total+=m[i];
	}

	cout << total <<" fishes"<<endl;
}

void do_iteration(map<int,uint64_t>& m){
	uint64_t tmp;

	tmp=m[0];
	for(int i=0;i<=8;i++){
		m[i]=m[i+1];
	}
	m[6]+=tmp;
	m[8]+=tmp;
}


int main(int argc, char** argv){
	string str, sb_str;
	size_t c_pos=0, n_pos=0;
	map<int, uint64_t> mp;
	int n_days, total, i;

	if(argc!=3){
		cout << "bad args!"<< endl;
		exit(1);
	}

	mp[0]=mp[1]=mp[2]=mp[3]=mp[4]=mp[5]=mp[6]=mp[7]=mp[8]=0;

	str=string(argv[1]);
	n_days=atoi(argv[2]);

	do{
		n_pos=str.find(',',c_pos);
		sb_str=str.substr(c_pos, n_pos-c_pos);
		mp[stoi(sb_str)]++;
		c_pos=n_pos+1;
	} while (n_pos!=string::npos);
	
	do_print(mp);

	for(int i=1;i<=n_days;i++){
		do_iteration(mp);
				cout << endl;
		do_print(mp);
	}

	
}