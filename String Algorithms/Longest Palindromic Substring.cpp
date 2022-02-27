/*
You are given a string S .You have to find the length of the longest palindromic substring of S.
Input Format:
First line of input contains the string S.
Constraints:
1 <= |S| <= 4*10^6
Output Format:
You have to print the length of longest palindromic substring
Sample Input 1:
zkpbhxkmauuamkxsyi
Sample Output 1:
10
Explanation:
In the given sample test case, the longest palindromic substring is: xkmauuamkx.
*/

#include <iostream>
#include <string>
using namespace std;
int lps(string s)
{
    int max=0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        //odd length
        int left=i;
        int right=i;
        while(right<n&&left>=0&&s[left]==s[right])
        {
            int current_length=right-left+1;
            if(current_length>max)
            {
                max=current_length;
            }
            left--;
            right++;
        }
        //even length
        left=i;
        right=i+1;
        while(left>=0&&right<n&&s[left]==s[right])
        {
            int current_length=right-left+1;
            if(current_length>max)
            {
                max=current_length;
            }
            left--;
            right++;
        }
    }
    return max;
}
int main()
{
    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}
