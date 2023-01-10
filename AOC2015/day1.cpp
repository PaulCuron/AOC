#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream myfile ("input1.txt");
	std::string str;
	
	if ( myfile.is_open() ) { // always check whether the file is open
		myfile >> str; // pipe file's content into stream
		int floor = 0;
		bool basement = true;
		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] == ')') {
				floor--;
			}else if (str[i] == '(') {
				floor++;
			}
			if (floor == -1 && basement) {
				std::cout << "Part 2: " << i+1 << "\n";
				basement = false;			
			}
		}
		std::cout << "Part 1: " << floor << "\n";
	}
	return 0;
}
