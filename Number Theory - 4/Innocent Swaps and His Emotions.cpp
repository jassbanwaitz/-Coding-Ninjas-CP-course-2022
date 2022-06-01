/*
There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions on a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
Input Format:
The first line of the input contains T, denoting the number of test cases.

The next T lines contain two space-separated integers N and K.
Constraints:
1 <=T <= 10^5
1<= K <= N <= 10^6
Output Format:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
Sample Input 1:
3
1 1
2 1
3 2
Sample Output 2:
2
4
12
Explanation
In the first test case, he needs to feel joyful on Day 1. Hence, answer is 2 (He can either play video games or sleep).

In the second test case, he can be joyful either on Day 1 or Day 2. So number of ways = 4.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1e9 + 7;
const int xe = 1e9 + 5;
ll arr[1000001];

void factori() {
	arr[0] = 1;
	for (int i = 1; i < 1000001; i++) {
		arr[i] = (arr[i - 1] % m * i % m) % m;
	}
}

inline ll factorial(ll n) {
	return arr[n];
}
ll binexpo(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1)
			ans = (ans * a) % m;

		a = (a * a) % m;
		b >>= 1;
	}
	return ans;
}
int main() {
	factori();
	ll t;
	cin >> t;
	while (t--) {

		ll n, k;
		cin >> n >> k;
		ll x1 = factorial(n);

		ll x2 = factorial(n - k);
		ll x3 = factorial(k);

		ll y1 = binexpo(x2, xe);

		ll y2 = binexpo(x3, xe);

		ll y3 = binexpo(2, k);
		ll ans = (x1 % m * y1 % m * y2 % m * y3 % m) % m;
		cout << ans << endl;
	}

}
