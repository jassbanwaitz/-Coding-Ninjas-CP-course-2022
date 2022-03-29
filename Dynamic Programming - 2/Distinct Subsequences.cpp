/*
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input Format:
First line of input contains an integer T which is equal to the number of test cases.
Each of next T lines contains a string s.
Output Format:
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%(10^9 + 7) where ans is the number of distinct subsequences. 
Constraints:
T ≤ 100
1 <= length(S) ≤ 10^5
All input strings shall contain only uppercase letters.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll all_subseq(string s){
    int len=s.length();
    
    ll *dp=new ll[len+1];
    
    ll *previndice=new ll[26];
    for(int i=0;i<26;i++){
        previndice[i]=-1;
    }
   
    dp[0]=1;
    for(ll i=1;i<=len;i++){
        dp[i]=(dp[i-1]*2)%mod;
       
        if(previndice[s[i-1]-65]!=-1){
           
            dp[i]=(dp[i]-dp[previndice[s[i-1]-65]-1]+mod)%mod;
        }
       
    	previndice[s[i-1]-65]=i;
    }
    ll ans=dp[len]%mod;
    delete dp;
	delete previndice;
    return ans;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<string,int> m;
        cout<<all_subseq(s)<<endl;
       
    }
    return 0;
}
