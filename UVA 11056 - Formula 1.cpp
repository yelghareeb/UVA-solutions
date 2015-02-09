#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

struct Record {
	string name;
	int val;
	Record (string _name, int n1, int n2, int n3) {
		name = _name;
		val = n3+n2*1000+n1*1000*60;
	}
	bool operator < (const Record& r2) const {
		if (val==r2.val) {
			string s1 = name,s2=r2.name;
			for (int i=0;i<s1.length();i++) s1[i] = tolower(s1[i]);
			for (int i=0;i<s2.length();i++) s2[i] = tolower(s2[i]);
			return s1<s2;
		}
		return val<r2.val;
	}
};

int main() {
	// your code goes here
	int n;
	string s, name, tmp;
	int mi, sec, ms;
	
	while (cin>>n) {
		vector<Record> v;
		for (int i=0;i<n;i++) {
			cin>>name;
			cin>>tmp>>mi>>tmp>>sec>>tmp>>ms>>tmp;
			
			v.push_back (Record(name, mi,sec,ms));
		}
		sort (v.begin(), v.end());
		int sz = v.size(),row = 1;
		
		for (int i=0;i<sz;i+=2) {
			printf ("Row %d\n",row++);
			if(i==sz-1) printf ("%s\n", &v[i].name[0]);
			else printf ("%s\n%s\n", &v[i].name[0], &v[i+1].name[0]);
		}
		printf ("\n");
	}
	return 0;
}