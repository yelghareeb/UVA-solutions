#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

bool is_prefix (string s1, string s2) {
	if (s1.length()>s2.length()) swap(s1,s2);
	if (s2.substr(0, s1.length())==s1) return true;
	return false;
}

int main() {
	// your code goes here
	string s;
	int tt = 1;
	while (cin>>s && s!="9") {
		vector<string> v;
		v.push_back (s);
		while (cin>>s && s!="9") {
			v.push_back(s);
		}
		
		int sz = v.size();
	//	for (int i=0;i<sz;i++) cout<<v[i].size()<<" "<<v[i]<<endl;
		
		bool flag= true;
		for (int i=0;i<sz-1 && flag;i++) {
			for (int j=i+1;j<sz;j++) {
				if (is_prefix (v[i], v[j])) {
					flag = false; 
				//	cout<<v[i]<<" "<<v[j];
					break;
				}
			}
		}
		if (flag) printf ("Set %d is immediately decodable\n", tt++);
		else printf ("Set %d is not immediately decodable\n", tt++);
	}
	return 0;
}