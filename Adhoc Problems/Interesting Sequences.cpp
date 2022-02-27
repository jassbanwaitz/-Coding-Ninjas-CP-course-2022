/*
Professor Jain has a class full of notorious students. To get anything done from them is a herculean task. Prof Jain wanted to organize a test. He gave this responsibility to Aahad. Aahad did an excellent job of organizing the test. As a reward, the professor gave him an sequence of numbers to play with. But Aahad likes playing with "interesting" sequence of numbers, which are sequences that have equal elements.
Now, the problem is - Prof Jain has a sequence of numbers, but that sequence isn't always "interesting”. To ensure sequence has equal elements, Prof Jain has 2 options:
1) Choose two elements of sequence. Decrease the first element by 1 and increase the second element by 1. This operation costs 'k' coins.
2) Choose one element of array and increase it by 1. This operation costs 'l' coins.
You have to find the minimum number of coins that Prof Jain needs to turn his sequence into a “interesting" sequence for Aahad?
Input Format
The first line of input contains three space-separated integers: n, k, l. Integer n is the size of array. Integer k is the number of coins needed to perform the first operation. Integer l is the number of coins needed to perform the second operation.

The second line of input contains n space separated integers: (a1, a2, a3... an), that denote the numbers of the sequence.
Constraints:
1 <= n <= 1000
1 <= k, I <= 10^9
1 <= a[i] <= 1000
Time Limit: 1 second
Output Format
The first and only line of output prints an integer, that denotes minimum number of coins required to make "interesting" sequence.
Sample Input 1:
4 1 2
3 4 2 2
Sample Output 1:
3
Explanation Output 1 :
The professor has a sequence with 4 elements. To perform the first operation, he must pay 1 coin and to perform the second operation, he must pay 2 coins. The optimal strategy is:

-Perform the second operation on the fourth element. Now the sequence is {3, 4, 2, 3}. This costs 2 coins.

-Perform the first operation on the second and third element. The sequence is now "interesting", and it looks like {3, 3, 3, 3}. This costs 1 coin. 

The total amount of coins needed is 2 + 1 = 3.
Sample Input 2:
3 2 1
5 5 5
Sample Output 2:
0
Explanation Output 2 :
The given sequence is already "interesting". The professor would spend 0 coins.
Sample Input 3:
5 2 1
1 2 3 4 5
Sample Output 3:
6
Explanation Output 3 :
The professor has a sequence with 5 elements. To perform the first operation, he must pay 2 coins and to perform the second operation, he must pay 1 coin. The optimal strategy is:

-Perform the first operation on the first and last element. Now the sequence is {2, 2, 3, 4, 4}. This costs 2 coins.

-Perform the first operation again on the first and last element. Now the sequence is {3, 2, 3, 4, 3}. This costs 2 coins.

-Perform the first operation on the second and second last element. Now the sequence is {3, 3, 3, 3, 3}. This costs 2 coins.

The total amount of coins needed is 2 + 2 + 2 = 6.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int minCost(const vector<int>& a, const int& k, const int& l, int curr) {
	int inc = 0, dec = 0;
	for(int x : a) {
		if(curr > x) {
			inc += (curr - x);
		}
		else {
			dec += (x - curr);
		}
	}
	if(inc >= dec) {
		return (dec * k) + ((inc - dec) * l);
	}
	return (int) 1e15;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int k, l; cin >> k >> l;

	vector<int> a(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> a[i];
	}

	int rangeMax = *max_element(a.begin(), a.end());
	int rangeMin = *min_element(a.begin(), a.end());

	int ans = (int) 1e15;
	for(int i = rangeMin ; i <= rangeMax ; ++i) {
		ans = min(ans, minCost(a, k, l, i));
	}

	cout << ans << '\n';
	return 0;
}
