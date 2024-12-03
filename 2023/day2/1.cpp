#include "..\..\filereader.h"

int Nred = 12, Ngreen = 13, Nblue = 14;
const string G = "green", R = "red", B = "blue";
bool isValid(string line)
{   
    bool isValid = true;
    bool end = false;
    int s = line.find(':');
    int len = line.substr(s+1).find(';');
    string draw;
    int nblue = 0, nred = 0, ngreen = 0;
    int ds;
    
    string game;
    while(true){
        game = line.substr(s+1, len);
        //cout << game << endl;
        ds = 1;

        while(ds>0){
            ds = game.find(',');

            draw = game.substr(0, ds);

            draw.find(B)!=draw.npos ? nblue = stoi(draw.substr(0,draw.find(B))):true;
            draw.find(G)!=draw.npos? ngreen = stoi(draw.substr(0,draw.find(G))):true;
            draw.find(R)!=draw.npos?nred = stoi(draw.substr(0,draw.find(R))):true;

            game = game.substr(ds+1);
        }

        if (nblue > Nblue || ngreen > Ngreen || nred > Nred){
            isValid = false;
            end = true;
        }

        if (end){break;}

        s = s+len+1;
        len = line.substr(s+1).find(';');
        if (len < 0){
            len = line.substr(s+1).length();
            end =true;
        }
    }
    return isValid;
}


int gamePower(string line)
{   
    bool end = false;
    int s = line.find(':');
    int len = line.substr(s+1).find(';');
    string draw;
    int nblue = 0, nred = 0, ngreen = 0;
    int mBlue = 0, mRed = 0, mGreen = 0;
    int ds;
    
    string game;
    while(true){
        game = line.substr(s+1, len);
        //cout << game << endl;
        ds = 1;

        while(ds>0){
            ds = game.find(',');

            draw = game.substr(0, ds);

            draw.find(B)!=draw.npos ? nblue = stoi(draw.substr(0,draw.find(B))):true;
            draw.find(G)!=draw.npos? ngreen = stoi(draw.substr(0,draw.find(G))):true;
            draw.find(R)!=draw.npos?nred = stoi(draw.substr(0,draw.find(R))):true;

            
            game = game.substr(ds+1);
        }

        nblue > mBlue? mBlue=nblue:true;
        nred > mRed?mRed = nred: true;
        ngreen > mGreen?mGreen = ngreen:true;


        if (end){break;}
        s = s+len+1;
        len = line.substr(s+1).find(';');
        if (len < 0){
            len = line.substr(s+1).length();
            end =true;
        }
    }
    return mBlue*mRed*mGreen;
}


int main(){
    

    int validgames = 0;
    int powers = 0;
    int id;
    string gameID;
    ifstream input("input.txt");
    for (string line; getline(input, line);)
    {
        int len = line.find(":") - 4;
        gameID = line.substr(5,len);
        id = stoi(gameID);
        isValid(line)?validgames = validgames + id:true;

        powers = powers + gamePower(line);
    }

    cout << validgames << endl;
    cout << powers << endl;
    return 0;
}