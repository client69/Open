#include<iostream>
#include<vector>
using namespace std;

 int hammingWeight(uint32_t n) {
    int count=0;
    for(int i=0; i<32; i++){
        int mask=(1 << i);
        if((n & mask)!=0)count++;
    }       
    //Log(n)
    while(n!=0){
        if((n & 1)!=0)count++;
        n>>=1;
    }
    //O(number of set bit)
    while(n!=0){
        count++;
        n=(n & (n-1)); // whenever we perform n & n-1 we reach to the last set bit
    }
    return count;
}
//leet 231
 bool isPowerOfTwo(int n) {
     return n>0 &&((n & (n-1))==0);   
    }

//leet 342a
bool isPowerOfFour(int n) {
        if(n>0 && ((n&(n-1))==0)){
            int count=0;
            while(n!=1){
                count++;
                n>>=1;
            }
            return ((count&1)==0);
        } else {
            return false;
        }
    }
void solve(){
    int n=3;
    hammingWeight(n);
}
//leet 36 valid sudoku
int rowA[10];
    int colA[10];
    int matrix[3][3];
    bool isValidSudoku(vector<vector<char>>& bo) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(bo[i][j]!='.'){
                    int mask=(1<<(bo[i][j]-'0'));
     if(((rowA[i] & mask)==0) && ((colA[j] & mask)==0) && ((matrix[i/3][j/3] & mask)==0)){
                        rowA[i]^=mask;
                        colA[j]^=mask;
                        matrix[i/3][j/3]^=mask;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }


int main(){
    solve();
    return 0;
}