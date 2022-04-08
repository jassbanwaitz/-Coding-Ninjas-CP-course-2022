/*
Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings 't' with length equal to that of 's', also consisting of upper case alphabets are there satisfying the following conditions:
-> String 't' is lexicographical larger than string 's'.
-> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.
Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.
Input Format:
First line will contain T(number of test cases).
Each test case consists of a single line containing the string s.
Output Format:
For each test case output the number of strings (t) %(10^9 + 7) in new line.
Constraints:
1 <= T <= 50
1 <= |S| <= 10^5
Sample Input:
2
A
XKS
Sample output:
25
523
*/

#include <bits/stdc++.h>
	using namespace std;

	int mod = 1e9 + 7;

	int countStrings(string &s)
	{

		int n = s.size();
		long long int req = 0, dp[n + 1], arr[n + 1], ans = 0;

		for (int i = 0; i < n; i++)
		{
			arr[i] = ('Z' - s[i]);
		}

		dp[n - 1] = arr[n - 1];

		for (int i = n - 2; i >= 0; i--)
		{

			req = (arr[i + 1] + (26ll * req) % mod) % mod;

			dp[i] = (arr[i] + (arr[i] * req) % mod) % mod;
		}

		for (int i = 0; i < n; i++)
		{

			ans = (ans + dp[i]) % mod;
		}

		return ans;
	}

	int main()
	{
		int t;
		cin >> t;
		while (t--)
		{
			string s;
			cin >> s;
			cout << countStrings(s) << endl;
		}
    }
