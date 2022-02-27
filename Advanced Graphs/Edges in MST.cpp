/*
You are given a connected weighted undirected graph without any loops and multiple edges.
Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.
Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input Format:
The first line contains two space-separated integers n and m — the number of the graph's vertexes and edges, correspondingly.
 Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi", where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight.
Output Format:
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Constraints:
 1 <= N, M <= 10^5
 1 <= a, b <= N
 1 <= w[i] <= 10^6
 Graph is connected and does not contain self loops and multiple edges.
Sample Input:
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
Sample Output:
none
any
at least one
at least one
any
*/

#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5+5;

int src[N], dst[N], val[N], idx[N];
int ans[N], visited[N], depth[N];
int parent[N], r[N];

vector<vector<pair<int, int>>> graph(N);



void make_set() {
    for(int i = 0 ; i < N ; ++i) {
        r[i] = 0;
        parent[i] = i;
    }
}


int get_parent(int x) {
    while(x != parent[x]) {
        x = parent[x];
    }
    return x;
}


void union_set(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    graph[x].clear();
    graph[y].clear();
    visited[x] = visited[y] = false;
    
   
    if(x != y) {
        if(r[x] == r[y]) ++r[x];
        if(r[x] < r[y]) swap(x, y);
        parent[y] = x;
    }
}


void kruskal(int v, int index, int h) {
    visited[v] = true;
    depth[v] = h;
    
    for(pair<int, int> p : graph[v]) {
        
        if(!visited[p.first]) {
            kruskal(p.first, p.second, h+1);
            depth[v] = min(depth[v], depth[p.first]);
        }
        
        else if(p.second != index) {
            depth[v] = min(depth[v], depth[p.first]);
        }
    }
    
    if(depth[v] == h) ans[index] = 2;
}

int main()
{
	
    int n, m;
    cin >> n >> m;
    
    
    for(int i = 1 ; i <= m ; i++) {
        cin >> src[i] >> dst[i] >> val[i];
        idx[i] = i;
    }
    
    sort(idx+1, idx+m+1, [&](int x, int y) {
        return val[x] < val[y];
    });
    
    
    make_set();
  	
    for(int i = 1 ; i <= m ; ) {
        int j = i;
       
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            int set1 = get_parent(src[idx[j]]);
            int set2 = get_parent(dst[idx[j]]);
            if(set1 != set2) {
                ans[idx[j]] = 1; 
                graph[set1].push_back({set2, idx[j]});
                graph[set2].push_back({set1, idx[j]});
            }
        }
        
    
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            int v = get_parent(src[idx[j]]);
            if(!visited[v]) {
                kruskal(v, 0, 0);
            }
        }
        
       
        for(j = i ; val[idx[i]] == val[idx[j]] ; ++j) {
            union_set(src[idx[j]], dst[idx[j]]);
        }
        
        i = j;
    }
    
   
    for(int i = 1 ; i <= m ; ++i) {
        if(ans[i] == 0) cout << "none" << endl;
        else if(ans[i] == 1) cout << "at least one" << endl;
        else cout << "any" << endl;
    }
	
    return 0;
}
