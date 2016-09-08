#include<iostream>
#include<vector>

using namespace std;

vector<int>:: iterator quick(vector <int> myVec, vector <int>:: iterator beg, vector <int>:: iterator end, vector <int>:: iterator loc);

int main()
{
	int input, i=0, N;
    vector <int> myVec;

	cin>>N;

	for(int i = 0; i<N; i++)
	{
		cin>>input;
		myVec.push_back(input);
	}
    //vector <int>:: iterator loc = myVec.begin();

    //quick( myVec , N, myVec.begin(), myVec.end(), loc);

    vector <int>:: iterator final  =  quick( myVec , myVec.begin(), myVec.end(), myVec.begin());
    vector <int>:: iterator final1 =  quick( myVec , myVec.begin(), final--, myVec.begin());
    vector <int>:: iterator final2 =  quick( myVec , final++, myVec.end(), final++);
    vector <int>:: iterator final3 =  quick( myVec , final++, final2--, final++);
	return 0;
}


vector <int>:: iterator quick(vector <int> myVec, vector <int>:: iterator beg, vector <int>:: iterator end, vector <int>:: iterator loc)
{
	vector <int>:: iterator left = beg;
	vector <int>:: iterator right = end;
//        for(int i = 0; i<12; i++)
 //           cout<<myVec.at(i)<<endl;

	 while(1)
    {
		while(*loc<=*right && loc!= right)
			right--;

        if( loc = right)
            return right;

		if(*loc > *right)
		{
			swap(*loc, *right);
			loc = right;
		}

		while(*left <= *loc && left != loc)
            left++;

        if(loc = left)
            return left;

        if(*left > *loc)
            swap(*loc, *right);
            loc = left;
    }
}
