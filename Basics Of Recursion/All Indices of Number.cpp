/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/

#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
  
    static int isize=size;
    static int index=0;
    static int flag=0;
	//base
    if(size==0) {
        if(flag==1){
            return index;
        }
        return -1;
    }
    if(input[0]==x){
        output[index]=isize-size;
        index++;
        flag=1;
    }
    return allIndexes(input+1,size-1,x,output);
}
