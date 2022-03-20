/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
W can be pretty large so output the answer % mod(10^9 + 7)
Input Format
First line will contain T (number of test case), each test case is consists of 3 three lines.
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
For each test case print the number of ways (W) % mod(10^9 +7) in new line.
Constraints :
1 <= T <= 10
1 <= N <= 10
1 <= V <= 5000
*/


#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int count(int arr[],int m,int n)
{
    int i,j,x,y;
    int table[n+1][m];
    for(i=0;i<m;i++)
        table[0][i] = 1;
        
        for(i=1;i<n+1;i++)
        {
            for(j=0;j<m;j++)
            {
                x = (i-arr[j] >= 0) ? table[i-arr[j]][j] : 0;
                y = (j>=1) ? table[i][j-1] : 0;
                table[i][j] = (x+y) % mod;
            }
        }
    return table[n][m-1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m ;
        cin>>m;
        int arr[m];
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
        }
        int val;
        cin>>val;
        cout<<count(arr,m,val)<<endl;
    }
}
