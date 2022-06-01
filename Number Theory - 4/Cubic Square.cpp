/*
Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
After school he found that tuples he wrote are modified by his little sister. His sister converted each b into base 3. Varun wrote everything in base 10.
Help Varun to do his exercise.
Input Format:
First line of input contains a number T(number of test case). Each test case contains an integer a(base 10) followed by a string b (base 3) followed by integer m (base 10). All are space-separated.
Output Format;
Output a number for each test case a^b mod m in base 10 in new line.
Constraints:
1 <= T <= 1000
1 <= a, m <= 10^9
Number of digits in b will be less than 250.
Sample Input:
2
2 10 10
3 21101 19
Sample Output:
8
3
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

	// write your code here
	ll t;
	cin >> t;
	while (t--) {
		ll a;
		cin >> a;
		string b;
		cin >> b;
		ll m;
		cin >> m;
		ll l = b.length();
		ll result = 1;
		for (ll i = l - 1; i >= 0; i--) {

			if (b[i] == '0') {

			}
			else if (b[i] == '1') {
				result = (result % m * a % m) % m;
			}
			else if (b[i] == '2') {
				result = ((result % m * a % m) * a % m) % m;
			}
			a = ((a * a) % m * a) % m;

		}
		cout << result << endl;

	}
	return 0;
}
