/*
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,s=0,p=0;
    int n=0;
    cin>>n;
    char * str = new char [n];
    cin>>str;
    for(int i=0;i<n;i++){
        if(str[i] =='a'){a++;}
        else if(str[i]=='s'){s++;}
        else if(str[i]=='p'){p++;}   
    }
    cout<<a<<" "<<s<<" "<<p;
	return 0;
}
