/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input Format:
The first line contains T, number of test cases.
T lines follow each containing the number N.
Output Format:
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500
0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/

#include<bits/stdc++.h>
#define m 1000000007
using namespace std;
void fact_divisor(int n){
    bool *prime=new bool[n+1];
    for(long long i=0;i<n+1;i++){
        prime[i]=true;
    }
 
    prime[0]=false;
    prime[1]=false;
    for(long long i=2;i<=sqrt(n);i++){
        if(prime[i]){
            for(long long j=i;j*i<=n;j++){
                prime[j*i]=false;
            }
        }
    }
    
  
    
    long long divisor=1;
    for(long long i=0;i<=n;i++){
        if(prime[i]){
            long long sum=0;
            for(long long j=1;pow(i,j)<=n;j++){
                sum+=n/pow(i,j);
            }
            divisor=(divisor%m*(sum+1)%m)%m;
        }
    }
    cout<<divisor<<endl;
    
}
int main(){

    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        fact_divisor(n);
    }
    return 0;
}
