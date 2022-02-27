/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
First line of input will contain T number of test cases
Next T line will contain the string S
Output Format :
For every test case print the answer in a separate line
Constraints :
1 <= T <= 10
1 <= |S| <= 10^4
where |S| represents the length of string
Sample Input 1 :
1
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
1
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void recursion(const string& s, int index, string& ans) {
	if(index == s.size()) {
		return;
	}

	if(index == 0 || (index > 0 && s[index] != s[index-1])) {
		ans += s[index];
	}
	recursion(s, index+1, ans);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		string ans;

		recursion(s, 0, ans);

		cout << ans << '\n';
	}
	return 0;
}
