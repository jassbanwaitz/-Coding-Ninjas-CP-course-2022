/*
Noor is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line and each of them has a score according to performance. Noor wants to give at least 1 chocolate to each student. She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
Note that when two students have equal score they are allowed to have different number of chocolates.
Input Format:
First line will contain T(number of test case), each test case consists of two lines.
First Line: Integer N, the number of students in Noor’s class. 
Second Line: Each of the student's score separated by spaces.
Output Format:
Output the minimum number of chocolates Noor must give for each test case in a newline.
Input Constraints
1 <= T <= 50
1 <= N <= 50000
1 <= score <= 10^9
Sample Input:
1
4
1 4 4 6
sample Output:
6
Explanation:
The number of chocolates distributed could be:
1 2 1 2
Sample Input:
1
3
8 7 5
sample Output:
6
*/

#include <iostream>
using namespace std;
int getMin(int arr[], int n){
    
    int dp[n];
    dp[0] = 1;
    int i=0;
    int sum = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i+1] && dp[i] <= dp[i + 1])
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += dp[i];
    }
    return sum;
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
        cout<<getMin(arr,n)<<endl;
    }
}
