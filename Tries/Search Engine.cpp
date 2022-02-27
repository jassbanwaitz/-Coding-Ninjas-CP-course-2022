/*
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
Input Format:
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. 
Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.
Next q lines follow, each line having a string t, which needs to be completed.
Constraints:
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
Total length of all strings in database entries ≤ 10^6
Total length of all query strings ≤ 10^6
Output Format:
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
Sample Input 1:
2 1
potential 10
potent 8
pot
Sample Output 1:
10
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

class Trie {
public:
	bool isEnd;
	int weight;
	unordered_map<char, Trie*> child;

	Trie() {
		child = {};
		weight = 0;
		isEnd = false;
	}
};

void insert(Trie* root, const string& s, int& wt) {
	Trie* current = root;
	for(char c : s) {
		if(!current->child.count(c)) {
			current->child[c] = new Trie();
		}
		current = current->child[c];
		current->weight = max(current->weight, wt);
	}
	current->isEnd = true;
}

int query(Trie* root, const string& s) {
	Trie* current = root;
	for(char c : s) {
		if(!current->child.count(c)) {
			return -1;
		}
		current = current->child[c];
	}
	
	int ans = -1;
	for(char c = 'a' ; c <= 'z' ; ++c) {
		if(current->child.count(c)) {
			ans = max(ans, current->child[c]->weight);
		}
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	Trie* root = new Trie();

	int n, q;
	cin >> n >> q;
	for(int i = 0 ; i < n ; ++i) {
		string s; cin >> s;
		int value; cin >> value;
		insert(root, s, value);
	}

	while(q--) {
		string s; cin >> s;
		cout << query(root, s) << '\n';
	}
	return 0;
}
