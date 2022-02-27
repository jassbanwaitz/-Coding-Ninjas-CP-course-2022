/*
Given an undirected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note :
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void BFS(vector<vector<int>>& graph, int startVertex, vector<bool>& visited) {
	queue<int> Queue;
	Queue.push(startVertex);
    visited[startVertex] = true;

	while(!Queue.empty()) {
		int node = Queue.front();
		Queue.pop();

		cout << node << ' ';
	
        for(int i = 0 ; i < graph[node].size() ; ++i) {
            if(!visited[i] && graph[node][i]) {
                Queue.push(i);
                visited[i] = true;
            }
        }
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	vector<vector<int>> graph(n, vector<int>(n, 0));
	for(int i = 0 ; i < m ; ++i) {
		int x, y;
		cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
	}

	vector<bool> visited(n, false);

	for(int i = 0 ; i < n ; ++i) {
		if(!visited[i]) {
			BFS(graph, i, visited);
		}
	}

	return 0;
}
