/*
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input Format:
First line will contain T (number of test case).
Each input is consists of a single line containing the message string
Output Format:
For each test case print the answer % mod (10^9 +7)
Constraints:
1 <= T <= 100
1 <= |S| <= 10^5
sum of length of all string doesn't exceed 5*10^6
Sample Input 1:
3
47974
6349988978
1001
Sample Output 1:
1
1
0
*/

#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int solve(string &s)
{
    int n = s.size();
    int arr[n+1];
    arr[0] = 1;
    for(int i=1;i<n;i++)
    {
        arr[i] = 0;
        int x = (s[i-1]-'0')*10+s[i]-'0';
        
        if(s[i]!='0')
            arr[i] = arr[i-1];
        
        if(x>=10 && x<=26 && i>1)
            arr[i] = (arr[i] + arr[i-2]) % mod;
        
        else if(x>=10 && x<=26)
            arr[i]++;
        
        arr[i] = arr[i] % mod;
    } 
    return arr[n-1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ans = solve(s);
        cout<<ans<<endl;
    }
}



