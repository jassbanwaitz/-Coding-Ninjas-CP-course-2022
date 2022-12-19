#include<bits/stdc++.h>
using namespace std;
vector<int> waveFormArray(vector<int> &arr, int n) {
    sort(arr.rbegin() , arr.rend());

    for(int i = 1; i <= n-2; i+=2){
        swap(arr[i],arr[i + 1]);
    }


    return arr;
    // Write your code here.
}
/*

    1   2   2   3   4   5

    0   1   2   3   4   5
    5   4   3   2   2   1

    0   1   2   3   4   5
    5   3   4   2   2   1

    // Reverse sort the numbers (sort in descending order)
    // start from index 1 swap i and i + 1 by jumping from i + 2 every time


*/
