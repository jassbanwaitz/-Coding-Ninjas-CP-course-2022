/*
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 10
8
Sample Output 1 :
true
Sample Input 2 :
3
9 8 10
2
Sample Output 2 :
false
*/

#include<bits/stdc++.h>
using namespace std;

bool checkNumber(int a[],int n,int val) {
    // base
    if(n==1) return a[0]==val;
    if(a[0]==val){
        return true;
    }
    return checkNumber(a+1,n-1,val);
}
