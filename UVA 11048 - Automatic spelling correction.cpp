#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>
#include <set>
using namespace std;

vector<string> dict;
set <string> mp;

int main() {
	// your code goes here
	int n,m;
	cin>>n;
	
	string query,s;
	dict.resize (n);
	
	for (int i=0;i<n;i++) {
		cin>>s;
		mp.insert(s);
		dict[i] = s;
	}
	cin>>m;
	for (int i=0;i<m;i++) {
		cin>>query;
		int len1 = query.length();
		bool flag = false;
		if (mp.find(query) != mp.end()) { printf ("%s is correct\n", &query[0]); flag = true; }
		
		for (int j=0;j<n&&!flag;j++) {
			string dic = dict[j];
			int len2= dic.length();
			
			if (abs(len1-len2)<=1) {
				if (len1==len2) {
					int mismatch=0;
					for(int k=0;k<len1;k++) {
						if (query[k]!=dic[k]) mismatch++;
						if (mismatch==2) {
							string qq = query;
							swap (qq[k], qq[k-1]);
							int y;
							if (qq==dic) {
								printf ("%s is a misspelling of %s\n", &query[0], &dic[0]);
								flag = true;
							}
							break;
						}
					}
					
					if (mismatch==1) {
						printf ("%s is a misspelling of %s\n", &query[0], &dic[0]);
						flag = true;
					}
				}
				
				else {
					int mismatch = 0;
					for(int k=0, u=0;k<len1&&mismatch<2;k++,u++) {
						if (query[k]!=dic[u]) {
							mismatch++;
							if (len1>len2) u--;
							else k--;
						}
					}
					if (mismatch<2) {
						printf ("%s is a misspelling of %s\n", &query[0], &dic[0]);
						flag = true;
					}
				}
			}
		}
		if (!flag) printf ("%s is unknown\n", &query[0]);
	}
	return 0;
}