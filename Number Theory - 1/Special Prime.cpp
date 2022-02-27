/*
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.
Input Format:
An integer N.
Output Format:
Print the number of special primes
Constraints:
1 <= N <= 2*10^5
Sample Input:
27
Sample Output:
2
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
	
	int n; cin >> n;

	sieve = vector<bool>(N, true);
	for(int i = 2 ; i*i <= N ; ++i) {
		if(sieve[i]) {
			for(int j = i*i ; j < N ; j += i) {
				sieve[j] = false;
			}
		}
	}

	vector<int> primes;
	for(int i = 2 ; i < N ; ++i) {
		if(sieve[i]) primes.emplace_back(i);
	}

	unordered_set<int> set;
	for(int i = 1 ; i < primes.size() ; ++i) {
		set.insert(primes[i-1] + primes[i]);
	}

	int count = 0;
	for(int i = 2 ; i <= n ; ++i) {
		if(sieve[i] && set.count(i-1)) ++count;
	}

	cout << count << '\n';

	return 0;
}
