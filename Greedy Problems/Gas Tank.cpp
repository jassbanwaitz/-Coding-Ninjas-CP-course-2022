/*
You have a car with a gas tank of infinite capacity. There are ‘N’ gas stations along a circular route. Gas stations are numbered from 0 to N - 1. You begin the journey with an empty tank at one of the gas stations. You want to travel around the circular route once in the clockwise direction. I.e if you start to travel from station ‘i’, then you will go to i + 1, i + 2, …, n - 1, 0, 1, 2, i - 1 and then return back to ‘i’.
You are given two integer arrays ‘gas’ and ‘cost’. ‘gas[i]’ gives the amount of gas available at station ‘i’ and cost[i] gives the amount of gas required to travel from station ‘i’ to next station i.e station ‘i’+1 (or 0 if the station is N - 1).
Return the starting gas station's index if it is possible to complete cycle of given circular route once in the clockwise direction. If there are multiple possible starting gas station’s indexes, then return the minimum of those gas station indexes. If there is no such gas station then return -1.
Input Format :
The first line of input contains a single integer T, representing the number of test cases or queries to be run, then the T test cases follow.

The first line of each test case contains a positive integer 'N' which represents the number of gas stations.

The second line of each test case contains 'N' space-separated integers representing the integer array 'gas'.

The third line of each test case contains 'N' space-separated integers representing the integer array 'cost'.
Output Format :
For each test case, print a single integer denoting the minimum index of the starting gas station if you are able to travel around the cycle once, otherwise print -1.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraint :
1 <= T <=50
1 <= N <= 10 ^ 4
0 <= GAS[i] <= 10 ^ 5
0 <= COST[i] <= 10 ^ 5

Where GAS[i] represents the ith element of 'GAS' array,
COST[i] represents the ith element of 'COST' array.

Time Limit: 1 sec
Sample Input 1 :
1
2
1 2
2 1
Sample Output 1:
1
Explanation of Sample Input 1 :
Test Case 1:
If you start from index 0, you can fill in 1 unit of gas. Now your tank has 1 unit of gas. But you need 2 units of gas to travel to station 1. Thus you can not start at station 0.
If you start from index 1, you can fill in 2 units of gas. Now your tank has 2 units of gas. You need 1 unit of gas to get to station 0. So, you travel to station 0 and still have 1 unit of gas left. You fill in 1 unit of additional gas, making your current gas = 2 unit. It costs you 2 amounts of gas to get to station 1, which you do and complete the cycle. Thus you can start at index 1.
Sample Input 2 :
1
5
1 2 3 4 5
3 4 5 1 2
Sample Output 2:
3
*/

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    for(int i=0;i<n;i++)
    {
        if(gas[i]<cost[i])
        {
            continue;
        }
        int gasLeft = 0;
        int j=0;
        
        for(j=i;j<i+n;j++)
        {
            gasLeft += gas[j%n] - cost[j%n];
            
            if(gasLeft<0)
            {
                i = j%n;
                break;
            }
        }
        
        if(gasLeft >=0)
        {
            return i;
        }
        
        else if(j==i+n)
        {
            return -1;
        }
    }
    return -1;
}
