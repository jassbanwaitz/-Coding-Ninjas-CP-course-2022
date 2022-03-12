/*
Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
An Integer N
Output Format :
Required sum for each test case in newline.
Constraints :
1 <= T <= 10^4
1 <= n <= 10^5
Sample Input 1 :
1
5
Sample Output 1 :
55
Sample Input 2 :
1
2
Sample Output 2 :
4
*/

#include<bits/stdc++.h>
using namespace std;
unsigned long long int phi(unsigned long long int n)
{
	unsigned long long int result = n;
	for (unsigned long long int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
		while (n % i == 0) 		
			n /= i;
        
		result = (result*(i-1))/i;
		}
	}
	if (n > 1)
		result = (result*(n-1))/n;
	return result;
}

int main(){
    
    
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> divisors;
         for (long long i=2; i<=sqrt(n); i++)
    	{
        	if (n%i == 0)
        	{
            	
            	if (n/i == i)
                {
                    divisors.push_back(i);
                }
 				else
                {
                 divisors.push_back(i);
                    divisors.push_back(n/i);
                }
        }
    }
        unsigned long long int sum=0;
        for(int i=0;i<divisors.size();i++)
        {
            sum=(sum+(phi(n/divisors[i])*((n*n)/divisors[i])));
        }
        sum=(sum+(phi(n)*(n*n)));
        sum=(sum+2*n);
        sum=sum/2;
        cout<<sum<<endl;
        
    }
    return 0;
}
