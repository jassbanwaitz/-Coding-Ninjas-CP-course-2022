/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Print "true" or "false" for each test case in new line
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
1
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
1
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include<bits/stdc++.h>
using namespace std;

void Is_connect(int **arr,int v,int curr,bool *vis)
{
    queue<int>q;
    vis[curr]=true;
    q.push(curr);
    while(!q.empty()){
        int current=q.front();
        for(int i=0;i<v;i++){
            if(!vis[i] and i!=current and arr[current][i]==1){
                q.push(i);
                vis[i]=true;
            }
        }
        q.pop();
    }
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
        bool *vis=new bool[v];
        for(int i=0;i<v;i++){
            vis[i]=false;
        }
        Is_connect(arr,v,0,vis);
        int check=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                check=1;
                cout<<"false"<<endl;
                break;
            }
        }
        if(check==0){
            cout<<"true"<<endl;
        }
        
        
    }


    return 0;
}
