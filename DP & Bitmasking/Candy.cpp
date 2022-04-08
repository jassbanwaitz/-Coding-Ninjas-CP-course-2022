/*
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
The first line of input will contain T(number of test cases), each test case follows as.
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines: N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy, 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes for each test case in a new line.
Sample Input:
1
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
Explanation:
Since, all the students like all the candies, so, the candies can be distributed in the following 6 ways:
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int candies(int **like, int n, int person, int mask, int *dp)
{
    if (person >= n)
    {
        return 1;
    }
       
    if(dp[mask]!=-1) 
    {
        return dp[mask];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)) && like[person][i])
        {
            ans += candies(like, n, person + 1, mask | (1 << i), dp);
        }
    }
    dp[mask]=ans;
    return ans;
}
int solve(int **like,int n)
{
	int *dp = new int[1 << n];
    for (int i = 0; i < (1 << n); i++)
    {
        dp[i] = -1;  
    }
    int ans= candies(like, n, 0, 0, dp);
    delete[]dp;
    return ans;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int** like = new int*[n];
 
    	for (int i = 0; i < n; i++) {
 

        	like[i] = new int[n];
    	}
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>like[i][j];
            }
        }
        
        cout<<solve(like,n)<<endl;
    }
}
