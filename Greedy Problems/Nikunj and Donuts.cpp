# include<bits/stdc++.h>
using namespace std;

# define ll 	long long int

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n,greater<ll>());

        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ans += (arr[i]*pow(2,i));
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
