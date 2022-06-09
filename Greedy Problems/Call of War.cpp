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
		vector<pair<int, int>> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i].first >> a[i].second;
		}

		vector<pair<int, int>> v;
		for(int i = 1 ; i < n ; ++i) {
			int pts = min(a[i].first, a[i-1].second) - min(a[0].first, a[n-1].second);
			v.push_back({pts, i});
		}
		sort(v.begin(), v.end());

		int index = 0;
		if(v.size() > 0 && v[0].first < 0) {
			index = v[0].second;
		}

		int ans = 0;

		for(int i = 0 ; i < n ; ++i) {
			ans += a[index].first;
			int damage = a[index].second;

			index = (n + index + 1) % n;

			a[index].first = max(0LL, a[index].first - damage);
		}
		cout << ans << '\n';
	}
	return 0;
}
