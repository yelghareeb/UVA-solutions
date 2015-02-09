#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int DFS_WHITE = -1;

int dfs_number_counter, root_children, dfs_root;
vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
vector<vector<int> > adj;

void articulation_point_and_bridge (int u) {
	dfs_low[u] = dfs_num[u] = dfs_number_counter++;
	for (int j=0;j<adj[u].size();j++) {
		int v = adj[u][j];
		if (dfs_num[v]==DFS_WHITE) {
			dfs_parent [v] = u;
			if (u==dfs_root) root_children++;
			
			articulation_point_and_bridge (v);
			
			if (dfs_low[v]>=dfs_num[u]) articulation_vertex[u] = 1;
			dfs_low[u] = min (dfs_low[u], dfs_low[v]);
		}
		else if (v!=dfs_parent[u]) {
			dfs_low[u] = min (dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	// your code goes here
	int n;
	string s;
	while (cin>>n && n) {
		adj.clear();
		adj.resize(n);
		getline (cin, s);
		int f,t;
		while (getline (cin, s)) {
			istringstream is (s);
			if (is>>f && !f) break;
			while (is>>t) {
				adj[f-1].push_back(t-1);
				adj[t-1].push_back(f-1);
			}
		}
		//Finding articulation points
		dfs_number_counter = 0;
		dfs_num.assign (n, DFS_WHITE);
		dfs_low.assign (n, 0);
		dfs_parent.assign (n, 0);
		articulation_vertex.assign (n, 0);
		for (int i=0;i<n;i++) {
			if (dfs_num[i]==DFS_WHITE) { //Unvisited
				dfs_root = i;
				root_children = 0;
				articulation_point_and_bridge(i);
				articulation_vertex[dfs_root] = (root_children > 1);
			}
		}
		int ret = 0;
		for (int i=0;i<n;i++) if (articulation_vertex[i]) ret++; 
		cout<<ret<<endl;
	}
	return 0;
}