/*
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
    for(j=i;j<n;j++)
        unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format:
First line will contain T(number of test cases), and each test case consists of two lines.
The first line contains two space-separated integers N and K.
The second line will contain N space-separated integers, where Ith integer denotes the candy in the Ith packet.
Output Format:
For each test case print a single integer which will be minimum unfairness in newline.
Constraints
1 <= T <= 10
2<=N<=10^5
2<=K<=N
0<= number of candies in each packet <=10^6
Sample Input
1
7 3
10 100 300 200 1000 20 30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.
*/

#include <bits/stdc++.h>

using namespace std;

long long int solve(int arr[], int n, int k)
{
    sort(arr,arr+n);
    vector<long long> sum(n+1,0);
    long long curr=0,ans;
    sum[0] = 0;
    for(int i=0;i<n;i++)
    {
        sum[i+1] = sum[i] + arr[i];
    }
    for(int i=0;i<k;i++)
    {
        curr += (1ll*i*arr[i]-sum[i]);
    }
    ans = curr;
    for(int i=k;i<n;i++)
    {
        curr = curr-2ll*(sum[i]-sum[i-k+1]) + 1ll*(k-1)*(arr[i]+arr[i-k]);
        ans = min(ans,curr);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n,k)<<endl;
    }
}
