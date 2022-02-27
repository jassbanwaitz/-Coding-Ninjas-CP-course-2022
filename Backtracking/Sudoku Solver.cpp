/*
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
*/

#include<iostream>
using namespace std;

#define N 9
bool check(int grid[N][N], int &row , int &col) {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(grid[i][j] == 0 ) {
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}
bool rowSafe(int grid[N][N], int row , int x) {
	for(int i=0;i<N;i++) {
		if(grid[row][i] == x) {
			return false;
		}
	}
	return true;
}
bool colSafe(int grid[N][N], int col , int x) {
	for(int i=0;i<N;i++) {
		if(grid[i][col] == x) {
			return false;
		}
	}
	return true;
}
bool boxSafe(int grid[N][N], int row ,int col ,int x) {
	int rowFactor = row - (row%3);
	int colFactor = col - (col%3);
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(grid[i+rowFactor][j+colFactor] == x) {
				return false;
			}
		}
	}
	return true;
}
bool isSafe(int grid[N][N], int row,int col,int i) {
	if( rowSafe(grid,row,i) && colSafe(grid,col,i) && boxSafe(grid,row,col,i) ) {
		return true;
	}
	return false;
}
bool sudokuSolver(int grid[][9]){
    int row,col;
	if(!check(grid,row,col)) {
		return true;
	}
	for(int i=1;i<=N;i++) {
		if(isSafe(grid,row,col,i)) {
			grid[row][col]=i;
			if(sudokuSolver(grid)) {
				return true;
			}
			grid[row][col] = 0;
		}
	}
	return false;
}

int main()
{
    int n = 9; 
  	int board[9][9];
  	for(int i = 0; i < n ;i++){
      	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
    	}		
  	}
    
    if(sudokuSolver(board)){
    	cout << "true";	
    }
    else{
    	cout << "false";	
    }
    return 0;
}
