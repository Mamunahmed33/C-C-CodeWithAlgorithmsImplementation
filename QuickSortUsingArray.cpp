#include<iostream>

using namespace std;

int sort(int a[], int beg, int end, int loc);
void mainFunction(int a[], int N);

int main()
{
	int input, i, N;

	cin>>N;
	int a[N];

	for(i = 0; i<N; i++)
	{
		cin>>input;
		a[i] = input;
	}
	
	mainFunction(a, N);
	
	return 0;
}


int sort(int a[], int beg, int end, int loc)
{
	int left = beg, right = end;

	while(1)
    {
        while(a[loc]<=a[right]&& loc != right )
            right--;

        if(loc == right)
            return right;

        if(a[loc] > a[right])
        {
            int temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
        }

        while(a[left] <= a[loc] && left != loc)
            left++;

        if(loc == left)
            return loc;

        if(a[left] > a[loc])
        {
            int temp = a[loc];
            a[loc] = a[left];
            a[left] = temp;
            loc = left;
        }
    }
}


void mainFunction(int a[], int N)
{
   int final  = sort( a , 0 , N-1, 0);
   int final1 = sort( a , 0, final--, 0);
   int final2 = sort( a , final+2, N-1, final+2);
   int final3 = sort( a , final+2, final2-1, final+2);	int final4 = sort( a , final3+1, final2-1, final3+1);

	for(int i=0;i<12;i++)
		cout<<a[i]<<endl;
}