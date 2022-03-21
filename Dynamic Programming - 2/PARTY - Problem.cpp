/*
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input Format:
First line of input will contain an integer N (number of parties).
Next line of input will contain N space-separated integers denoting the entry fee of Ith party.
Next line will contain N space-separated integers denoting the amount of fun Ith party provide.
Last line of input will contain an integer W party budget.
Output Format:
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
Note: In case of multiple cost provides the maximum fun output the minimum total cost.
Sample Input:
5
1 7 9 7 2 
5 5 2 4 7 
12
Sample Output:
10 17
*/

#include<iostream>
#include<utility>
using namespace std;
pair<int, int> most_fun(int* enterance_fees, int* fun, int budget, int n, pair<int, int>**dp)
{
	if (n == 0)
	{
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	if (dp[budget][n].first != -1 && dp[budget][n].second != -1)
	{
		return dp[budget][n];
	}
	pair<int, int> ans;
	if (enterance_fees[0] <= budget)
	{
		pair<int, int>option1 = most_fun(enterance_fees + 1, fun + 1, budget - enterance_fees[0], n - 1, dp);
		option1.first += enterance_fees[0];
		option1.second += fun[0];
		pair<int, int>option2 = most_fun(enterance_fees + 1, fun + 1, budget, n - 1, dp);
		if (option1.second > option2.second)
		{
			ans= option1;
		}
		else if (option2.second > option1.second)
		{
			ans= option2;
		}
		else
		{
			if (option1.first < option2.first)
			{
				ans= option1;
			}
			else
			{
				ans= option2;
			}
		}
	}
	else
	{
		ans= most_fun(enterance_fees + 1, fun + 1, budget, n - 1, dp);
	}
	dp[budget][n] = ans;
	return ans;
}
int main()
{
	while (true)
	{
		int budget;
		int n;
		cin >> n;
		if (budget == 0 && n == 0)
		{
			break;
		}
		int* enterance_fees = new int[n];
		int* fun = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> enterance_fees[i];
		}
	for(int i=0;i<n;i++){
        cin>> fun[i];
    }
		cin >> budget;
		
		pair<int, int>** dp = new pair<int, int> * [budget+1];
		for (int i = 0; i < budget+1; i++)
		{
			dp[i] = new pair<int, int>[n + 1];
			for (int j = 0; j < n + 1; j++)
			{
				dp[i][j].first = -1;
				dp[i][j].second = -1;
			}
		}


		pair<int, int> p;
		p = most_fun(enterance_fees, fun, budget, n, dp);
		cout << p.first << ' ' << p.second << endl;
        exit(0);



		for (int i = 0; i < budget + 1; i++)
		{
			delete[]dp[i];
		}
		delete[]dp;
	}
}
