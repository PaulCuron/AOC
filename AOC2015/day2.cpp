# include <iostream>
# include <string>
# include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

int main(){

	std::ifstream file ("input2.txt");
	std::string line;
	std::size_t pos = 0;
	int size_tot = 0;
	int length_tot = 0;
	int s; // each packet face surface
	int S; // each packet total surface
	int l; // each packe ribbon length
	std::string sdim;
	int dim; // each dimension
	
	if( file.is_open() ) {
		
		while (std::getline(file, line)) {

			std::vector<int> dims; // dims =  {l, w, h}
			
			// lines recovery
			while (( pos = line.find('x')) != std::string::npos) {
				sdim = line.substr(0,pos);
				std::stringstream ss(sdim);
				ss >> dim;
				line.erase(0, pos + 1);
				dims.push_back(dim);
			}

			// converting string to int
			std::stringstream ss(line);
                        ss >> dim;
			dims.push_back(dim);


			// surface and length calculations
			S = 0;
			int lmin = 2000000;
			int smin = 2000000;
			
			for (int i = 0; i < dims.size()-1; i++) {
				for (int j = i+1; j < dims.size(); j++){
					s = dims[i]*dims[j]; // face surf
					l = dims[i] + dims[j]; // face perimeter
					smin = std::min(s,smin);
					lmin = std::min(l,lmin);
			 		S += 2*s;
				}
				int V = dims[0]*dims[1]*dims[2]; // volume of the packet
			}
			length_tot += 2*lmin + V;
			size_tot += S + smin;
		}
		std::cout << "Part 1: " << size_tot << "\n";	
		std::cout << "Part 2: " << length_tot << "\n";
	}
	return 0;
}
