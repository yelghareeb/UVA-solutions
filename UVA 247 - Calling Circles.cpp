#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <stack>
using namespace std;
 
map<string,int> mp;
map<int,string> rmp;
 
vector<int> dfs_num, dfs_low, visited;
vector<vector<int> > adj;
vector<vector<int> > To_print;

int dfs_number_counter, num_scc;
stack<int> S;

const int DFS_WHITE = -1;
 
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
		vector<int> to_print;
		int v = S.top();
		S.pop();
		visited[v] = 0;
		to_print.push_back(v);
		
 
		while (i!=v) {
			v = S.top();
			S.pop();
			visited[v] = 0;
			to_print.push_back(v);
		}
		To_print.push_back (to_print);
	}
}
 
int main() { 
	// your code goes here
	int n,m,tt=1;
	bool first = true;
	while (cin>>n>>m) {
		if (n==0 && m==0) break;
		if (!first) printf ("\n");
		first = false;
 
		printf ("Calling circles for data set %d:\n", tt++);
		int count = 0;
		string f,t;
		
		To_print.clear();
		mp.clear();
		rmp.clear();
		adj.clear();
		adj.resize(n);
		
		for (int i=0;i<m;i++) {
			cin>>f>>t;
			int n1, n2;
			if (mp.find(f)==mp.end()) mp[f]=count++;
			if (mp.find(t)==mp.end()) mp[t]=count++;
			n1=mp[f];	n2=mp[t];
			rmp[n1] = f;	rmp[n2] = t;
			adj[n1].push_back(n2);
		}
 
		//DO Tarjan
		dfs_num.assign (n, DFS_WHITE);
		dfs_low.assign (n, 0);
		visited.assign (n,0);
		dfs_number_counter = num_scc = 0;
		for (int i=0;i<n;i++) {
			if (dfs_num[i]==DFS_WHITE) tarjan_scc(i);
		}
		for (int i=To_print.size()-1;i>=0;i--) {
			vector<int> to_print = To_print[i];
			printf ("%s", &rmp[to_print[to_print.size()-1]][0]);
			for (int k=to_print.size()-2;k>=0;k--)printf (", %s", &rmp[to_print[k]][0]); 
			printf ("\n");
		}
	}
	return 0;
}