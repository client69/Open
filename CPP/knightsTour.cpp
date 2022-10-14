// Here we have to fill the chess board where the knight can move exactly once and print all the possible combinations
// we know how the knight move r-2,c+1 r-1,c+2 r+1,j+2 i+2,j+1 .. 
// we will call the function for all of them
// we will take count and fill the board with count
// when the board is filled we will print it 
// the base consitions : are out of bound conditions and if the position is already filled we will not make any changes but 
// will return similar to N queens


#include<bits/stdc++.h>
using namespace std;

void print (vector<vector<int>> &board,int size)
{
    for (int rowIdx=0; rowIdx<size; rowIdx++)
    {
        for (int colIdx=0; colIdx<size; colIdx++)
        {
            cout << board[rowIdx][colIdx] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void fillBoard(int size, int row, int col, vector<vector<int>>& board, int count)
{   

    if (row<0 || col<0 || row>=size || col>=size || board[row][col]!=0 )
    {
        return;
    }

    if ( count == (size*size))
    {   
        board[row][col] = count;

        print(board,size);

        board[row][col] = 0;

        return;
    }


    board[row][col] = count; 

    fillBoard(size, row-2, col+1, board, count+1); 
    fillBoard(size, row-1, col+2, board, count+1); 
    fillBoard(size, row+1, col+2, board, count+1); 
    fillBoard(size, row+2, col+1, board, count+1); 
    fillBoard(size, row+2, col-1, board, count+1); 
    fillBoard(size, row+1, col-2, board, count+1); 
    fillBoard(size, row-1, col-2, board, count+1); 
    fillBoard(size, row-2, col-1, board, count+1);

    board[row][col] = 0;
}


int main()
{
    int size;

    cin >> size;

    int rowIdx,colIdx;

    cin >> rowIdx >> colIdx;

    vector<vector<int>> board(size,vector<int>(size));

    fillBoard(size, rowIdx, colIdx, board, 1);

    return 0;
} 
