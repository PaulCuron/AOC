#include "..\..\filereader.h"

bool isPart(int i, int j, int len, char mat[]){
    bool valid = false;
    return valid;
}




int main(){
    int sum = 0;
    ifstream input("input.txt");
    string prevline;
    int width = 0;
    int height = 0;
    int i = 0;

    for (string line; getline(input, line);)
    {
        if (!width){
            width = line.length();
            prevline = line;
        }
        height += 1;
        cout << "prev: " << prevline << endl;
        cout << "curr: " << line << endl;
        prevline = line;


    }
    char mat[height][width];
    i = 0;
    for (string line; getline(input, line);)
    {
        for (int j=0; j < width; j++){
            mat[i][j]= line[j];
        }
    }
    for (int k = 0; k <height; k++){
        for (int l = 0; l < width; l++){
            cout << *mat[k][l];
        }
        cout << endl;
    }
    
    return 0;
}