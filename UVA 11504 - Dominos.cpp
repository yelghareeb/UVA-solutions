#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <stack>
using namespace std;

vector<int> dfs_num, dfs_low, visited;
vector<vector<int> > adj, new_adj;
int dfs_number_counter, num_scc;
stack<int> S;

const int DFS_WHITE = -1;
map<int,int> new_mp;

void tarjan_scc (int i) {
	dfs_num[i] = dfs_low[i] = dfs_number_counter++;
	visited[i]=1;
	S.push(i);
 
	for (int j=0;j<adj[i].size();j++) {
		int v = adj[i][j];
		if (dfs_num[v]==DFS_WHITE) tarjan_scc (adj[i][j]);
		if (visited[v]) dfs_low[i] = min (dfs_low[i], dfs_low[v]);
	}
	
	if (dfs_low[i]==dfs_num[i]) {
		int v = S.top();
		S.pop();
		visited[v] = 0;
 		new_mp [v] = num_scc;
		while (i!=v) {
			v = S.top();
			S.pop();
			visited[v] = 0;
			new_mp[v] = num_scc;
		}
		num_scc++;
	}
}
int main() {
	// your code goes here
	int n,m,tt,f,t;
	cin>>tt;
	for (int x=0;x<tt;x++) {
		cin>>n>>m;
		adj.clear();
		adj.resize(n);
		new_mp.clear();
		
		for (int i=0;i<m;i++) {
			cin>>f>>t;
			adj[f-1].push_back(t-1);
		}
		
		//Tarjan
		dfs_num.assign (n, DFS_WHITE);
		dfs_low.assign (n, 0);
		visited.assign (n,0);
		dfs_number_counter = num_scc = 0;
		for (int i=0;i<n;i++) {
			if (dfs_num[i]==DFS_WHITE) tarjan_scc(i);
		}
	//	printf ("num_scc = %d\n", num_scc);
		new_adj.clear();
		new_adj.resize(num_scc);
		for (int i=0;i<n;i++) {
			for (int j=0;j<adj[i].size();j++) {
				if (new_mp[i]!=new_mp[adj[i][j]])
					new_adj[new_mp[i]].push_back (new_mp[adj[i][j]]);
			}
		}
		
		//printf new_adj
	/*	for (int i=0;i<num_scc;i++) {
			printf ("i: %d\n\t", i);
			for (int j=0;j<new_adj[i].size();j++) {
				printf ("%d ", new_adj[i][j]);
			}
			printf ("\n");
		} */
		vector<int> indegree (num_scc, 0); //all true
		for (int i=0;i<num_scc;i++) {
			for (int j=0;j<new_adj[i].size();j++) {
				indegree [new_adj[i][j]] = 1;
			}
		}
		int ret = 0;
		for (int i=0;i<num_scc;i++) if(indegree[i]==0) ret++;
		printf ("%d\n", ret);
	}
	
	return 0;
}