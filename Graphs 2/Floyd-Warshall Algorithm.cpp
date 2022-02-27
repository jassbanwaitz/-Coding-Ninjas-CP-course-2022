/*
You are given an undirected weighted graph G with n vertices. And Q queries, each query consists of two integers a and b and you have print the distance of shortest path between a and b.
Note: If there is no path between a and b print 10^9
Input Format:
First line of Input will contain T(number of test cases), each test case follows as.
Line1: contains two space-separated integers N and M denoting the number of vertex and edge in graph.
Next M line contain three space-separated integers a, b, c denoting the edge between a and b with weight c.
Next line will contain Q (number of queries)
Next Q lines will contain two space-separated integers a and b.
Output Format:
For each query of each test case print the answer in a newline.
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= M <= 10^4
1 <= Q <= 10^4
1 <= wt <= 10^5 (for each edge)
Note: Graph may contain multiple edges.
Sample Input:
1
3 6
3 1 4
1 3 17
2 3 2
1 3 7
3 2 11
2 3 15
3
1 1 
2 2 
2 3 
Sample output:
0
0
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
		int n, m;
		cin >> n >> m;

		vector<vector<int>> dp(102, vector<int>(102, INT_MAX));

		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			dp[x][y] = dp[y][x] = min(dp[x][y], z);
		}

		for(int i = 0 ; i <= n ; ++i) {
			dp[i][i] = 0;
		}

		for(int k = 1 ; k <= n ; ++k) {
			for(int i = 1 ; i <= n ; ++i) {
				for(int j = 1 ; j <= n ; ++j) {
					if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
					}
				}
			}
		}

		int q; cin >> q;
		while(q--) {
			int x, y; 
			cin >> x >> y;
			cout << dp[x][y] << '\n';
		}
	}
	return 0;
}
