#include<bits/stdc++.h>
using namespace std;
int main(){
    
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            if(mini>abs(arr[i-1]-arr[i]))
                mini=abs(arr[i-1]-arr[i]);

               }
               cout<<mini<<endl;
               }
    return 0;
}
