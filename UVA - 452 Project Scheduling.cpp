/*
	UVA - 452	Project Scheduling
	Category: Topological sort
	Author: Youssef ElGhareeb
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	int tt;
	bool first = true;
	cin>>tt;
	char line [2000];
	for (int k=0;k<2;k++) cin.getline(line, 2000, '\n'); //Dummy reads
	while (tt--) {
		char from;
		string deps;
		int dur, adj_mat[30][30],dist[30],in[30],ret=0,init;
		set<int> nodes;
		memset (dist,0,sizeof(dist));
		memset (in,0,sizeof(in));
		for (int i=0;i<30;i++) for (int j=0;j<30;j++) adj_mat[i][j]= -1;
		
		while (cin.getline(line, 2000, '\n')) {
			if (line[0]==0) break;
			istringstream is (line);
			is>>from>>dur>>deps;
			nodes.insert(from);
			for (int j=0;j<deps.length();j++) adj_mat[deps[j]-'A'][from-'A'] = dur; 
			in[from-'A'] = deps.length();
			if (deps.length()==0) init=dur;
		}
		
		//Topological sort
		int num_nodes = nodes.size();
		for (int j=0;j<num_nodes;j++) {
			if (in[j] == 0) {
				//Remove this node and relax edges
				for (int k=0;k<30;k++) {
					if (adj_mat[j][k]>0) {
						in[k] --;
						dist[k] = max (dist[k], dist[j]+adj_mat[j][k]);
					}
				}
				in[j] = - 1;
				j=0;
			}
		}
		num_nodes = nodes.size();
		for (int i=0;i<num_nodes;i++) ret=max(ret, dist[i]);
		if (!first) cout<<endl;
		first = false;
		cout<<ret+init<<endl;
	}
	return 0;
}