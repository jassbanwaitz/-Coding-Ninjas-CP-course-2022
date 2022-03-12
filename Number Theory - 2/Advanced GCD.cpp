/*
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and another integer can have 10^4 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input Format
The first line of input will contain T(number of the test case), each test case follows as.

Each test case consists of two number A and B.
Output Format:
Print for each pair (A,B) in the input one integer representing the GCD of A and B.
Constraints:
1 <= T <= 100
1 <= A <= 4*10^5
1 <= |B| <= 10^4
where |B| is the length of the integer B 
Sample Input:
2
2 6
10 11
Sample Output:
2
1
*/

#include<bits/stdc++.h>
using namespace std;
int gcdmain(int a ,int b){
    if(b==0){
        return a;
    }
    return gcdmain(b,a%b);
}

int mod(string num, int a)
{
    
    int res = 0;
 
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
 
    return res;
}
int gcd(int a,string b)
{
    
 int d=mod(b,a);
 int maxi=max(a,d);
 int mini=min(a,d);
 return gcdmain(maxi,mini);
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        string b;
        cin>>b;
        cout<<gcd(a,b)<<endl;
    }
    return 0;
}
