/*A recent non violent protest in Uptown Plaza took a drastic turn as a bomb was blasted by some resurgent. Ninja Investigations was hired to determine the responsible party. Using advanced satellite systems and GPS tracking of cell phones, the investigators determined the coordinates of every person in the plaza. Using some advanced algorithms, the investigative team has also determined the approximated coordinates of the bomb and the vicinity in which a person had to be if he planted the bomb. You have been given a very important task - narrow down the suspect pool. To do this, you have to find out whether a given person was in the vicinity of the bomb. Also print the probability that they planted the bomb. The probability can be calculated using the following formula:
100 - (distance of point to be checked with approx coordinates of bomb /  total area of the vicinity).
Note: A person in the plaza may not be carrying a phone and their coordinates might be unknown. But we can disregard such people, because the bomb was cell phone triggered, hence it would be impossible for a person not carrying the phone to plant and trigger the bomb.
Note: Get the answer of distance and area in double, then typecast it in int. Print probability in int also.
Input Format:
First line contains integer t, representing the number of test cases.
For each test case
Line 1: contains integer n, number of vertices of vicinity.
Next n lines contain coordinates of vertices of vicinity.
Next line contains approximate coordinates of the bomb.
Next line contains integer q, number of coordinates to be checked.
Next q lines contain coordinates of the people to be checked.
Output Format:
For each test case, print “Yes” if the person is present in the vicinity of the bomb and the probability that he planted the bomb in the next line, otherwise print “No”.
Sample Case 1:
1
3
1 10
9 1
10 7
5 6
2
8 6
8 8
Sample Output 1:
Yes
90
No
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 50000
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

struct Point
{
    double x,y;
    Point() {}
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
    double cross(Point p)
    {
        return x*p.y - y*p.x;
    }
    double distance(Point p)
    {
        double dis = sqrt((pow(p.x - x, 2.0) + pow(p.y - y,2.0)) * 1.0);
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2) * 1.0);
    }
};

double polygonArea(Point arr[], int n)
{
    double a = arr[n - 1].cross(arr[0]);
    
    for(int i=0;i<int(n) - 1;i++)
    {
        a += arr[i].cross(arr[i + 1]);
    }
    return a/2;
}

int probability(Point arr[], int n, Point p, Point app)
{
    int area = polygonArea(arr, n);
    int dis = app.distance(p);
    int prob = (dis*1.0 / area*1.0) * 100;
    return 100 - prob;
}

int isInside(Point polygon [], int N, Point p)
{
    int counter = 0;
    int i;
    double xinters;
    Point p1,p2;
    
    p1 = polygon[0];
    for(i = 1;i<=N;i++)
    {
        p2 = polygon[i % N];
        if(p.y > MIN(p1.y,p2.y))
        {
            if(p.y <= MAX(p1.y,p2.y))
            {
                if(p.x <= MAX(p1.x,p2.x))
                {
                    if(p1.y != p2.y)
                    {
                        xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
                        if(p1.x == p2.x || p.x <= xinters)
                            counter++;
                    }
                }
            }
        }
        p1 = p2;
    }
    
    if(counter % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Point arr[n];
        for(int i=0;i<n;i++)
        {
            double a,b;
            cin>> a>> b;
            arr[i] = Point(a, b);
        }
        
        double a, b;
        cin>> a >> b;
        Point approx(a,b);
        
        int q;
        cin >> q;
        
        for(int i = 0;i < q;i++)
        {
            int a, b;
            cin>> a >>b;
            Point ch(a,b);
            if(!isInside(arr,n,ch))
            {
                cout<<"Yes"<<endl;
                cout<<probability(arr,n,ch,approx)<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
