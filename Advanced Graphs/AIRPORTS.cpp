/*
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, and with minimum cost.
Input Format:
The first line of input contains the integer T (the number of test cases), each test case follow as.
Line1: Three space-separated integers N, M and cost number of locations, number of possible roads and cost of airport respectively
The following M lines each contain three integers X, Y and C, separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output Format:
For each test case print the cost in a newline.
Constraints:
1 <= T <= 20
1 <= N, M <= 10^5
1 <= cost <= 10^9
1 <= weight(of each road) <= 10^9
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
145
2090
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf (int)1e9
#define f first
#define s second

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
		if(parent[x] == x) return x;
		return parent[x] = get_set(parent[x]);
	}

	void union_set(int x, int y) {
		x = get_set(x);
		y = get_set(y);
		if(x != y) {
			if(rank[x] == rank[y]) ++rank[x];
			if(rank[x] < rank[y]) swap(x, y);
			parent[y] = x;
		}
	}
};

class edge {
public:
	int src, dst, val;

	edge(int s, int d, int v) {
		src = s;
		dst = d;
		val = v;
	}
};

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int Case = 1;
	int t; cin >> t;
	while(t--)
	{
		int n, m, airportCost;
		cin >> n >> m >> airportCost;

		vector<edge> graph;
		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			graph.push_back(edge(x-1, y-1, z));
		}

		sort(graph.begin(), graph.end(), [&](edge a, edge b) {
			return a.val < b.val;
		});

		DSU dsu(n);

		int total = 0, airportsCount = 0;

		int index = 0, count = 0;
		while(index < m && count < n-1 && graph[index].val < airportCost) {
			edge x = graph[index];
			if(dsu.get_set(x.src) != dsu.get_set(x.dst)) {
				dsu.union_set(x.src, x.dst);
				total += x.val;
				++count;
			}
			++index;
		}

		for(int i = 0 ; i < n ; ++i) {
			if(dsu.get_set(i) == i) {
				total += airportCost;
				++airportsCount;
			}
		}

		cout << total << '\n';
	}
	return 0;
}
