#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int n; 
	string s, pass;
	
	while (cin>>n) {
		cin.ignore();
		map<string,int> mp;
		
		getline (cin, s);
		for (int i=0;i<=s.length()-n;i++) {
			string sub = s.substr (i, n);
			if (mp.find(sub)==mp.end()) mp[sub] = 1;
			else mp[sub]++;
		}
		
		int maxim = 0;
		for (map<string,int>::iterator it = mp.begin(); it!=mp.end(); it++) {
			if (it->second>maxim) {
				maxim = it->second;
				pass = it->first;
			}
		}
		cout<<pass<<endl;
	}
	
	return 0;
}