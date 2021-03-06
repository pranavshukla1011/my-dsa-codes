


#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list <pair<int, int>> l;

public:
	Graph(int V)
	{
		v = V;
	}

	int addEdge(int u, int v)
	{
		l.push_back({u,v});
	}

	//forming dsu

	//path compression optimization
	int findSet(int i, int parent[])
	{
		if(parent[i] == -1)
			return i;
		
		return parent[i] = findSet(parent[i],parent);
	}

	//union by rank
	void union_set(int x, int y, int parent[])
	{
		int s1 = find(x,parent);
		int s2 = find(y,parent);

		if(s1!=s2)
		{
			if(rank[s1]<rank[s2])
				{
					parent[s1] = s2;
					rank[s2]+=rank[s1];
				}
			else
				{
					parent[s2] = s1;
					rank[s1]+= rank[s1];
				}
		}
	}

	bool contains_cycle()
	{
		//DSU logic to check if function contains cycle
		int *parent = new int[v+1];
		for(auto i = 0;i<=v; i++)
			parent[i] = -1;

		//as soon as two nodes belong to same set we get a cycle.
		for(auto edge:l)
		{
			int i = edge.first;
			int j = edge.second;

			int s1 = find(i,parent);
			int s2 = find(j,parent);

			if(s1!=s2)
				union_set(s1,s2,parent);
			else
				return true;
		}
		delete [] parent;
		return false;
	}
};



int main(int argc, char const *argv[])
{
	#ifdef ONLINE_JUDGE
	freopen("intput.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	#endif


	return 0;
}



