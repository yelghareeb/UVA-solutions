#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define PII pair<int,int>
#define vi vector<int>

vi pset;
void init_set (int n) {
	pset.assign (n,0);
	for (int i=0;i<n;i++) pset[i] = i;
}

int find_set (int i) { return (pset[i]==i)? i: pset[i]=find_set(pset[i]);	}
bool is_same_set (int i, int j) {return find_set(i) == find_set(j);	}
void union_set (int i, int j) { pset[find_set(i)] = find_set(j); }

vector<PII> points;
vector<vector<int> > grid;
int visited [205], tt=1;

double dist (int i, int j) {
	PII p1 = points[i], p2 = points[j];
	return sqrt ((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

void dfs (int i, double& maxim) {
	if (visited[i]) return;
	if (i==1) {
		printf ("Scenario #%d\nFrog Distance = %.3f\n", tt++, maxim);
		return;
	}
	visited[i] = 1;
	
	for (int j=0;j<grid[i].size();j++) {
		double maxim2 = max (maxim, dist(i,grid[i][j]));
		dfs (grid[i][j], maxim2);
	}
}

int main() {
	// your code goes here
	int n,x,y;
	while (cin>>n && n) {
		points.clear();
		points.resize(n);
		memset (visited,0,sizeof(visited));
		
		for (int i=0;i<n;i++) {
			cin>>x>>y;
			points[i] = make_pair(x,y);
		}
		
		vector<pair<double, PII> > edge_list;
		for (int i=0;i<n;i++) {
			for (int j=i+1;j<n;j++) {
				edge_list.push_back (make_pair(dist(i, j), PII(i,j)));
			}
		}
		sort (edge_list.begin(), edge_list.end());
		int E = edge_list.size();
	//	for (int i=0;i<E;i++) printf ("%f %d %d\n", edge_list[i].first, edge_list[i].second.first, edge_list[i].second.second);
	
		init_set (n);
		grid.clear();
		grid.resize(n);
		
		for (int i=0;i<E;i++) {
			pair<int,PII> front = edge_list[i];
			if (!is_same_set(front.second.first, front.second.second)) {
				int f = front.second.first, s= front.second.second;
				union_set (f, s);
				grid [f].push_back(s);
				grid [s].push_back(f);
		//		printf ("connect %d %d\n", f, s);
			}
		}
	//	for (int i=0;i<n;i++) printf ("%d %d\n", i, grid[i][0]);
	//	printf ("%f\n", dist(0,1));
		double maxim = 0;
		dfs (0, maxim);
		printf ("\n");
	}
	return 0;
}