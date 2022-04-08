/*
Abhishek, a blind man recently bought N binary strings all of equal length .A binary string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek can identify one character at a position of a string from the set. Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different .
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Line1: contain an integer N (number of strings)
Next N line contain binary strings.
Output Format:
For each test case print the answer in newline.
Constraints:
1 <= T <= 50
1 <= N <= 10
1 <= |S| <= 100 
Sample Input :
1
2
111010
100100
Sample Output :
2
*/
#include <bits/stdc++.h>
using namespace std;

int dp[105][1 << 12];

int find_touches(int pos, int mask, vector<string> &v)
{
    if (!(mask & (mask - 1)) && mask)
    {
        return 0;
    }

    if (pos == -1 || mask == 0)
    {
        return 1000000;
    }

    if (dp[pos][mask])
    {
        return dp[pos][mask];
    }

    int newmask1 = 0, newmask2 = 0, touches = 0;

    for (int i = 0; i < v.size(); i++)
    {

        if ((mask >> i) & 1)
        {
            touches++;
            if (v[i][pos] == '0')
            {
                newmask1 |= (1 << i);
            }
            else
            {
                newmask2 |= (1 << i);
            }
        }
    }
    return dp[pos][mask] = min(find_touches(pos - 1, newmask1, v) + find_touches(pos - 1, newmask2, v) + touches, find_touches(pos - 1, mask, v));
}

int solve(int n, vector<string> v)
{
    return find_touches(v[0].size() - 1, (1 << n) - 1, v);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v;
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        cout << solve(n, v) << endl;
    }
}
