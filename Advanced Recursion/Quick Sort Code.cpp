/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
First line will contain T number of test case and each tet case will consist of two lines.
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
for every test case print rray elements in increasing order (separated by space) in a new line.
Constraints :
1 <= T <= 10
1 <= n <= 10^5
0 <= arr[i] <= 10^9
Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
1
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int partition(vector<int>& a, int left, int right) {
	int previousIndex = left - 1;
	for(int i = left ; i < right ; ++i) {
		if(a[i] < a[right]) {
			++previousIndex;
			swap(a[i], a[previousIndex]);
		}
	}
	swap(a[previousIndex+1], a[right]);
	return previousIndex+1;
}

void divide(vector<int>& a, int left, int right) {
	if(left < right) {
		int pivot = partition(a, left, right);
		divide(a, left, pivot-1);
		divide(a, pivot+1, right);
	}
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}

		divide(a, 0, n-1);

		for(int i = 0 ; i < n ; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
