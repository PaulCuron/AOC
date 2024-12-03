#include "..\..\filereader.h"


int main(){

    int xs = 0, ys = 0, x = 0, y = 0, dir = 1, forward = 1;
    char del = ',';
    ifstream input1("input.txt");
    int nstep = 0;
    for (string line; getline(input1, line);)
    {
        stringstream ss(line);
        string word;
        while (!ss.eof()) {
            getline(ss, word, del);
            word.erase(remove(word.begin(), word.end(), ' '), word.end());

            int dist = stoi(word.substr(1));

            nstep = nstep + dist;
        }
    }
    cout << nstep<<"\n";
    int positions[nstep][2];

    int i = 0;
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
            for (int k = 0; k < dist; k ++){
                x = x + (1-dir)*2*(forward - 0.5);
                y = y + dir*2*(forward - 0.5);
                positions[i][0] = x;
                positions[i][1] = y;
                i = i + 1;
            }

        }
        
    }
    int xh, yh;
    bool found = false;
    for (int j = 1; j < nstep; j ++){
        xh = positions[j][0];
        yh = positions[j][1];
        for (int k = 0; k < j; k ++){
            if (positions[k][0]==xh && positions[k][1]==yh)
            {   
                cout << "Position " << positions[k][0] << " " <<positions[k][1] << " et " << positions[j][0] <<" "<< positions[j][1] << " matchent\n";
                cout << abs(xs - xh) + abs(ys - yh) << "\n";
                found = true;
                break;
            }
            
        }
        if (found){break;}
    }
    return 0;
}