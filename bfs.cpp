#include<iostream>
#include<queue>
#include<fstream>

using namespace std;

void print_path(int* color, int* dist, int* prev, int start_v, int qv)
{
	if(start_v == qv)
		cout << qv << endl;
	else if (prev[qv]==-1)
		cout << "No Path" << endl;
	else
	{
		print_path(color, dist, prev, start_v, prev[qv]);
		cout << qv << endl;
	}
}

int main ()//int argc, char* argv []
{
	ifstream graph("bfs.txt");
//	graph.open(argv[1]);
	if(graph.is_open())
	{
		int v_no, e_no;
		graph >> v_no >> e_no;

		int **adjacency_matrix;
		adjacency_matrix = new int* [v_no];
		for(int i=0; i<v_no; i++)
		{
			adjacency_matrix[i] = new int [v_no];
		}

		for(int i=0; i<v_no; i++)
		{
			for(int j=0; j<v_no; j++)
			{
				graph >> adjacency_matrix[i][j];
			}
		}
/*
		for(int i=0; i<v_no; i++)
		{
			for(int j=0; j<v_no; j++)
			{
				cout << adjacency_matrix[i][j] << " ";
			}
			cout << endl;
		}
*/

		//bfs

		int *color, *prev, *dist;
		color = new int [v_no];
		prev = new int [v_no];
		dist = new int [v_no];


		for(int i=0;i<v_no;i++)
		{
			color[i]=1;
			dist[i]=31216;
			prev[i] =-1;
		}

		cout << "start vertex? [0~" <<v_no-1 << "] :";
		int start_v;
		cin >> start_v;

		color[start_v]=2;
		dist[start_v]=0;
		prev[start_v] =-1;

		queue <int> bfsq;
		bfsq.push(start_v);

		while (!bfsq.empty())
		{
			int u = bfsq.front();
			bfsq.pop();

			for(int i=0; i<v_no; i++)
			{
				if(adjacency_matrix[u][i]==1)
				{ 
					int v = i;
					if(color[v]==1)
					{
						color[v] = 2;
						dist[v] = dist[u]+1;
						prev[v] = u;
						bfsq.push(v);
					}
				}
			}
			color[u] = 3;
		}
/*
		cout << endl;
		for(int i=0;i<v_no;i++)
			cout << color[i] << "\t";
		cout << endl;
		for(int i=0;i<v_no;i++)
			cout << dist[i] << "\t";
		cout << endl;
		for(int i=0;i<v_no;i++)
			cout << prev[i] << "\t";
		cout << endl;
*/
		int qv;
		cout << "What is your Quarry Vertex? ";
		cin >> qv;
		print_path(color, dist, prev, start_v, qv);

		delete [] color;
		delete [] dist;
		delete [] prev;

		for(int i=0; i<v_no; i++)
		{
			delete [] adjacency_matrix[i];
		}

		delete [] adjacency_matrix;

		graph.close();
	}

	return 0;
}
