/*
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.
Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).
Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line will contain two space-separated integers N and M denoting the number of vertex and edges respectively.
Next M line will contain two space separated integers a, b denoting an edge from a to b.
Output Format:
For each test case output the bottom of the specified graph on a single line. 
Constraints:
1 <= T <= 50
1 <= N, M <= 10^5
Sample Input:
1
3 6
3 1
2 3
3 2
1 2
1 3
2 1
Sample Output:
1 2 3 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

vector<bool> seen;
stack<int> finishedVertices;

void DFS1(vector<vector<int>>& g, int v) {
	seen[v] = true;
	for(int next : g[v]) {
		if(!seen[next]) DFS1(g, next);
	}
	finishedVertices.push(v);
}

void DFS2(vector<vector<int>>& g, int node, vector<int>& current) {
	seen[node] = true;
	current.push_back(node);
	for(int next : g[node]) {
		if(!seen[next]) DFS2(g, next, current);
	}
}

vector<vector<int>> getSCC(vector<vector<int>>& g, vector<vector<int>>& gt, int& n) {
	seen = vector<bool>(n+1, false);
	finishedVertices = stack<int>();
	for(int i = 1 ; i <= n ; ++i) {
		if(!seen[i]) {
			DFS1(g, i);
		}
	}

	vector<vector<int>> ans;

	seen = vector<bool>(n+1, false);
	while(!finishedVertices.empty()) {
		int node = finishedVertices.top();
		finishedVertices.pop();

		if(!seen[node]) {
			vector<int> current;
			DFS2(gt, node, current);
			ans.push_back(current);
		}
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int m; cin >> m;

		vector<vector<int>> g(n+1), gt(n+1);
		for(int i = 0 ; i < m ; ++i) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			gt[y].push_back(x);
		}

		vector<vector<int>> scc = getSCC(g, gt, n);

		set<int> bottom;

		for(vector<int> component : scc) {
			// for O(1) query
			unordered_set<int> currentComponent;
			for(int node : component) {
				currentComponent.insert(node);
			}
			
			bool flag = true;
			for(int node : currentComponent) {
				for(int neighbor : g[node]) {
					if(!currentComponent.count(neighbor)) {
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}

			if(flag) {
				for(int node : currentComponent) {
					bottom.insert(node);
				}
			}
		}

		for(int x : bottom) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}
