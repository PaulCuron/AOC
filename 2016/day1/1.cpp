#include "..\..\filereader.h"


int main(){

    

    int xs = 0, ys = 0, x = 0, y = 0, dir = 1, forward = 1;
    char del = ',';
    ifstream input("input.txt");
    for (string line; getline(input, line);)
    {
        stringstream ss(line);
        string word;
        while (!ss.eof()) {
            getline(ss, word, del);

            word.erase(remove(word.begin(), word.end(), ' '), word.end());
            int dist = stoi(word.substr(1));
            if ((dir==1 && word[0]=='L')|| (dir==0 && word[0]=='R')){
                forward = (forward+1)%2;
            }
            dir = (dir + 1)%2;
            string::size_type sz;   // alias of size_t
            x = x + (1-dir)*2*(forward - 0.5)*dist;
            y = y + dir*2*(forward - 0.5)*dist;
        }
        cout << abs(x - xs) + abs(y - ys) << "\n";
        
    }
    return 0;
}