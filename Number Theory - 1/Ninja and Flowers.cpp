/*
Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.
As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.
Input Format:
The only line of input will contain an integer N (number of flowers).
Output Format:
In first-line print K, the minimum number of different colour boxes that are needed to pack the flowers.
Next line contains K space-separated integers in sorted order denoting the counts of the different coloured boxes.
Constraints:
1 <= N <= 2*10^5
Sample Input:
4
Sample Output:
2
1 3
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int N = (int) 1e6+5;
vector<bool> sieve;

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	sieve = vector<bool>(N, true);
	for(int i = 2 ; i*i <= N ; ++i) {
		if(sieve[i]) {
			for(int j = i*i ; j < N ; j += i) {
				sieve[j] = false;
			}
		}
	}

	int n; cin >> n;

	if(n <= 1) {
		cout << 1 << '\n';
	}
	else {
		cout << 2 << '\n';
	}

	int cp = 0, cnp = 0;
	for(int i = 2 ; i <= n+1 ; ++i) {
		if(sieve[i]) ++cp;
		else ++cnp;
	}

	cout << min(cp, cnp) << ' ' << max(cp, cnp) << '\n';

	return 0;
}
