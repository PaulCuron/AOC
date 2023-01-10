# include <iostream>
# include <string>
# include <fstream>

int main(){

	std::ifstream file ("input3.txt");
	std::string str;
	if( file.is_open() ) {
		file >> str;
		for(char c : str){
			std::cout << c << "\n";
		}
		
	}
	return 0;
}
