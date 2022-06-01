/*
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input Format:
The first line of input will contain T(number of the test case). Each test case contains an integer N.
Output Format:
For each test case print the answer in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^5
Sample Input:
3
10
100
3
Sample Output:
67
13015
3
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e5 + 1;
ll arr[mex];
void sieve() {

	for (ll i = 0; i < mex; i++) {
		arr[i] = i;
	}


	for (ll i = 2; i < mex; i++) {
		if (arr[i] == i) {
			arr[i] -= 1;
			for (ll j = 2 * i; j < mex; j += i) {
				arr[j] = arr[j] * (i - 1) / i;
			}
		}
	}



}



int main() {

	ll t;
	cin >> t;
	sieve();
	ll result[mex];
	memset(result, 0, sizeof(result));
	for (ll i = 1; i < mex; i++) {
		for (ll j = 2; i * j < mex; j++) {
			result[i * j] += (i * arr[j]);
		}
	}
	ll dp[mex];
	dp[0] = result[0];
	for (ll i = 1; i < mex; i++) {
		dp[i] = result[i] + dp[i - 1];
	}
	while (t--) {
		ll n;
		cin >> n;
		ll sum = 0;
		cout << dp[n] << endl;

	}
}
