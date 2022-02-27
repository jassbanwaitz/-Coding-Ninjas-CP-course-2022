/*
A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6
You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
Input Format:
Contain an integer N
Output Format:
Print the number of super prime between [1, N]
Constraints:
1 <= N <= 10^6
Sample Input 1:
10
Sample Output 1:
2
Sample Input 2:
25
Sample Output 2:
10
Explanation:
The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24.
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
long long sieve[N];

int main()
{
    for(int i = 0 ; i < N ; ++i) {
        sieve[i] = 0;
    }
    
    for(int i = 2 ; i < N ; ++i) {
        if(!sieve[i]) {
            for(int j = 2*i ; j < N ; j += i) {
                ++sieve[j];
            }
        }
    }
    
    int n; cin >> n;
    
    int count = 0;
    for(int i = 0 ; i <= n ; ++i) {
        if(sieve[i] == 2) ++count;
    }
    
    cout << count << '\n';
    
    return 0;
}
