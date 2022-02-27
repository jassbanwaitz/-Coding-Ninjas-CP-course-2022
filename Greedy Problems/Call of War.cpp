/*
DecenTile Games have launched a new First Person Shooter soldier game, called the Call of War, that young gamers can play on their website.
Our protagonist, Ninja (played by you) is a soldier whose mission is to kill all the enemies plotting against you. Your enemies are standing in a circle, numbered clockwise from 1 to n. Initially, the i-th enemy has ai health.
You have only one pistol, and infinite bullet magazines. You have to shoot the enemies in order to kill them. Each bullet fired at the enemy decreases their health by 1 (deals 1 damage to it). When the health of some enemy i becomes 0 or less than 0, he dies and his grenade drops down and explodes, dealing bi damage to the next enemy (enemy i+1, if i<n, or enemy 1, if i=n). If the next enemy is already dead, then nothing happens. If the frag from the grenade kills the next enemy, even he drops a grenade, damaging the enemy after him and possibly triggering another explosion, and so on.
You have to calculate the minimum number of bullets you need in order to kill all the enemies and win the game.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Line 1: contain an integer N
Next N line contains two space separated integers a and b
Output Format:
For each test case print the output in a new line.
Constraints:
1 <= T <= 100
1 <= N <= 10^4
1 <= a, b <= 10^12
Sample Input:
1
3
7 15
2 14
5 3
Sample Output:
6
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
