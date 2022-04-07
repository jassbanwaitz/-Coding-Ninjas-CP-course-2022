/*
You are given an integer Ni. You need to make rightmost set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
The first line of input will contain T(number of test cases), each test case follows as.
A single integer N for each test case in a newline.
Output Format :
Updated N for each test case in a newline.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
Sample Input 1 :
1
4
Sample Output 1 :
0
Sample Input 2 :
1
12 
Sample Output 2 :
8
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count = 0;
        int ans;
        while(n != 0){
			if(n&1){
                ans = (n ^ 1);
                break;
            }
            else{
                // ans += pow(2 , count);
                count++;
            }
            n >>= 1;
        }
        for(int i=0;i<count;i++){
            ans <<= 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
