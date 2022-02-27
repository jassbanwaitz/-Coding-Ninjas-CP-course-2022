/*
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   
Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation :
Only 1 path is possible. The path is shown in the image below.
Alt Text

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Explanation:
 As described in the Sample Output 2, four paths are possible.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int maze[20][20], solution[20][20];

bool isSafe(int row, int col, int n) {
	return (row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1 && solution[row][col] == 0);
}

void runRat(int row, int col, int n) {
	if(!isSafe(row, col, n)) {
		return;
	}
    
	if(row == n-1 && col == n-1) {
        solution[row][col] = 1;
		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j < n ; ++j) cout << solution[i][j] << ' ';
		}
		cout << '\n';
        solution[row][col] = 0;
        return;
	}
	
    solution[row][col] = 1;
    
    runRat(row-1, col, n);
	runRat(row+1, col, n);
    runRat(row, col-1, n);
	runRat(row, col+1, n);

	solution[row][col] = 0;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;

	for(int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < n ; ++j) cin >> maze[i][j];
	}
	memset(solution, 0, sizeof solution);

	runRat(0, 0, n);
	return 0;
}
