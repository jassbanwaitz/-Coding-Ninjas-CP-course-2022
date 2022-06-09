#include<iostream>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
bool sortfinish(const pair<int,int> &a,
              const pair<int,int> &b)
{
    double r1=(double)a.first/a.second;
    double r2=(double)b.first/b.second;
    return r1>r2;
}
int main()
{
   int n;
   cin>>n;
    double W;
    cin>>W;
   vector<pair<double,double>> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr.at(i).first;
       cin>>arr.at(i).second;
   }
  
   sort(arr.begin(), arr.end(), sortfinish);
   double ans=0;
    double curWeight = 0; 
    double finalvalue = 0;
	for(int i=0;i<n;i++){
    if(curWeight+arr.at(i).second <=W){
        curWeight+=arr.at(i).second;
        finalvalue+=arr.at(i).first;
    }
    else{
        double remain = W - curWeight;
            finalvalue += arr.at(i).first
                          * ((double)remain
                             / (double)arr.at(i).second);
            break;
    }
   }
  
  
   cout<<fixed<<setprecision(6)<<finalvalue;
   return 0;
}
