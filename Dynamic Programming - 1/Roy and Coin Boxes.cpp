/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.
After M days, Roy has a query: How many coin boxes have at least X coins.
He has Q such queries.
Input Format:
First line will contain T (number of test case), format of each test case follows
First line contains two space separated integers N and M (N - number of coin boxes, M - number of days). Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.
Output Format:
For each query of each test case output the result in a new line.
Constraints:
1 <= T <= 10
1 ≤ N ≤ 10000
1 ≤ M ≤ min(10000, N)
1 ≤ L ≤ R ≤ N
1 ≤ Q ≤ 10000
1 ≤ X ≤ N
Sample Input
1
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q,l,r;
        cin>>n>>m;
        int start[n+1], end[n+1], coins[n+1], ans[n+1];
        for(int i=0;i<=n;i++)
        {
            start[i] = 0;
            end[i] = 0;
            coins[i] = 0;
            ans[i] = 0;
        }
        for(int i=0;i<m;i++)
        {
            cin>>l>>r;
            start[l]++;
            end[r]++;
        }
        int temp = 0;
        for(int i=1;i<=n;i++)
        {
            temp += start[i];
            coins[i] = temp;
            temp -= end[i];
        }
        for(int i=1;i<=n;i++)
        {
            ans[coins[i]]++;
        }
        for(int i=n-1;i>0;i--)
        {
            ans[i] = ans[i]+ans[i+1];
        }
        cin>>q;
        while(q--)
        {
            cin>>temp;
            cout<<ans[temp]<<endl;
        }
    }
    return 0;
}
