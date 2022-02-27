/*
Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct puzzle{
    int x, y;
    char c;
    int len;
};

int fill_table(string s[], puzzle node, string city)
{
    int x= node.x;
    int y = node.y;
    int len = node.len;
    char c = node.c;
    int idx = 0;
    
    if( c == 'H') {
        while(idx < city.size()) {
            if((s[x][y+idx] == 'h') || (s[x][y+idx] == 'v') || (s[x][y+idx] == city[idx])){
            }
            else{
                return 0;
            }
            idx++;
        }
    }
    else{
        while(idx < city.size()) {
            if((s[x+idx][y] == 'h') || (s[x+idx][y] == 'v') || (s[x+idx][y] == city[idx])){
            }
            else{
                return 0;
            }
            idx++;
        }
    }
    idx = 0;
    
    if( c == 'H') {
        while(idx < city.size()) {
            s[x][y+idx] = city[idx];
            idx++;
        }
    }
    else{
        while(idx < city.size()) {
            s[x+idx][y] = city[idx];
            idx++;
        }
    }
    return 1;
}

void print_table(char s[][10]){
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }    
}

int fill_iterative(string s[], string city[], int idx, puzzle nodes[], int n_idx, int cnt, int arr[])
{
   
    if(cnt == n_idx)
        return 1;
    
  
    string bkp;
    int x = nodes[cnt].x;
    int y = nodes[cnt].y;
    char c = nodes[cnt].c;
    int len = nodes[cnt].len;
    
    bkp.reserve(len);
    
    for(int i = 0; i < len; i++) {
        if(c == 'H') {
           bkp[i] = s[x][y+i];        
        }
        else{
            bkp[i] = s[x+i][y];
        }
    }
    
    for(int i = 0;i < idx; i++) {
        if(arr[i] == 0 && city[i].size()== nodes[cnt].len) {
            arr[i] = 1;
               
            if(fill_table(s, nodes[cnt], city[i])) {
              
                
                int ret = fill_iterative(s, city, idx, nodes, n_idx, cnt+1, arr);   
                
                if(ret == 1)
                    return 1;
                
                for(int i = 0; i < len; i++) {
                    if(c == 'H') {
                        s[x][y+i] = bkp[i];        
                    }
                    else{
                        s[x+i][y]= bkp[i];
                    }
                }
            }
            arr[i] = 0;
        }
    }
    return 0;
}

int main() {
    string s[10];
    string city[10];
    string cities;
    int idx = 0;    
    
    for(int i = 0; i < 10; i++) {
        cin >> s[i];
    }
    
    cin >> cities;
    
    for(int i = 0; i < 10; i++) {
  
    }
   
   
    while(cities.size() != 0) {
        int sc = cities.find(';');
        city[idx] = cities.substr(0, sc);
        cities.erase(0, sc);
        if(cities.size() != 0)
            cities.erase(0,1);
        idx++;
    }

        
    puzzle nodes[10];
    int n_idx = 0;
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if((s[i])[j] == '-' || (s[i])[j] == 'h' || s[i][j] == 'v') {
                if((j < 9) && ((s[i][j+1] == '-') || (s[i][j+1] == 'v'))) {
                    int k = j;
                    nodes[n_idx].x = i;
                    nodes[n_idx].y = j;
                    nodes[n_idx].c = 'H';
                    while(k <=9 && ((s[i][k] == '-') || (s[i][k] == 'v'))) {
                        s[i][k]='h';
                        k++;
                    }
                    nodes[n_idx].len = k - j;
                    n_idx++;
                }
                else if((i < 9) && ((s[i+1][j] == '-') || (s[i+1][j] == 'h'))) {
                    int k = i;
                    nodes[n_idx].x = i;
                    nodes[n_idx].y = j;
                    nodes[n_idx].c = 'V';
                    while(k <= 9 && ((s[k][j] == '-') || (s[k][j] == 'h'))) {
                        s[k][j] = 'v';
                        k++;
                    }
                    nodes[n_idx].len = k -i;
                    n_idx++;
                }
            }
        }
    }
    
    for(int i = 0; i < n_idx ; i++) {
      
    }
    
    char str_arr[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            str_arr[i][j]= s[i][j];
        }
    }
    int arr[idx];
    memset(arr, 0, sizeof(int)*idx);
    
    int ret = fill_iterative(s, city, idx, nodes, n_idx, 0, arr);
    
    if(ret) {
        for(int i = 0; i < 10; i++)
            cout << s[i]<< endl;
   
        
    }
    return 0;
}
