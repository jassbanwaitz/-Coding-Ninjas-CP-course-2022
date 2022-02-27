/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Note: Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
1 <= W <= 1000
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include<iostream>
using namespace std;
typedef long long ll;



// this solution is not space optimized, will not pass some test cases
ll helper_(int* weights, int* values, int n, int maxWeight,ll **storage){

    // base cases
    if(n<0){
      return 0;
    }

    // if work already done
    if(storage[n][maxWeight]!=-1){
      return storage[n][maxWeight];
    }

    // if including possible
    if(weights[n]<=maxWeight){

      // including last num
      ll inc=values[n]+helper_(weights,values,n-1,maxWeight-weights[n],storage);
      // not including last num
      ll notinc=helper_(weights,values,n-1,maxWeight,storage);
      ll ans=max(inc,notinc);
      storage[n][maxWeight]=ans;
      return ans;

    }else{

      ll ans=helper_(weights,values,n-1,maxWeight,storage);
      storage[n][maxWeight]=ans;
      return ans;

    }
}

int knapsack(int* weights, int* values, int n, int maxWeight){
	ll **storage=new ll*[n+1];
	for(int i=0;i<=n;i++){
	  storage[i]=new ll[maxWeight+1];
	}
	for(int i=0;i<=n;i++){
	  for(int j=0;j<=maxWeight;j++){
	    storage[i][j]=-1;
	  }
	}
    ll ans=helper_(weights,values,n-1,maxWeight,storage);
    ans=(int)ans;
    for(int i=0;i<=n;i++){
        delete storage[i];
    }
    delete storage;
    return ans;
}

int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}

