/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
First line of input will contain T number of test cases
First line of every input will contain a single integer N size of the input array.
second line of each input will contain N space-separated integers.
Output format :
For every test case print, array elements in increasing order (separated by space) in a separate line.
Constraints :
1 <= T <= 10
1 <= n <= 10^5
Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
1
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void merge(vector<int>& a, int left, int mid, int right) {
	vector<int> t;
	int i = left, j = mid+1;
	while(i <= mid && j <= right) {
		if(a[i] <= a[j]) {
			t.push_back(a[i++]);
		}
		else {
			t.push_back(a[j++]);
		}
	}
	while(i <= mid) {
		t.push_back(a[i++]);
	}
	while(j <= right) {
		t.push_back(a[j++]);
	}
	
	for(int i = left ; i <= right ; ++i) {
		a[i] = t[i-left];
	}
}

void divide(vector<int>& a, int left, int right) {
	if(left < right) {
		int mid = (right + left) / 2;
		divide(a, left, mid);
		divide(a, mid+1, right);
		merge(a, left, mid, right);
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
