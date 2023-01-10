# include <iostream>
# include <string>
# include <fstream>
#include <set>
#include <vector>

int main(){

	std::ifstream file ("input3.txt");
	std::string str;
	std::set<std::vector<int>> visited1;
	std::set<std::vector<int>> visited2;
	std::vector<int> pos1;
	std::vector<int> pos2;
	int x_pos = 0;
	int y_pos = 0;
	int x_santa = 0;
	int y_santa = 0;
	int x_robo = 0;
	int y_robo = 0;
	int i = 0;
	pos1 = {x_pos,y_pos};
	visited1.insert(pos1);
	visited2.insert(pos1);
	if( file.is_open() ) {
		file >> str;
		for(char c : str) {
			switch(c){
				case '>':
					x_pos += 1;
					x_santa += 1 - i%2;
					x_robo += i%2;
					break;
				case '<':
					x_pos -= 1;
					x_santa -= 1 - i%2;
					x_robo -= i%2;
					break;
				case '^':
					y_pos += 1;
					y_santa += 1 - i%2;
					y_robo += i%2;
					break;
				case 'v':
					y_pos -= 1;
					y_santa -= 1 - i%2;
					y_robo -= i%2;
					break;
			}
			pos1 = {x_pos, y_pos};
			pos2 = {i%2*x_santa + (1-i%2)*x_robo, i%2*y_santa + (1-i%2)*y_robo};
			i += 1;
			visited1.insert(pos1);
			visited2.insert(pos2);		
		}
		std::cout << i << "\n";
		std::cout << "Part 1: " << visited1.size() << "\n";
		std::cout << "Part 2: " << visited2.size() << "\n";
	}
	return 0;
}
