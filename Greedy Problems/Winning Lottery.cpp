#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int s;
        cin>>s;
        int d;
        cin>>d;
        int arr[d];
        for(int i=0;i<d;i++){
            arr[i]=0;
        }
        arr[0]=1;
        int sum=s-1;
        int i=d-1;
        while (i > 0)
	{
		if (i == 0)
		{
			arr[i] += sum;
		}
		if (sum > 9)
		{
			arr[i] = 9;
			sum -= 9;
		}
		else if (sum <= 9)
		{
			arr[i] += sum;
			sum = 0;
		}
		i--;
	}
        
        arr[i] = sum + 1;
        for(int i=0;i<d;i++){
            cout<<arr[i];
        }
        cout<<endl;
        
    }
    
    return 0;
}
