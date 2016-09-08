#include<iostream>
#include<fstream>

using namespace std;

int time = 0;

void dfs(int start_v, int **adjacency_matrix, int *color, int *prev, int *dist, int *f, int v)
{
    color[start_v] = 2;
    dist[start_v] = time++;

    for(int i = 0; i< v; i++)
    {
        if(adjacency_matrix[start_v][i] == 1)
        {
            int forward = i;
            if(color[forward] == 1)
            {
                prev[forward] = start_v;
                dfs(forward, adjacency_matrix, color, prev, dist, f, v);
            }
        }
        if(i == (v-1)){
                color[start_v] = 3;
                f[start_v] = ++time;
        }
    }
}

int main(void)
{
    ifstream fin;
    fin.open("dfs.txt");

    if(fin.is_open())
    {
        int e,v;
        fin>>v>>e;

        int **adjacency_matrix;
		adjacency_matrix = new int* [v];

		for(int i=0; i<v; i++)
		{
			adjacency_matrix[i] = new int [v];
		}

		for(int i=0; i<v; i++)
		{
			for(int j=0; j<v; j++)
			{
				fin >> adjacency_matrix[i][j];
			}
		}

		for(int i=0; i<v; i++){
			for(int j=0; j<v; j++){
				cout << adjacency_matrix[i][j] << " ";
			}
			cout << endl;
		}

		int *color, *prev, *dist, *f;
		color = new int [v];
		prev = new int [v];
		dist = new int [v];
        f = new int [v];

		for(int i=0; i<v; i++){
			color[i] = 1;
			dist[i] = 31216;
			f[i] = 34231;
			prev[i] = -1;
		}

        cout << "start vertex? [0~" <<v-1 << "] :";
		int start_v;
		cin >> start_v;

        if(color[start_v]==1)
            dfs(start_v, adjacency_matrix, color, prev, dist, f, v);


        for(int i=0; i<v; i++)
            if(color[i]==1)
                dfs(i, adjacency_matrix, color, prev, dist, f, v);

		cout<<"Start Vertex: "<<start_v<<endl;
		cout<<"Final Vertex: "<<f[start_v]<<endl;

        cout<<"\t\tDistance\tPrevious\tFinal"<<endl;
        for(int i = 0; i< v; i++)
            cout<<"Vertex["<<i<<"]\t  "<<dist[i]<<"\t\t   "<<prev[i]<<"\t\t "<<f[i]<<endl;

        delete [] color;
		delete [] dist;
		delete [] prev;
		delete [] f;

		for(int i=0; i<v; i++)
		{
			delete [] adjacency_matrix[i];
		}
		delete [] adjacency_matrix;

		fin.close();
    }

    return 0;
}
