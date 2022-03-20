/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
First line will contain T(number of test case), each test case consists of a single line containing an integer N.
Output Format :
For each test case print the required minimum count in a newline.
Constraints :
 1 <= T <= 1000
 1 <= N <= 1000
Sample Input 1 :
1
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
1
9
Sample Output 2 :
1
*/

#include <bits/stdc++.h>

using namespace std;

int minCount(int n)
{
    
	int dp[n+1];
    
	dp[0] = 0;
	dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
    	dp[i] = INT_MAX;
    	for (int j = 1; i-(j*j) >= 0; ++j)
    	{
    		dp[i] = min(dp[i],dp[i-(j*j)]);
    	}
    	dp[i] +=1;	
    }

    return dp[n];
	
}

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<minCount(n)<<endl;
    }
	 
}
