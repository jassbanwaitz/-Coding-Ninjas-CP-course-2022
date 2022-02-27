/*
Given a state of 3*3 Tic Tac Toe Board and two players 'x' and 'o', find the best optimal move possible for player with the next turn, specifying their row and column.
Consider yourself to be 'x' and computer to be 'o'.
Note: If there are more than one ways for 'x' to win the game from the given board state, the optimal move is the one where we have to make lesser number of moves to win the game.
Input Format:
First line of input contains integer N, representing the number of given states of board.
Next N lines contain row number, column number and player name('x' or 'o'), space separated.
Output Format:
The first line of output contains the ultimate result of the game as follows:
"Player_name" Wins. If no one wins, print Draw 
The second line of output contains 
(Total number of moves left) row: (Row Number) col: (Column Number)
Sample Input 1:
4
0 0 x
0 1 o
0 2 x
1 1 o
Sample Output 1:
Draw
5 row: 2 col: 1
Sample Input 2:
4
0 0 o
2 0 x
2 2 o
2 1 x
Sample Output 2:
o Wins
1 row: 1 col: 1
*/

#include <bits/stdc++.h>
using namespace std;

struct Move
{
    int row, col;
};

char player = 'x', opponent = 'o';
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

int evaluate(char b[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }

    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == player)
                return +10;

            else if (b[0][col] == opponent)
                return -10;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }

    return 0;
}

pair<int, int> minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);
    if (score == 10)
        return make_pair(score-depth,depth);
    if (score == -10)
        return make_pair(score+depth,depth);
    if (isMovesLeft(board) == false)
        return make_pair(0, depth);

    if (isMax)
    {
        pair<int, int> best = make_pair(-1000,0);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (board[i][j] == '_')
                {
                    board[i][j] = player;
                    best = max(best,
                               minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    }

    else
    {
       pair<int, int> best = make_pair(1000,0);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (board[i][j] == '_')
                {
                    board[i][j] = opponent;
                    best = min(best,
                               minimax(board, depth + 1, !isMax));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

Move findBestMoveForX(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    int moves;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (board[i][j] == '_')
            {
                board[i][j] = player;
                pair<int, int> moveVal = minimax(board, 1, false);
                board[i][j] = '_';
                if (moveVal.first > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal.first;
                    moves = moveVal.second;
                }
            }
        }
    }
    string status = "";
    if(bestVal > 0)
    {
        status = "x Wins";
    }
    else if(bestVal < 0)
    {
        status = "o Wins";
    }
    else
    {
        status = "Draw";
    }
    cout<<status<<endl;
    printf("%d",moves);

    return bestMove;
}

Move findBestMoveForO(char board[3][3])
{
    int bestVal = 1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    int moves;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (board[i][j] == '_')
            {
                board[i][j] = opponent;
                pair<int, int> moveVal = minimax(board, 1, true);
                board[i][j] = '_';
                if (moveVal.first < bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal.first;
                    moves = moveVal.second;
                }
            }
        }
    }
    string status = "";
    if(bestVal > 0)
    {
        status = "x Wins";
    }
    else if(bestVal < 0)
    {
        status = "o Wins";
    }
    else
    {
        status = "Draw";
    }
    cout<<status<<endl;
    printf("%d",moves);

    return bestMove;
}

// Driver code
int main()
{
    char board[3][3] = 
    {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    int n;
    cin >> n;
    int j,k;
    char p;
    Move bestMove;
    for(int i=0;i<n;i++)
    {
        cin>>j>>k;
        cin>>p;
        board[j][k] = p;
    }
    if(p == 'x')
        bestMove = findBestMoveForO(board);
    else if(p == 'o')
        bestMove = findBestMoveForX(board);
    
    printf(" row: %d col: %d", bestMove.row,
                                  bestMove.col);
    
    return 0;
        
}

