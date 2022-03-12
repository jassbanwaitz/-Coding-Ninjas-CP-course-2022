/*

A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Note: we will consider 1 as the 1st cube free number
Input Format:
First line of the test case will be the number of test case T 
Each test case contain an integer N
Output Format:
For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^6
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
1
2
3
4
5
6
7
Not Cube Free
8
9
*/

#include<bits/stdc++.h>
using namespace std;
void cubic(int arr[]){
    for(int i=0;i<1000001;i++){
        arr[i]=0;
    }
    arr[1]=1;
    for(int i=2;i<=100;i++){
        int cube=i*i*i;
        for(int j=1;cube*j<1000001;j++){
            arr[cube*j]=-1;
            
        }
    }

    
    int k=1;
    for(int i=1;i<1000001;i++){
        if(arr[i]!=-1){
            arr[i]=k;
            k++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[1000001];
    cubic(arr);
    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        if(arr[val]!=-1){
            cout<<arr[val]<<endl;
        }
        else{
            cout<<"Not Cube Free"<<endl;
        }
    }
    
    return 0;
}
