/*
you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line1: contain two space-separated integers N and M denoting the number of vertex and number of edges in graph respectively.
Line2: contain two space-separated integers src, des.
Next M line will contain three space-separated integers a, b, wt representing the edge from a to b with weight wt.
Output Format:
For each test case print the distance of des from src in new line.
Note: In case of no path is found print (10 ^ 9) in that case.
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= min(800, N*(N-1))
1 <= a,b <= N
-10^5 <= wt <= 10^5
Sample Input:
1
3 6
3 1
3 1 -2
1 3 244
2 3 -2
2 1 201
3 2 220
1 2 223
Sample output:
-2
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

		int a, b;
		cin >> a >> b;

		vector<vector<int>> g;
		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			g.push_back({x, y, z});
		}

		vector<int> distance(n+1, INT_MAX);
		distance[a] = 0;

		for(int i = 1 ; i <= n ; ++i) {
			for(int j = 0 ; j < m ; ++j) {
				int src = g[j][0];
				int dst = g[j][1];
				int val = g[j][2];
				if(distance[src] != INT_MAX && distance[dst] > distance[src] + val) {
					distance[dst] = distance[src] + val;
				}
			}
		}

		if(distance[b] == INT_MAX) {
			distance[b] = (int) 1e9;
		}
		cout << distance[b] << '\n';
	}
	return 0;
}
