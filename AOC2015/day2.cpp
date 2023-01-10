# include <iostream>
# include <string>
# include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

int main(){

	std::ifstream file ("input2.txt");
	std::string line;	// line of the file
	std::size_t pos = 0;	// position read in line
	int size_tot = 0;	// total surface of paper (part 1 solution)
	int length_tot = 0; 	// total length of ribbon (part 2 solution)
	int iFaceSurface; 	// each packet face surface
	int iPacketSurface; 	// each packet total surface
	int iRibbonLength; 	// each packe ribbon length
	std::string sdim;	// each dimension of the box in string
	int dim; 		// each dimension of the box
	int V; 			// volume of each box
	if( file.is_open() ) {
		
		while (std::getline(file, line)) {

			std::vector<int> dims; // dims =  {l, w, h}
			
			// lines recovery
			while (( pos = line.find('x')) != std::string::npos) {
				// line = yyxzzxww
				sdim = line.substr(0,pos);	// sdim = yy
				std::stringstream ss(sdim);
				ss >> dim;
				dims.push_back(dim);
				line.erase(0, pos + 1);		// erases yyx
			}
			// line = ww
			// converting string to int
			std::stringstream ss(line);
                        ss >> dim;
			dims.push_back(dim);

			// surface and length calculations
			iPacketSurface = 0;
			int lmin = 2000000;
			int smin = 2000000;
			
			for (int i = 0; i < dims.size()-1; i++) {
				for (int j = i+1; j < dims.size(); j++){
					iFaceSurface = dims[i]*dims[j]; // face surf
					iRibbonLength = dims[i] + dims[j]; // face perimeter
					smin = std::min(iFaceSurface,smin);
					lmin = std::min(iRibbonLength,lmin);
			 		iPacketSurface += 2*iFaceSurface;
				}
				V = dims[0]*dims[1]*dims[2]; // volume of the packet
			}
			length_tot += 2*lmin + V;
			size_tot += iPacketSurface + smin;
		}
		std::cout << "Part 1: " << size_tot << "\n";	
		std::cout << "Part 2: " << length_tot << "\n";
	}
	return 0;
}
