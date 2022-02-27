/*
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format:
First line of input contains an integer T, representing the number of test cases.
Next T lines contain an integer n.
Constraints:
1 <= T <= 10^4
1 <= N <= 10^6
Output Format:
Print the Grundy Number(n) for each test case in a new line.
Sample Input 1:
1
10
Sample Output 1:
0
*/

#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6+5;

int dp[N];

int getGrundy(int n) {
	if(n == 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    
	int a = getGrundy(n/2);
	int b = getGrundy(n/3);
	int c = getGrundy(n/6);
    
	int x=0;
	while(x == a || x == b || x == c) {
        ++x;
	}
    return dp[n] = x;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    memset(dp , -1, sizeof(dp));
    
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << getGrundy(n) << endl;
    }
	return 0;
}
