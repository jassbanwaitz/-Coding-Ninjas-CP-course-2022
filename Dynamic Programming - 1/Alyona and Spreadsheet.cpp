/*
During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help!
Input Format:
First line of input will contain T(number of test case), each test case is described as.
The first line of the each test case contains two positive integers n and m the number of rows and the number of columns in the table respectively.
Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j.

The next line of the input contains an integer k, the number of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri
Output Format:
For each test case, print "Yes" to the i-th line of the output if the table consisting of rows from li to ri inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".
Constriants:
1 <= T <= 10
1 <= N, M <=  20000
1 <= N*M <= 20000
1 <= arr[i][j] <= 10^9
1 <= K <= 10000
1 <= l <= r <= N
Sample Input :
1
3 11
5 1 3 4 5 1 5 5 3 3 2 
5 8 2 10 1 9 8 4 4 3 4 
15 6 9 2 7 1 3 13 7 7 5 
1
1 3
Sample Output :
Yes
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>> &mat, int n, int m)
{
    vector<int> dp(n, 0);
    int index[n][m];
    for(int i=0;i<m;i++)
    {
        index[0][i] = 0;
        for(int j=1;j<n;j++)
        {
            if(mat[j][i] >= mat[j-1][i])
                index[j][i] = index[j-1][i];
            else
                index[j][i] = j;
        }
    }
    for(int i=0;i<n;i++)
    {
        dp[i] = i;
        for(int j=0;j<m;j++)
        {
            dp[i] = min(dp[i], index[i][j]);
        }
    }
    return dp;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
            vector<int> dp = solve(mat, n, m);
            int q, l, r;
            cin>>q;
            while(q--)
            {
                cin>>l>>r;
                l--;
                r--;
                if(dp[r] <= l)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
            }        
    }
}
