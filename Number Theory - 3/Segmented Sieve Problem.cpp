/*
In this problem you have to print all primes from given interval.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.

On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval.
Output Format:
For each test case output must contain all primes from interval [L; U] in increasing order.
Constraints:
1  <= T <= 100
1 <= L <= U <= 10^9
0 <= U - L <= 10^5
Sample Input:
2
2 10
3 7
Sample Output:
2 3 5 7
3 5 7 
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n=1000000000;
    long long size=sqrt(n);
    bool arr[size];
    //cout<<size<<endl;
    arr[0]=false;
    arr[1]=false;
    for(long long i=2;i<=size;i++)
    {
        arr[i]=true;
    }
    for(long long i=2;i<=size;i++)
    {
        for(long long j=i*i;j<=size;j+=i)
        {
            arr[j]=false;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        long long l,u;
        cin>>l>>u;
        bool isPrime[u-l+1];
        for(int i=0;i<=u-l;i++)
        {
            isPrime[i]=true;
        }
        if(u>size)
        {
            for(long long i=2;i<=size;i++)
            {
                if(i*i>u)
                {
                    break;
                }
                if(arr[i]==true)
                {
                    long long base=(l/i)*i;
                    if(base<l)
                    {
                        base=base+i;
                    }
                     for(long long j=base;j<=u;j+=i)
                	{
                    isPrime[j-l]=false;
                	}
                    if(base==i)
                    {
                        isPrime[base-l]=true;
                    }
                }
            }
            for(long long i=0;i<=(u-l);i++)
            {
                if(isPrime[i]==true)
                {
                    cout<<i+l<<" ";
                }
            }
        }
        else
        {
            for(long long i=l;i<=u;i++)
            {
                if(arr[i]==true)
                {
                    cout<<i<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
