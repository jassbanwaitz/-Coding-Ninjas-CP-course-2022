/*
Ninja is given an array of integers of size N and Q queries, each query will be consists of two integers l, r and ninja is supposed to calculate the number of i such that the ninja factor of array[i] is a prime number where l <= i <= r
Ninja factor of a Number A is defined as the number of integers B such that
1 <= B <= A
LCM (A, B) = A * B
Input Format:
 Line1: contain two space-separated integers N and Q denoting the number of elements in array and number of queries.
Line2: contain N space-separated integers denoting the elements of the array
Next, Q lines contain two space-separated integers l, r describing the query.
Output Format:
For each query print the answer in a newline.
Constraints:
1 <= N , Q <= 10^5
1 <= arr[i] <= 10^9
1 <= l, r <= N
Sample Input:
10 6
8 8 6 8 6 7 10 7 9 9 
2 10
7 7
5 7
7 8
6 10
3 4
Sample Output:
2
0
1
0
0
1
Explanation:
6 is the only number whose ninja factor is prime here(i.e. 2) {[LCM(1,6]=1*6; LCM(5, 6)=5*6}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1), dp(n+1, 0);
    
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i] == 3 || a[i]==4 || a[i]==6)
            dp[i] = 1;
        
        dp[i] += dp[i-1];
    }
    
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<dp[r] - dp[l-1]<<'\n';
    }
    
    return 0;
}
