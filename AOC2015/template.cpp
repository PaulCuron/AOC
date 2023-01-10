# include <iostream>
# include <string>
# include <fstream>

int main(){

	std::ifstream file ("input2.txt");
	std::string str;
	if( file.is_open() ) {
		file >> str;
		
	}
	return 0;
}
