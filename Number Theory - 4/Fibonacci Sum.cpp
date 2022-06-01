/*
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
First line of input will contain T(number of test cases), each test case follows as.
Two non-negative space-separated integers N and M. (N <= M)
Output Format :
A new line containing the answer for the each test case.
Constraints:
1 <= T <= 10^3
1 <= N <= M <= 10^18
Sample Input :
1 
10 19 
Sample Output :
10857
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

void mult(ll a[][2], ll b[][2])
{
    ll res[2][2];
    memset(res, 0, sizeof res);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = res[i][j];
        }
    }
}
ll helper(ll num)
{
    ll q[2][2] = {{1, 1}, {1, 0}};
    ll w[2][2] = {{1, 0}, {0, 1}};
    while (num)
    {
        if (num & 1)
            mult(w, q);

        mult(q, q);

        num >>= 1;
    }

    return w[0][1];
}

ll fiboSum(ll m, ll n)
{
    return (helper(n + 2) - helper(m + 1) + mod) % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << fiboSum(n, m) << endl;
    }
}
