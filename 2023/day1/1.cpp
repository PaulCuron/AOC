#include "..\..\filereader.h"


const char *ONE = "one", *TWO = "two", *THREE = "three", *FOUR = "four", *FIVE = "five", *SIX = "six", *SEVEN = "seven", *EIGHT = "eight", *NINE = "nine";


int main(){
    

    int s = 0;
    int n = 0, r = 0;
    int i = 0;
    bool firstfound = false;
    ifstream input("input.txt");
    for (string line; getline(input, line);)
    {
        n = 0;
        r = 0;
        i = 0;
        firstfound = true;
        for (string::iterator it=line.begin(); it!=line.end(); ++it)
        {   
            if (line.substr(i, 3).find(ONE)!=std::string::npos){
                if (firstfound){
                    n = 1;
                    firstfound = false;
                }
                r = 1;
            }
            if (line.substr(i, 3).find(TWO)!=std::string::npos){
                if (firstfound){
                    n = 2;
                    firstfound = false;
                }
                r = 2;
            }
            if (line.substr(i, 5).find(THREE)!=std::string::npos){
                if (firstfound){
                    n = 3;
                    firstfound = false;
                }
                r = 3;
            }
            if (line.substr(i, 4).find(FOUR)!=std::string::npos){
                if (firstfound){
                    n = 4;
                    firstfound = false;
                }
                r = 4;
            }
            if (line.substr(i, 4).find(FIVE)!=std::string::npos){
                if (firstfound){
                    n = 5;
                    firstfound = false;
                }
                r = 5;
            }
            if (line.substr(i, 3).find(SIX)!=std::string::npos){
                if (firstfound){
                    n = 6;
                    firstfound = false;
                }
                r = 6;
            }
            if (line.substr(i, 5).find(SEVEN)!=std::string::npos){
                if (firstfound){
                    n = 7;
                    firstfound = false;
                }
                r = 7;
            }
            if (line.substr(i, 5).find(EIGHT)!=std::string::npos){
                if (firstfound){
                    n = 8;
                    firstfound = false;
                }
                r = 8;
            }
            if (line.substr(i, 4).find(NINE)!=std::string::npos){
                if (firstfound){
                    n = 9;
                    firstfound = false;
                }

                r = 9;
            }
            if (isdigit(*it)){
                if (firstfound){
                    n = ((int) *it) - 48;
                    firstfound = false;
                }

                r = (int) *it - 48;
            }
            i ++;

        }
        n = 10*(n) + r;
        cout << n << endl;
        s = s + n;
    }
    cout << s << endl;




    return 0;
}