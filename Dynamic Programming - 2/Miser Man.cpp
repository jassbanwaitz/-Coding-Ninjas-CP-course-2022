/*
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
Input Format:
First-line will contain T(number of the test case), each test case follows as.
First-line will contain two space-separated integers N and M.
Next, N rows will contain M space-separated integers denoting the elements of the grid.
Each row lists the fares the M busses to go form the current city to the next city.
Output Format:
For each test case print the minimum amount of fare that Jack has to give in a newline.
Constraints:
1 <= T <= 100
1 <= N, M <= 100
1 <= arr[i][j] <= 10^5
Sample Input
1
5 5
1 3 1 2 6
10 2 5 4 15
10 9 6 7 1
2 7 1 5 3
8 2 6 1 9
Sample Output
10
Explanation:
1 -> 4 -> 1 -> 3 -> 1: 10
This is marked and shown in the following image: 
*/

#include<bits/stdc++.h>
using namespace std;

int save[105][105];

int main()
{
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	int i,j;
    
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>save[i][j];
	int res[n][m];
	for(i=0;i<m;i++)
		res[0][i]=save[0][i];
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int l,u,r;
			l=(j>0)?(res[i-1][j-1]):INT_MAX;

			u=res[i-1][j];
			r=(j<m-1)?res[i-1][j+1]:INT_MAX;
			res[i][j]=save[i][j]+min(u,min(l,r));
		}
	}
	int ans=INT_MAX;
	for(i=0;i<m;i++)
		if(res[n-1][i]<ans)
			ans=res[n-1][i];
	cout<<ans<<endl;}
	return 0;
}
