#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define MAX_N 1000010
string T,P; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
	int i = 0, j = -1; b[0] = -1; // starting values
	while (i < m) { // pre-process the pattern string P
		while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
		i++; j++; // if same, advance both pointers
		b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
	} 
} 
// in the example of P = "SEVENTY SEVEN" above
void kmpSearch() { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0; // starting values
	while (i < n) { // search through string T
		while (j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
		i++; j++; // if same, advance both pointers
		if (j == m) { // a match found when j == m
		//	printf("P is found at index %d in T\n", i - j);
			if (i>j) {
				printf ("%d\n", n/(2*(i-j)));
				return;
			}
			j = b[j]; // prepare j for the next possible match
		} 
	} 
}


int main() {
	// your code goes here
	string s;
	while (getline (cin, T) && T!=".") {
		P = T;
		T += T;
		n = T.length();	m=P.length();
	//	printf ("%d %d", n, m);
		
	//	printf ("%s\n", T);
	//	printf ("%s\n", P);
		kmpPreprocess();
		kmpSearch();
	}
	return 0;
}