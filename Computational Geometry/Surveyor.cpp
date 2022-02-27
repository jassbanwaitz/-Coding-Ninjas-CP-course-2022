/*
A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
Input Format:
First line of input contains a string s
Second line of input contains an array (space separated), with the length same as string s.
Constraints:
Direction string will have between 4 and 50 characters inclusive.
Length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
Output Format:
For each input, print the area calculated.
Sample Test Case
NWWSE
10 3 7 10 10
Sample Ouput:
100
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s; cin >> s;
	const int n = s.size();

	vector<int> points(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> points[i];
	}

	int ans = 0;

	vector<int> x(n+1, 0), y(n+1, 0);
	for(int i = 0 ; i < n ; ++i) {
		x[i+1] = x[i];
		y[i+1] = y[i];

		if(s[i] == 'N') {
			y[i+1] = y[i] + points[i];
		}
		if(s[i] == 'S') {
			y[i+1] = y[i] - points[i];
		}
		if(s[i] == 'E') {
			x[i+1] = x[i] + points[i];
		}
		if(s[i] == 'W') {
			x[i+1] = x[i] - points[i];
		}
		ans += (x[i+1] - x[i]) * y[i];
	}

	cout << abs(ans) << '\n';

	return 0;
}
