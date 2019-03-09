#include<iostream>
#include<string>
#include<fstream>

using namespace std;

float *CC, *DD, *RR, *SS;
float t = 0;

diff(string A, string B, int M, int N, int tb, int te){
    if(N == 0){
        if(M > 0){
            //write delete A
        }
        else if(M == 0){
            //insert B
        }
        else if( M == 1){
            float firstMin = 0, secondMin=0;
            if(tb < te){
                firstMin = tb;
            }
            else{
                firstMin = te;
            }
            firstMin += g + h * N;
            
        }
        else{
            int i = M/2;
            t = tb;

        }
    }

}

float calculateMin(){
    
}

main(){

    ifstream fin;
    fin.open("Input_Strings.txt");
    string line, A, B;

    if(fin.is_open())
    {
        getline(fin,A);
        getline(fin,B);

        cout<<A <<"\n" <<B;

        fin.close();
    }

    int aLength = A.length(), bLength = B.length();
    int g = 2;

    CC = new float[aLength];
    DD = new float[aLength];
    RR = new float[bLength];
    SS = new float[bLength];

    diff(A, B, aLength, bLength, g, g);

    return 0;
}
