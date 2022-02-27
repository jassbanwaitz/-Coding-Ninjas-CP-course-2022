/*
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distribute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He wants to distribute them in a way such that:
1. All students get an equal number of candies.
2. All the candies which a student gets must be from a single box only.
As he wants to make all of them happy so he wants to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First-line contains T the number of test cases. 
The first line of each test case contains N and K.
Next line contains N space-separated integers, ith of which is the number of candies in the ith box.
Output
For each test case print the required answer in a separate line.
Constraints
1<= T <= 10^5
1 <= N <= 10^5
1 <= K <= 10^9
0 <= A[i] <= 10^9
Sum of N over all test cases doesn't exceed 10^6
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

bool check(const vector<int>& a, int candies, const int& k) {
	int countChildren = 0;
	for(int i = 0 ; i < a.size() ; ++i) {
		countChildren += a[i] / candies;
		if(countChildren >= k) return true;
	}
	return false;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}

		int ans = 0;

		int left = 0, right = (int) 1e9;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(check(a, mid, k)) {
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
