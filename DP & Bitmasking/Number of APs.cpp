/*
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 10^9 + 7.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:
First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.
Output:
 Print total number of subsequences
Input Constraints:
1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000
Sample Input 1 :
3
1 2 3
Sample output:
8
Sample Output Explanation:
Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }
Sample Input 2:
7
1 2 3 4 5 9 10
Sample Output:
37
*/
#include <bits/stdc++.h>
	using namespace std;

	int mod = 1e9 + 7;
	int numofAP(int arr[], int n)
	{

		int minElem = *min_element(arr, arr + n);
		int maxElem = *max_element(arr, arr + n);

		int totalAPs = n + 1;
		int sum[1001];
        //CODE BY KAMAL CHAUHAN
		for (int d = (minElem - maxElem); d <= (maxElem - minElem); d++)
		{
			memset(sum, 0, sizeof(sum));

			for (int i = 0; i < n; i++)
			{
				int a = 1;
				if (arr[i] - d >= 1 && arr[i] - d <= 1000)

					a = (a + sum[arr[i] - d]) % mod;

				totalAPs = ((totalAPs + a - 1) % mod + mod) % mod;
				sum[arr[i]] = (sum[arr[i]] + a) % mod;
			}
		}
		return totalAPs;
	}
	int main()
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << numofAP(arr, n);
        }
