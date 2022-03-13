/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output Format:
Output a single integer, maximum sum rectangle for each test case in a newline.
Constraints
1 <= T <= 50
1<=n,m<=100
-10^5 <= mat[i][j] <= 10^5
Sample Input
1
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int>v,int n){
    int ma=INT_MIN;
    int u=0;
    for(int i=0;i<n;i++){
        u+=v[i];
        if(u>ma){
            ma=u;
        }
        if(u<0){
            u=0;
        }
    }
    return ma;
}
int main(){
    
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>mat(n,vector<int>(m));
   		for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
    	}
        
        
        int ma=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>ans(m);
            for(int j=i;j<n;j++){
                for(int col=0;col<m;col++) {
                    ans[col]+=mat[j][col];
                }
                ma=max(ma,kadane(ans,m));
            }
        }
        cout<<ma<<endl;
        
    	}
    return 0;
}
