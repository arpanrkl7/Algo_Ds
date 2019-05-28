#include<iostream>
#include<vector>
#include<string>
using namespace std;
void sudoku(vector<vector<int>>& board,int bno);
bool isnoSafe(vector<vector<int>>& board,int no,int row,int col);

    int rowBit[]={0,0,0,0,0,0,0,0,0};
    int colBit[]={0,0,0,0,0,0,0,0,0};  
    int matrixBit[][]={{0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0}}; 

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

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            rowBit[i]=rowBit[i] | (1 << board[i][j]);
            colBit[i]=colBit[i] | (1 << board[j][i]);
            matrixBit[i/3][j/3]=matrixBit[i/3][j/3] | (1 << board[i/3][j/3]);

            
        }
        
    }    
                     

}

bool isnoSafe(vector<vector<int>>& board,int no,int row,int col){
    //col check
    for(int i=0;i<board.size();i++){
        if(board[row][i] == no){
            return false;
        }
    }
    //row check
    for(int j=0;j<board.size();j++){
        if(board[j][col] == no){
            return false;
        }
    }
    //submatrix check
    int rownew=(row/3)*3;
    int colnew=(col/3)*3;
    for(int i=rownew;i<rownew+3;i++){
        for(int j=colnew;j<colnew+3;j++){
            if(board[i][j] == no){
                return false;
            }
        }
    }

    return true;

}

void sudoku(vector<vector<int>>& board,int bno){

    if(bno == board.size()*board.size()){
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
            if(isnoSafe(board,no,row,col)){
            board[row][col]=no;
            sudoku(board,bno+1);
            board[row][col]=0;
        }
        }
        }

        else
        sudoku(board,bno+1);
        
        
}

bool isnoSafebitmask(int row,int col,int no){
    if(rowBit[row] & (1<<no) ==1 && rowBit[col] & (1<<no) == 1 && matrixBit[row/3][col/3] & (1<<no) == 1){
        return false;
    }

    return true;


}

void sudokubitmask(vector<vector<int>>& board,int bno){

    if(bno == board.size()*board.size()){
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
            if(isnoSafebitmask(row,col,no)){
            board[row][col]=no;
            sudoku(board,bno+1);
            board[row][col]=0;
        }
        }
        }

        else
        sudokubitmask(board,bno+1);

}
    
