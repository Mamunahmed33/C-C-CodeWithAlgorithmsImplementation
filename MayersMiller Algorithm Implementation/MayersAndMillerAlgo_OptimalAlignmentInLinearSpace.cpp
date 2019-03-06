#include<iostream>
#include<string>
#include<fstream>

using namespace std;

float CC[], DD[], RR[], SS[];

diff(){

}

main(){

    ifstream fin;
    fin.open("Input_Strings.txt");
    string line, A, B;

    if(fin.is_open())
    {
        /*
        while ( getline (fin,line) )
        {
          A = line;
        }
        */
        getline(fin,A);
        getline(fin,B);

        cout<<A <<"\n" <<B;

        fin.close();
    }

    return 0;
}
