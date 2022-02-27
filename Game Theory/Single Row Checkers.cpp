/*
Yash is a huge fan of the game Chinese Checkers. He plays the game all the time. So much so, that he has come up with an interesting variant. Instead of the entire board, the game will be played only on one row containing multiple cells. He challenges his friend Aman to a match in his new variant. In Yash’s variant, a cell may contain the character “A” (for Aman), “B” (for Yash) or be empty. Each character can be moved from cell i to cell j if and only if all the cells between ith and jth cell are empty. The first character(leftmost) can only be moved to the right, the second character can only be moved to left, the next to the right, and so on and so forth. Each character can be moved any number of times, including zero.
Both Aman and Yash will have alternate turns. Since Yash is very confident, he gives first chance to his friend Aman. On each turn, the current player must choose a cell containing their own character and move it to a different cell. This cell can be chosen randomly, as long as both the players follow the above said rules. The first player who cannot move a character, loses.
Since each character is moved in a fixed direction, the game is finite.
Yash and Aman will always make the most optimal move. Determine who wins.
Input Format:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string s describing the initial state of the row of cells. Each character of s is either 'A', 'B' or '.', denoting a cell containing 'A', a cell containing 'B' or an empty cell respectively.
Output Format:
For each test case, print a single line containing the string "A" if player A wins or "B" if player B wins.
Constraints:
1 <= T <= 100
1 <= |s| <= 10^4
Sample Input 1:
2
..B
A.B
Sample Output 1:
B
A
Explanation:
For first test case: In the first test case, since A doesn't have a character and therefore, cannot move. Hence, A loses and B wins.
For the second test case: A moves the first character to right. Now, B cannot move and loses.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

char checkMate(const string& s) {
	const int n = s.size();

	string ans = "AB";
	vector<int> c(2);
	vector<char> dir(n, '#');

	int current = 0;

	for(int i = 0 ; i < n ; ++i) {
		if(s[i] != '.') {
			dir[i] = (current == 0 ? 'R' : 'L');
			current ^= 1;
		}
	}

	int pre = -1, ok = 0, grundy = 0;

	for(int i = 0 ; i < n ; ++i) {
		if(s[i] != '.') {
			if(pre == -1) {
				pre = i;
				continue;
			}
			if(dir[i] == 'L' && dir[pre] == 'R') {
				int dots = i - pre - 1;
				if(s[i] == s[pre]) {
					c[s[i] - 'A'] += dots;
				}
				else {
					if(dots > 0) ok = 1;
					grundy ^= dots;
				}
			}
			pre = i;
		}
	}

	if(dir[pre] == 'R') {
		c[s[pre] - 'A'] += (n - pre - 1);
	}

	if(c[0] == c[1]) return ans[grundy == 0];
	return ans[c[0] < c[1]];
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		cout << checkMate(s) << '\n';
	}
	return 0;
}
