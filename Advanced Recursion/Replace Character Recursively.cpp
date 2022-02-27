/*
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
The first line of input will contain an integer T, which will denote the value of number of test cases. In the following lines, T test cases will be written.
The first line of each test case will contain a string S. 
The following line of each test case will contain two space separated characters, c1 and c2, respectively.
Output Format :
For each test case, the first and only line of output contains the updated string S.
Constraints :
 1 <= T <= 100
 1 <= Length of String S <= 100
Sample Input :
1
abacd
a x
Sample Output :
xbxcd
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void recursion(string& s, int index, char& t, char& r) {
	if(index == s.size()) {
		return;
	}

	if(s[index] == t) {
		s[index] = r;
	}
	recursion(s, index+1, t, r);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		char t, r;
		cin >> t >> r;

		recursion(s, 0, t, r);

		cout << s << '\n';
	}
	return 0;
}
