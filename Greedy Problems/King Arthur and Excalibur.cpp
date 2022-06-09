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
		vector<int> a(n+1);
		for(int i = 1 ; i <= n ; ++i) {
			cin >> a[i];
		}
		sort(a.begin()+1, a.end());

		vector<int> dp(n+1, 0);

		int ans = 0;
		for(int i = 1 ; i <= n ; ++i) {
			if(i - a[i] >= 0) {
				dp[i] = max(dp[i-1], dp[i-a[i]] + 1);
			}
			else {
				dp[i] = dp[i-1];
			}
		}

		cout << dp[n] << '\n';
	}
	return 0;
}
