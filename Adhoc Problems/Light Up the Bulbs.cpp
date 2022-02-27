/*
Navdeep is given a binary string (string consists of only 0’s and 1’s) of size ‘n’. The string represents the state of n bulbs. ‘0’ represents that the bulb is in ‘OFF’ mode and ‘1’ represents the bulb is in ‘ON’ mode. Navdeep is given the task to change all the characters to 1. In other words, Navdeep has to light up all the bulbs.
He can perform two operations on the given string:
1. In the first operation, he can choose any substring and reverse it. For example, in the binary string: 0110001, if we reverse substring from 1st to 3rd index in the given string, then the resultant string will be: 0011001. Here, 110 is reversed to form 011. This operation will cost Rs. ‘X’.
2. In the second operation, he can choose any substring and toggle each character of that substring. For example, in the binary string: 0110001, if we toggle characters of the substring from 1st to 3rd index in the given string, then the resultant string will be: 0001001. Here, 110 is converted to form 001. This operation will cost Rs. ‘Y’.     
Can you help Navdeep to complete the task in the minimum amount possible.
Input Format:
The first line will contain three space separated integers: ‘n’, ‘X’, ‘Y’, denoting the number of bulbs, cost of first operation and cost of second operation respectively.
The second line contains a binary string of length ‘n’, consisting of 0’s and 1’s,  representing whether the bulb is ‘OFF’ or ‘ON’.
Output Format:
Print a single integer denoting the minimum cost required to light up all the bulbs.
Constraints:
1 <= n <= 3,00,000
0 <= X, Y <= 10^9
Time Limit: 1 second
Sample Input:
5 1 10
01000
Sample Output:
11
Explanation:
First, Reverse substring (0, 1): “01000” -> “10000”, COST = 1
Second, Invert substring (1, 4): “10000” -> “11111”, COST = 10
Total cost = 1+10 => 11
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, x, y;
	cin >> n >> x >> y;
	string s; cin >> s;

	if(string(n, '1') == s) {
		cout << 0 << '\n';
        return 0;
	}

	int zeroGroups = 0;
	for(int i = 0 ; i < n ; ++i) {
		if(s[i] == '0' && (i == 0 || s[i-1] == '1')) {
			++zeroGroups;
		}
	}

	cout << (zeroGroups-1) * min(x, y) + y << '\n';
	return 0;
}
