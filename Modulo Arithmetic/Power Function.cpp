/*
You are given two integers, X and Y. You have to compute X^Y.
Example:
2^3 evaluates to 8.
Since the result can be large, so calculate the X^Y % M, where M is 10^9 + 7.
Note: Apply the brute force method to solve the problem.
Input Format:
The first line of input contains an integer, that denotes the value of the number of test cases. Let us denote it with the symbol T.
Each test case consists of two space separated integers, that denote the value of X and Y. Each test case is given in a separate line.
Output Format:
For each test case, print the answer modulo 10^9 + 7 in a separate line.
Constraints:
1 <= T <= 50
1 <= X, Y <= 10^5
Time Limit: 1 second
Sample Input 1:
2
2 3
3 2
Sample Output 1:
8
9
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int MOD = (int) 1e9+7;

int powerFunction(int base, int power) {
	if(power == 0) {
		return 1;
	}
	if(base <= 0) {
		return base;
	}

	int ans = powerFunction(base, power / 2);
	int value = (ans * ans) % MOD;

	if(power % 2 == 1) {
		value = (value * base) % MOD;
	}
	return value;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int base, power;
		cin >> base >> power;

		cout << powerFunction(base, power) << '\n';
	}
	return 0;
}
