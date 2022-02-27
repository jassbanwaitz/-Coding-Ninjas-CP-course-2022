/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
Input Format :
First line will contain T(number of test case), each test case follows as. 
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Weight of MST for each test case in new line.
Constraints :
1 <= T <= 10
2 <= V, E <= 10^5
1 <= wt <= 10^4
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class edge {
public:
	int src, dst, val;

	edge(int s, int d, int v) {
		src = s;
		dst = d;
		val = v;
	}
};

bool compare(edge a, edge b) {
	return a.val < b.val;
}

class DSU {
private:
	vector<int> parent, rank;

public:
	DSU(int n) {
		for(int i = 0 ; i < n ; ++i) {
			rank.push_back(0);
			parent.push_back(i);
		}
	}

	int get_set(int x) {
		if(x == parent[x]) return x;
		return parent[x] = get_set(parent[x]);
	}

	bool union_set(int x, int y) {
		x = get_set(x);
		y = get_set(y);
		if(x != y) {
			if(rank[x] == rank[y]) ++rank[x];
			if(rank[x] < rank[y]) swap(x, y);
			parent[y] = x;
			return true;
		}
		return false;
	}
};

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;

		vector<edge> a;
		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			a.push_back(edge(x, y, z));
		}
		sort(a.begin(), a.end(), compare);

		DSU dsu(n);
		
		int ans = 0;

		int edges = 0, index = 0;
		while(edges < n-1 && index < m) {
			if(dsu.union_set(a[index].src, a[index].dst)) {
				++edges;
				ans += a[index].val;
			}
			++index;
		}

		cout << ans << '\n';
	}
	return 0;
}
