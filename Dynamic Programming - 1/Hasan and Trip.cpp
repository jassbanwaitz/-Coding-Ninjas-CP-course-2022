/*
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line will contain T(number of test case).
First line of each test case will contain an integer N 
Next N lines of that test case will contain three space-separated integers Xi, Yi, Fi (coordinates and happiness)
Output format:
For each test Output one number rounded to 6 digits after floating point, the maximum possible happiness in newline, Hasan can get. 
Note: If answer is 2 print 2.000000
Constraints:
1 <= T <= 50
1 <= N <= 500
0 <= Xi, Yi, Fi <= 100,000
Sample Input
1
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
*/
#include <bits/stdc++.h>
using namespace std;
double inf = 1e15;

double disc(pair<double, double> p1, pair<double, double> p2)
{
    double a, b;
    a = (p2.first - p1.first) * (p2.first - p1.first);
    b = (p2.second - p1.second) * (p2.second - p1.second);
    return sqrt(a+b);
}
void solve(pair<double, double> arr[], double happy[], int n)
{
    double dp[n];
    dp[0] = happy[0];
    for(int i=1;i<n;i++)
    {
        dp[i] = -inf;
        for(int j=0;j<i;j++)
        {
            double x = disc(arr[i], arr[j]);
            dp[i] = max(dp[i], dp[j]-x);
        }
        dp[i] += happy[i];
    }
    cout<<fixed;
    cout<<setprecision(6)<<dp[n-1]<<endl;
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair<double, double> arr[n];
        double a,b;
        double happy[n];
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            arr[i] = make_pair(a,b);
            cin>>happy[i];
        }
        solve(arr,happy,n);
    }
}
