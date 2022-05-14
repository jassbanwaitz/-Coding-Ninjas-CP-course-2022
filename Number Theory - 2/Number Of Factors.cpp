/*
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Each test cases consists of a single line containing integers a, b, and n as described above.
Output Format:
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints:
1 <= T <= 10000
1 ≤ a ≤ b ≤ 10^6
0 <= b - a <= 100
0 ≤ n ≤ 10
Sample Input
4
1 3 1
1 10 2
1 10 3
1 100 3
Sample Output
2 
2
0
8
*/
#include <iostream>
using namespace std;
#include <iostream>
#include <math.h>
using namespace std;
void makeSieve(int *isprime, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        isprime[i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i] == 0)
            for (int j = 1; j * i <= n; j++)
            {
                isprime[j * i] += 1;
            }
    }
}
int main()
{
    int t;
    cin >> t;
    int *arr = new int[1000001];
    int **table=new int* [11];
    for(int i=0; i<11; i++)
    {
        table[i]=new int[10000001];
    }
    makeSieve(arr, 1000001);
    for(int i=0; i<11; i++)
    {
        table[i][0]=0;
        table[i][1]=0;
        for(int j=2; j<1000001; j++)
        {
            if(i==arr[j])
            {
                table[i][j]=table[i][j-1]+1;
            }
            else
            {
                table[i][j]=table[i][j-1];
            }
        }
    }
    for (int test_case = 1; test_case <= t; test_case++)
    {
        int a, b, n;
        cin>>a>>b>>n;
        if(a==1&&n==0)
        {
            cout<<1<<endl;
            continue;
        }
        cout<<table[n][b]-table[n][a-1]<<endl;
    }
}
