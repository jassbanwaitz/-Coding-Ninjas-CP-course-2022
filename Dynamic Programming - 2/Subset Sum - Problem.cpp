/*
Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First-line will contain T(number of test cases), each test case consists of three lines. 
First-line contains a single integer N(length of input array).
Second-line contains n space-separated integers denoting the elements of array.
The last line contains a single positive integer k.
Output Format
Output Yes if there exists a subset whose sum is k, else output No for each test case in new line.
Constraints:
1 <= T <= 100
1 <= N <= 500
1 <= arr[i] <= 10^4
1 <= K <= 500
Sample Input
1
3
1 2 3
4
Sample Output
Yes
*/

#include <iostream>
#include <vector>
using namespace std;

bool targetSumSubset(int n, vector<int> arr, int tar) {
    bool dp[n+1][tar+1]={true};
    for(int i=0;i<n+1;i++){
        for(int j=0;j<tar+1;j++){
            if(i==0 and j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(j==0){
                dp[i][j]=true;
            }
            else{
                if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }
                else{
                    int val=arr[i-1];
                    if(j>=val){
                        if(dp[i-1][j-val]==true){
                            dp[i][j]=true;
                        }
                    }
                }
            }
        }
    }
   return dp[arr.size()][tar];
}


int main() {
    int t;
    cin>>t;
    while(t--){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int tar;
  cin >> tar;
bool a=  targetSumSubset(n, arr, tar);
if(a==1){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
}
}
