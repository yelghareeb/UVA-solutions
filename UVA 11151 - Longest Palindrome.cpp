#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int len, dp[1005][1005];

int sol (int l, int r) {
	if (dp[l][r]!=-1) return dp[l][r];
	if (l==r) return dp[l][r]=1;
	else if (r==l+1) {
		if (s[l]==s[r]) return dp[l][r]=2;
		else return dp[l][r]=1;
	}
	if (s[l]==s[r]) return 2+sol(l+1,r-1);
	return dp[l][r]= max (sol(l+1,r), sol (l,r-1));
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	cin.ignore();
	while (t--) {
		getline (cin,s);
		len = s.length();
		for (int i=0;i<1005;i++) for(int j=0;j<1005;j++) dp[i][j]=-1;
		cout<<sol (0,len-1)<<endl;
	}
	return 0;
}