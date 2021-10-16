#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;

    bool safeToPlace(vector<vector<int>> &board, int row, int col)
    {
        for (int rowIdx=row; rowIdx>=0; rowIdx--) // check the column
        {
            if (board[rowIdx][col]==1) return false;

        }

        for (int rowIdx=row, colIdx=col; rowIdx>=0 && colIdx>=0; rowIdx--,colIdx--) // check the left diagonal 
        {
            if (board[rowIdx][colIdx]==1) return false;
        }

        for (int rowIdx=row, colIdx=col; rowIdx>=0 && colIdx<board[0].size(); rowIdx--, colIdx++) // check the right diagonal 
        {
            if (board[rowIdx][colIdx]==1) return false;
        }

        return true;
    }


    void fillBoard(vector<vector<int>> &board, int rows, int cols)  // for placing the queens
    {   

        if (rows == board.size()) // when all the rows are done we will add Q where queen was placed and rest places dot
        {   
            vector<string> temp;

            for (int rowIdx=0; rowIdx<board.size(); rowIdx++)
            {   
                string add="";

                for (int colIdx=0; colIdx<board[0].size(); colIdx++)
                {
                    if (board[rowIdx][colIdx] == 1)
                    {
                        add += "Q" ;
                    }
                    else
                    {
                        add += "." ;
                    }
                }

                temp.push_back(add);
            }

            ans.push_back(temp);
            {
                return ;
            }
        }

        for (int colIdx=0; colIdx<cols; colIdx++) 
        {
            if(safeToPlace(board,rows,colIdx))      // if the position is safe to place we will put the queen there 
            {
                board[rows][colIdx] = 1;            // putting 1 there

                fillBoard(board,rows+1,cols);       // now calling for another row
            }

            board[rows][colIdx] = 0;                // if we can't place the queen anywhere in the entire row we will return and put zero 
        }                                           // to previous filled (with Q) places

        return ;
    }

    vector<vector<string>> solveNQueens(int n) 
    {

        vector<vector<int>> board;                  // we need to make the board where we will fill the position of the queen

        for (int rowIdx=0; rowIdx<n; rowIdx++)      // we are intializing the the entire board vector with 0
        {   
            vector<int> temp;

            for (int colIdx=0; colIdx<n; colIdx++)
            {
                temp.push_back(0);    
            }

            board.push_back(temp);
        }

        fillBoard(board,0,n);

        return ans;
    }
};