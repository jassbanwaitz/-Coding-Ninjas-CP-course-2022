/*
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
First line will contain T (number of test case), each test is consists of two lines. 
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence for each test case in a newline.
Input Constraints:
1 <= T <= 10
1<= N <= 5000
Sample Input 1:
1
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
1
2
1 5
Sample Output 2:
2
Sample Input 3:
1
2
5 1
Sample Output 3:
2
*/

#include <bits/stdc++.h>
using namespace std;
int longestBitonicSubsequence(int input[], int n)
{
        int incr[n];
        for(int i=0;i<n;i++)
        {
            incr[i] = 1;
        }
    
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((input[i] > input[j]) && (incr[i] < incr[j] + 1))
                {
                    incr[i] = incr[j] + 1;
                }
            }
        }
    
    int decr[n];
    for(int i=0;i<n;i++)
    {
        decr[i] = 1;
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if((input[i] > input[j]) && (decr[i] < decr[j] + 1))
            {
                decr[i] = decr[j] + 1;
            }
        }
    }
    
    int maxim = incr[0] + decr[0] - 1;
    for(int i=1;i<n;i++)
    {
        if(incr[i] + decr[i] - 1 > maxim)
        {
            maxim = incr[i] + decr[i] - 1;
        }
    }
    return maxim;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int ans = longestBitonicSubsequence(arr,n);
        cout<<ans<<endl;
    }
}
