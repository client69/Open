import java.util.*;

/**
 * suduko_bit_manip
 */
public class sudoku_bit_manip {

    static int[]rows=new int[9];
    static int[]cols=new int[9];
    static int[][]mat=new int[3][3];

    public static boolean placedigit(int[][]board,int idx,ArrayList<Integer> loz)
    {
        if(idx==loz.size())
        {
            return true;
        }
            
        int row=loz.get(idx)/9;
        int col=loz.get(idx)%9;
        for(int i=1;i<=9;i++){
            int mask=(1<<i);
            if((rows[row]&mask)==0&&(cols[col]&mask)==0&&(mat[row/3][col/3]&mask)==0)
            {
                rows[row]^=mask;
                cols[col]^=mask;
                mat[row/3][col/3]^=mask;


                board[row][col]=i;
                if(placedigit(board,idx+1,loz)==true)
                    return true;
                board[row][col]=0;
                rows[row]^=mask;
                cols[col]^=mask;
                mat[row/3][col/3]^=mask;
            }
        }
        return false;
    }
    

    
    public static void main(String[] args) {

        int[][]board={
            {0,0,9,7,4,8,0,0,0},
            {7,0,0,0,0,0,0,0,0},
            {0,2,0,1,0,9,0,0,0},
            {0,0,7,0,0,0,2,4,0},
            {0,6,4,0,1,0,5,9,0},
            {0,9,8,0,0,0,3,0,0},
            {0,0,0,8,0,3,0,2,0},
            {0,0,0,0,0,0,0,0,6},
            {0,0,0,2,7,5,9,0,0}
        };
        ArrayList<Integer> loz=new ArrayList<>();
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!=0)
                {
                    int val=board[i][j];
                    int mask=(1<<val);
                    rows[i]^=mask;
                    cols[j]^=mask;
                    mat[i/3][j/3]^=mask;
                    
                }
                else
                    loz.add(i*9+j);
                    
        placedigit(board,0,loz);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                System.out.print(board[i][j]+" ");
            System.out.println();
        }
    }
}
