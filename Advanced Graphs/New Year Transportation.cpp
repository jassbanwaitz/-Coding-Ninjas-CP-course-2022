/*
New Year Transportation
New Year is coming in Line World! In this world, there are n cells numbered by integers from 1 to n, as a 1 × n board. People live in cells. However, it was hard to move between distinct cells, because of the difficulty of escaping the cell. People wanted to meet people who live in other cells.
So, user tncks0121 has made a transportation system to move between these cells, to celebrate the New Year. First, he thought of n - 1 positive integers a1, a2, ..., an - 1. For every integer i where 1 ≤ i ≤ n - 1 the condition 1 ≤ ai ≤ n - i holds. Next, he made n - 1 portals, numbered by integers from 1 to n - 1. The i-th (1 ≤ i ≤ n - 1) portal connects cell i and cell (i + ai), and one can travel from cell i to cell (i + ai) using the i-th portal. Unfortunately, one cannot use the portal backwards, which means one cannot move from cell (i + ai) to cell i using the i-th portal. It is easy to see that because of condition 1 ≤ ai ≤ n - i one can't leave the Line World using portals.
Currently, I am standing at cell 1, and I want to go to cell d. However, I don't know whether it is possible to go there. Please determine whether I can go to cell d by only using the construted transportation system.
Input Format:
First line will contain T(number of test case), each test case follows as.
Line1: will contain N (number of cells)
Line2: contains n - 1 space-separated integers a1, a2, ..., an - 1 (1 ≤ ai ≤ n - i). It is guaranteed, that using the given transportation system, one cannot leave the Line World.
Line3: contain an integer Q  (number of queries)
Next Q line will contain an integer d the cell where i want to go for that query
Output Format:
If I can go to cell d using the transportation system, print "YES". Otherwise, print "NO" for each test case and query in newline.
Sample Input 1:
1
8
1 2 1 2 1 2 1
1
4
Sample Output 1:
YES
Sample Input 2:
1
8
1 2 1 2 1 1 1
1
5
Sample Output 2:
NO
Note:
In the first sample, the visited cells are: 1, 2, 4; so we can successfully visit the cell 4.
In the second sample, the possible cells to visit are: 1, 2, 4, 6, 7, 8; so we can't visit the cell 5, which we want to visit.
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
		vector<int> a(n);
		for(int i = 1 ; i < n ; ++i) {
			cin >> a[i];
		}

		vector<bool> visited(n, false);

		int index = 1;
		while(index < n) {
			visited[index] = true;
			int step = index + a[index];
			index = step;
		}

		int q; cin >> q;
		while(q--) {
			int x; cin >> x;
			if(visited[x] || x == n) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
