/*
Given a number N, find number of primes in the range [1,N].
Input Format:
The only line of input consists of a number N
Output Format:
Print the number of primes in the range [1,N].
Constraints:
1 ≤ N ≤ 10^6
Sample Input :
3 
Sample Output -
2
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
bool sieve[N];

int main()
{
    for(int i = 0 ; i < N ; ++i) {
        sieve[i] = true;
    }
    sieve[0] = sieve[1] = false;
    
    for(int i = 2 ; i*i <= N ; ++i) {
        if(sieve[i]) {
            for(int j = i*i ; j < N ; j += i) {
                sieve[j] = false;
            }
        }
    }
    
    int n; cin >> n;
    
    int count = 0;
    for(int i = 0 ; i <= n ; ++i) {
        if(sieve[i]) ++count;
    }
    
    cout << count << '\n';
    
    return 0;
}
