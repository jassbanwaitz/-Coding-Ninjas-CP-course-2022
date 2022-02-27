/*
King Arthur’s land is in danger. He wants to fend off the Saxon invaders. In order to do so, he needs to find the fabled sword, Excalibur. He has a vague idea about its location, and has dispatched his best Knights and their Squires to acquire it. The Knights go to the location to find The Dark Forest. They set up tents and decided to split into groups to find Excalibur faster. The famous knight, Sir Lancelot was trying to form search parties, but ran into some trouble.
Most of the knights were untrained for quests, and sending them alone into the dangers of the quest would be a grave mistake. Each of the knights have been given a positive integer parameter by King Arthur, ti - their training score. Sir Lancelot decided that a knight with training t can join the group of t or more knights.
Some of the knights are very egotistical and can’t work well with others. Hence Sir Lancelot decided it is not necessary to include all the knights, some can stay back and defend the tents from danger. Now Sir Lancelot needs to figure out how many search parties he can organize. Sir Lancelot is one of the most responsible knights and doesn't want to go back to King Arthur empty handed. He would rather die than fail. You need to help him in his quest.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Line1 : will contain an integer N denoting the total number of explorer
Line2: Will contain N space-separated integers denoting the inexperience level 
Ouput Format:
For each test case output the answer in a new line.
Constraints:
1 <= T <= 100
1 <= N <= 10^4
1 <= levels <= N
Sample Input:
2
3
1 1 1
5
2 3 1 2 2
Sample Output:
3
2
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector<int> a(n+1);
		for(int i = 1 ; i <= n ; ++i) {
			cin >> a[i];
		}
		sort(a.begin()+1, a.end());

		vector<int> dp(n+1, 0);

		int ans = 0;
		for(int i = 1 ; i <= n ; ++i) {
			if(i - a[i] >= 0) {
				dp[i] = max(dp[i-1], dp[i-a[i]] + 1);
			}
			else {
				dp[i] = dp[i-1];
			}
		}

		cout << dp[n] << '\n';
	}
	return 0;
}
