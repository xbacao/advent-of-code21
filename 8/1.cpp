#include <string>
#include <fstream>

typedef struct {
	vector<string> signal;
	vector<string> digits;
} line_info_t;

int main(void){
	ifstream ifs("input_test");
	string str;
	vector<line_info_t> lines;
	line_info_t line_tmp;

	while(getline(ifs, str)){
		
	}
}