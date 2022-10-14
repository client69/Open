#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<vector<int> > &v, int x, int y, int a)
{
    int horBox = (x / 3) + 1;
    int verBox = (y / 3) + 1;
    for (int i = 0; i < 9; i++)
    {
        if (v[i][x] == a)
        {
            return false;
        }
        if (v[y][i] == a)
        {
            return false;
        } 
    }
    
    for(int i = 3*(horBox-1); i < 3*horBox; i++)
    {
        for (int j = 3*(verBox-1); j < 3*verBox; j++)
        {
            if(v[j][i] == a)
                return false;
        }
    }
    return true;
}
bool sudokuHelper(int board[][9], vector<vector<int> > &v)
{
    int y = 0;
    for(y = 0; y < 9; y++)
    {
        for(int i = 0; i < 9;)
        {
            if(board[y][i] != 0)
            {
                if(y == 8 && i == 8)
                    return true;
                i++;
                continue;
            }
            int j = v[y][i] + 1;
            for(; j <= 9; j++)
            {
                if(isPossible(v, i, y, j))
                {
                    v[y][i] = j;
                    if(y == 8 && i == 8)
                        return true;
                    i++;
                    break;
                }
            }
            if(j == 10)
            {
                v[y][i] = 0;
                if(i == 0)
                {
                    if(y == 0)
                        return false;
                    y--;
                    i = 8;
                    while(board[y][i] != 0)
                    {
                        i--;
                        if(i == 0)
                        {
                            if(y == 0)
                                return false;
                            y--;
                            i = 8;
                        }
                    }
                    continue;
                }
                i--;
                while(board[y][i] != 0)
                    {
                        if(i == 0)
                        {
                            if(y == 0)
                                return false;
                            y--;
                            i = 8;
                        }
                        i--;
                    }
            }
        }
    }
    return false;
}
bool sudokuSolver(int board[][9]){
    vector<vector<int> > v(9, vector<int> (9));
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            v[i][j] = board[i][j];
    cout<<sudokuHelper(board, v)<<endl; 
    for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            cout<<v[i][j]<<" ";  
            cout<<endl;
        } 
}
int main(int argc, char const *argv[])
{
    int board[9][9];
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin>>board[i][j];
    cout<<"__________________________________"<<endl;
    sudokuSolver(board);
    return 0;
}
