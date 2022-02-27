/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input Format:
The first line of input contains number of test cases, which will be denoted by the symbol t. In the following lines, the t test cases are written.
The first line of each of the test cases contain two space separated integers: N and C. The following line contains N space separated integers, where the ith integer denote the position of ith stall. 
It is given that sum of N over all the test cases doesn't exceed 1000, 000.   
Output Format:
As described in the problem statement, the first and only line of output will print the largest minimum distance possible. 
The output for each test case will be printed on a separate line. 
Sample Input 1:
2
11 3
15 5 2 4 17 16 12 8 19 18 11 
15 13
20 8 16 3 13 9 11 10 15 17 18 14 1 2 5 
Sample Output 1:
8
1
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf (int)1e9
#define f first
#define s second

bool check(const vector<int>& a, const int& cows, int distance) {
	int count = 1;
	int previousPosition = 0; 
	for(int i = 1 ; i < a.size() ; ++i) {
		if(a[i] - a[previousPosition] >= distance) {
			++count;
			previousPosition = i;
		}
		if(count >= cows) return true;
	}
	return false;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, c;
		cin >> n >> c;

		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		int left = 0;
		int right = 1000000001;

		int ans = 0;

		while(left <= right) {
			int mid = (right + left) / 2;
			if(check(a, c, mid)) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

