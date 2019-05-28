#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isnoSafe(vector<vector<int>>& board,int i,int j,int no){

    for(int ii=0;ii<board.size();ii++){
        if(board[i][ii] == no || board[ii][j] == no){
            return false;
        }
    }
    int matrixRow=(i/3)*3;
    int matrixCol=(j/3)*3;
    for(int ii=matrixRow;ii<matrixRow+3;ii++){
        for(int jj=matrixCol;jj<matrixCol+3;jj++){
            if(board[ii][jj] == no){
                return false;
            }
        }
    }
    return true;

}

void sudoku(vector<vector<int>> board,int bno){

    if(bno == (board.size()*board.size())){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
      
    }

    int row=bno/board.size();
    int col=bno%board.size();
    if(board[row][col] == 0){
        for(int no=1;no<=9;no++){
            if(isnoSafe(board,row,col,no)){
                board[row][col]=no;
                sudoku(board,bno + 1);
                board[row][col] = 0;
            }
        }

    }
    else
    {
        sudoku(board,bno + 1);
    }
}

int main(int argc,char** argv){

    vector<vector<int>> board{{3,0,6,5,0,8,4,0,0},
                              {5,2,0,0,0,0,0,0,0},
                              {0,8,7,0,0,0,0,3,1},
                              {0,0,3,0,1,0,0,8,0},
                              {9,0,0,8,6,3,0,0,5},
                              {0,5,0,0,9,0,6,0,0},
                              {1,3,0,0,0,0,2,5,0},
                              {0,0,0,0,0,0,0,7,4},
                              {0,0,5,2,0,6,3,0,0}};
    sudoku(board,0);   
}
