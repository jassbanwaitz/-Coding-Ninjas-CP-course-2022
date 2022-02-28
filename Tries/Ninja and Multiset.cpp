/*
Our problem setter, Ninja, is fascinated by different types of sets. Quite recently, he came across a new term- Multiset. Multiset is a set, where equal elements are allowed. He started experimenting with it and has managed to frame a pretty interesting problem for you to solve.
You are given a multiset G, initially containing only 0, and a few queries q. Queries are actually of 3 types:
"+ x" — This query adds an integer x to the given multiset.
"- x" — This query erases one occurrence of x from the given multiset. Before this query is encountered, it is guaranteed that the multiset will contain integer x at least once.
"? x" — In this query, you are given integer x and you need to compute the maximum value of bitwise exclusive OR (also known as XOR) of integer x and some integer y from the given multiset.
Input Format:
First line on input contain Q (number of queries ).
Next Q line contain Q queries as defined above.
Output Format:
For each query of type '?' print the answer in new line
Constraints:
1 <= Q <= 10^5
1 <= x <= 10^9
Sample Input 1:
8
? 8
? 5
+ 10
? 5
? 4
+ 4
- 4
? 10
Sample Output 1:
8
5
15
14
10
Explanation:
Initially the multiset contains only the integer 0. So for the first query, answer is 8 XOR 0 = 8.
Similarily, the answer for second query is 5 XOR 0 = 5.
After the third query, 10 is added to the multiset.
For the fourth query, 5 will be XOR'ed with 0 and 10. Out of these, 5 XOR 10 = 15 is max.
Similarily, for the fifth query, 4 will be XOR'ed with 0 and 10. Out of these, 4 XOR 10 = 14 is max.
After the sixth query, 4 is added to the multiset.
After the seventh query, 4 is erased from the multiset.
For the last query, 10 is XOR'ed with 0 and 10. Out of these, 10 XOR 0 = 10 is max.
*/

#include<bits/stdc++.h>
using namespace std;

struct trie
{
    trie *left = NULL, *right = NULL;
    int count = 0;
    void insert(int index, int val)
    {
        if(index < 0)
        {
            return ;
        }
        int a = (1ll << index);
        int b = (a & val);
        if(b == 0)
        {
            if(left == NULL)
                left = new trie();
            left->count++;
            left->insert(index-1,val);
        }
        else
        {
            if(right == NULL)
               right = new trie();
            right->count++;
            right->insert(index-1,val);
        }
    }
    
    void delete_(int index, int val)
    {
        if(index<0)
          return;
        int a = (1ll << index), b = (a & val);
        if(b == 0)
        {
            if(left == NULL)
               left = new trie();
            left->count--;
            left->delete_(index-1,val);
        }
        else
        {
            if(right == NULL)
                right = new trie();
            right->count--;
            right->delete_(index-1,val);
        }
    }
    
    int max_(int index, int val)
    {
        int ans = 0;
        if(index < 0)
            return 0;
        int a = (1ll << index), b = (a & val);
        if(b == 0)
        {
            if(right && right->count > 0)
            {
                ans += (a);
                ans += (right->max_(index-1,val));
            }
            else if(left && left->count > 0)
            {
                ans += (left->max_(index-1,val));
            }
            else
                return ans;
        }
        else
        {
            if(left && left->count > 0)
            {
                ans += (a);
                ans += (left->max_(index-1,val));
            }
            else if(right && right->count > 0)
            {
                ans += (right->max_(index-1,val));
            }
            else
                return ans;
        }
        return ans;
    }
};
int main()
{
   trie *head = new trie();
    int q;
    cin>>q;
    while(q--)
    {
        char x,y;
        int a,b,c,d;
        cin>>x;
        cin>>a;
        if(x == '+')
        {
            head->insert(31,a);
        }
        else if(x == '-')
        {
            head->delete_(31,a);
        }
        else
        {
            b = max(a, head->max_(31,a));
            cout<<b<<endl;
        }
    }
}
