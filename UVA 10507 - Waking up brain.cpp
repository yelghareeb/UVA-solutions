#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map> 
using namespace std;

int visited [26];

int main() {
	// your code goes here
	int n,m;
	string awake, tmp;
	
	while (cin>>n) {
		vector<string> con;
		map<char,int> mp;
		
		cin>>m;
		memset (visited, 0, sizeof(visited));
		
		cin>>awake;
		int x = 0;
		for (int j=0;j<3;j++) if (mp.find(awake[j])==mp.end()) mp[awake[j]] = x++;
		
		for(int i=0;i<m;i++) {
			cin>>tmp;
			con.push_back(tmp);
			for (int j=0;j<2;j++) {
				if (mp.find(tmp[j])==mp.end()) mp[tmp[j]] = x++;
			}
		}
	
		if (n>mp.size()) {
			printf ("THIS BRAIN NEVER WAKES UP\n");
			continue;
		}
		
		for (int i=0;i<3;i++) visited[mp[awake[i]]] = 1;
		int count = 3, ret=0;
		
		while (count<n) {
			vector<int> to_mark;
			for (map<char,int>::iterator it = mp.begin(); it!=mp.end(); it++) {
				int j = it->second;
				if (visited[j]) continue;
				
				int tcount = 0;
				for (int k=0;k<con.size();k++) {
					if (mp[con[k][0]]==j && visited[mp[con[k][1]]]) tcount++;
					else if (mp[con[k][1]]==j && visited[mp[con[k][0]]]) tcount++;
				}
				if (tcount>=3) to_mark.push_back (j);
			}
			count += to_mark.size();
			if (to_mark.empty()) break;
			for (int j=0;j<to_mark.size();j++) visited[to_mark[j]]=1;
			ret++;
		}
		if (count<n) printf ("THIS BRAIN NEVER WAKES UP\n");
		else printf ("WAKE UP IN, %d, YEARS\n", ret);
	}
	return 0;
}