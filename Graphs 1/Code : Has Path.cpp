/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
First line will contain T(number of test cases), each test case as follow.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false for each test case in a newline.
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include<bits/stdc++.h>
using namespace std;
bool haspath(int **arr,int v,bool *vis,int curr,int end){
    if(curr==end){
        return true;
    }
    for(int i=0;i<v;i++){
        if(!vis[i] and i!=curr and arr[curr][i]==1){
            vis[i]=true;
            if(haspath(arr,v,vis,i,end)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
	int v,e;
    cin>>v>>e;
    int **arr=new int*[v];
    for(int i=0;i<v;i++){
        arr[i]=new int[v];
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    bool *vis=new bool[v];
    for(int i=0;i<v;i++){
        vis[i]=0;
    }
    vis[v1]=true;
    if(haspath(arr,v,vis,v1,v2)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    }
    return 0;
}
