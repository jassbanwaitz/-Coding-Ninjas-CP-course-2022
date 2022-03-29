/*
You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Note: since result can be pretty large output the answer % mod (10^9 + 7).
Input Format:
The first line of the input file contains one integer T(number of test cases), each test case follows as.
The first line contains two integers n and k separated by single space.
The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output Format:
 For each test case print the number of balanced square bracket sequence % mod (10^9 + 7), that can be formed using the above rules in a new line.
Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= K <= N
Sample Input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Sample Output
1 
0 
2 
3 
2 
*/

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

bool openings[201];
int dp[201][201];

int possibleBrackets(int open,int close,int n)
{
    if(openings[0])
    {
        return 0;
    }

    if(dp[open][close] != -1)
    {
        return dp[open][close];
    }

    if(open > n || close > n)
    {
        return 0;
    }

    if(open == n && close == n)
    {
        dp[open][close] = 1;
        return 1;
    }
    
    int currIndex = (open+close+1);

    if(open == close || openings[currIndex])
    {
        dp[open][close] = possibleBrackets(open+1,close,n);
    }
    else if(open == n)
    {
        dp[open][close] = possibleBrackets(open,close+1,n);
    }
    else
    {
        dp[open][close] = (possibleBrackets(open+1,close,n) + possibleBrackets(open,close+1,n))%mod;
    }
    return dp[open][close];
}

int main()
{
    int d;
    cin >> d;

    while(d--)
    {
        int n,k;
        cin >> n >> k;
        memset(openings,0,sizeof(openings));
        memset(dp,-1,sizeof(dp));

        for(int i = 0; i < k ; i++)
        {
            int m;
            cin >> m;
            openings[m] = true;
        }
        cout<<possibleBrackets(0,0,n)<<endl;
    }

    return 0;
}
