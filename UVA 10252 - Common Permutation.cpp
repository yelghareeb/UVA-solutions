#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	string s1, s2;
	while (getline(cin,s1) && !cin.eof()) {
		getline(cin,s2);
		int len1 = s1.length(), len2 = s2.length();
		int occ1[26], occ2[26];
		memset (occ1, 0, sizeof(occ1));
		memset (occ2, 0, sizeof(occ2));
		
		for (int i=0;i<len1;i++) occ1[s1[i]-'a']++;
		for (int i=0;i<len2;i++) occ2[s2[i]-'a']++;
		
		string ret = "";
		
		for (int i=0;i<len1;i++) {
			if (occ1[s1[i]-'a']>0 && occ2[s1[i]-'a']>0) {
				occ1[s1[i]-'a']--;
				occ2[s1[i]-'a']--;
				ret += s1[i];
			}
		}
		sort (ret.begin(), ret.end());
		cout<<ret<<endl;
	}
	return 0;
}