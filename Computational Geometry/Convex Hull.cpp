/*
Given a set of points in the plane, the Convex Hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.
Input Format:
First line of input contains integer N, representing number of points.
Second line contains N space separated integers, which are the X coordinates.
Third line contains N space separated integers, which are the Y coordinates.
Constraints:
1 <= N <= 10^5
1 <= X[i] <= 10^4
1 <= Y[i] <= 10^4
Also input is given in such a way that the number of points on the hull doesn't exceed 50
Output Format:
Print the X coordinate and the Y coordinate of all the points seperated by space. Order doesn't matter.
Sample Input:
5
2 1 7 9 7 
2 5 5 2 4 
Sample Output:
1 5
2 2
9 2
7 5
*/

#include <bits/stdc++.h> 
using namespace std; 
  
struct Point 
{ 
    int x, y; 
}; 

int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
} 
  

void convexHull(Point points[], int n) 
{ 
 
    if (n < 3) return; 
  
    vector<Point> hull; 
  
 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
  
   
    int p = l, q; 
    do
    { 
        
        hull.push_back(points[p]); 
  
       
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           
           if (orientation(points[p], points[i], points[q]) == 2) 
               q = i; 
        } 
  
        
        p = q; 
  
    } while (p != l);  
  
    
    for (int i = 0; i < hull.size(); i++) 
        cout << hull[i].x << " " << hull[i].y << "\n"; 
} 

int main() 
{ 
    int n; 
    cin >> n;
    Point points[n];
    
    for(int i=0 ; i<n ; i++) cin >> points[i].x;
    for(int i=0 ; i<n ; i++) cin >> points[i].y;
    
    convexHull(points, n); 
    return 0; 
}
