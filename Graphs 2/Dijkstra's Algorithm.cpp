/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
1 <= T <= 10
2 <= V, E <= 10^3
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
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

		vector<vector<pair<int, int>>> a(n);
		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			a[x].push_back({z, y});
			a[y].push_back({z, x});
		}

		vector<bool> visited = vector<bool>(n, false);
		vector<int> weight = vector<int>(n, INT_MAX);
		weight[0] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push({0, 0});

		while(!q.empty()) {
			int currentWeight = q.top().first;
			int currentNode = q.top().second;
			q.pop();

			visited[currentNode] = true;

			for(pair<int, int> x : a[currentNode]) {
				int node = x.second;
				int value = x.first;
				if(!visited[node] && weight[node] > currentWeight + value) {
					weight[node] = value + currentWeight;
					q.push({weight[node], node});
				}
			}
		}

		for(int i = 0 ; i < n ; ++i) {
			cout << i << ' ' << weight[i] << '\n';
		}
	}
	return 0;
}
