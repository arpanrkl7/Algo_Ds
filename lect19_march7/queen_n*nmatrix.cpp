#include<iostream>
#include<vector>
#include<string>
using namespace std;
void queenPerm(vector<vector<bool>> &board,int queen,string asf);
void queenComb(vector<vector<bool>> &board,int queen,int lqp);
void nqueen2nComb(vector<vector<bool>>& board,int cq,int cb,string asf);
bool isQueenSafe(vector<vector<bool>> &board,int i,int j);
bool isBoardSafe(vector<vector<bool>> &board);
bool isBoardSafedouble(vector<vector<bool>> &board);
void coinChange(int coins[],int amt,string asf);
void coinChangeComb(int coins[],int amt,string asf,int size,int lc);
void queenPerm(vector<vector<bool>> &board,int queen,string asf){

    static int count=0;
    if(queen==board.size()){
        cout << count++ << endl;
        return;
    }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==false){
                board[i][j]=true;
                queenPerm(board,queen+1,asf + to_string(i) + to_string(j) + " ");
                board[i][j]=false;
            }
        }
        // cout << endl;
    }
}

void queenComb(vector<vector<bool>> &board,int queen,int lqp){
        static int count=0;

    if(queen==(board.size())){
        if(isBoardSafedouble(board)==true){
        cout << ++count << endl;
        }
        return;
    }

    for(int i=lqp+1;i<(board.size()*board.size());i++){
        if(board[i/board.size()][i%board.size()]==false){
            board[i/board.size()][i%board.size()]=true;
            queenComb(board,queen+1,i);
            board[i/board.size()][i%board.size()]=false;
        }

    }
}

void nqueen2nComb(vector<vector<bool>>& board,int cq,int cb,string asf){

    if(cb == board.size()*board.size()){
        if(cq == board.size()){
            cout << asf << endl; 
        }
        return;
    }

    nqueen2nComb(board,cq,cb+1,asf);
    int row=cb/board.size();
    int col=cb%board.size();
    if(board[row][col] == false && isQueenSafe(board,row,col)){
        board[row][col]=true;
        nqueen2nComb(board,cq+1,cb+1,asf + to_string(row) + to_string(col) + " ");
        board[row][col]=false;
    }

}

void queenCombPro(vector<vector<bool>> &board,int queen,int lqp){
        static int count=0;

    if(queen==(board.size())){
        
        cout << ++count << endl;
        return;
    }

    for(int i=lqp+1;i<(board.size()*board.size());i++){
        if(board[i/board.size()][i%board.size()]==false && isQueenSafe(board,(i/board.size()),(i%board.size()))){
            board[i/board.size()][i%board.size()]=true;
            queenComb(board,queen+1,i);
            board[i/board.size()][i%board.size()]=false;
        }

    }
}

bool isQueenSafe(vector<vector<bool>> &board,int i,int j){
    //column check
    for(int k=0;k<board.size();k++){
        if(board[k][j] == true && k!=i)
        return false;
      }

    //row check  
    for(int k=0;k<board.size();k++){
        if(board[i][k] == true && k!=j)
        return false;
    }  
    //NW
    for(int ii=i-1,jj=j-1;ii>=0 && jj>=0;ii--,jj--){
    if(board[ii][jj] == true)
    return false; 
    }
    //NE
    for(int ii=i-1,jj=j+1;ii>=0 && jj<board.size();ii--,jj++){
    if(board[ii][jj] == true)
    return false;
    }
    //SW
    for(int ii=i+1,jj=j-1;ii<board.size() &&  jj>=0;ii++,jj--){
    if(board[ii][jj] == true)
    return false;
    }
    //SE
    for(int ii=i+1,jj=j+1;ii<board.size() && jj<board.size();ii++,jj++){
    if(board[ii][jj] == true)
    return false;
    }
    return true;
}

bool isBoardSafe(vector<vector<bool>> &board){
    for(int i=0;i<(board.size()*board.size());i++){
        int row=i/board.size();
        int col=i%board.size();
        if(board[row][col] == true)
        {
        if(isQueenSafe(board,row,col)==false){
            return false;

        }
        }


        
    }
            return true;

}

bool isBoardSafedouble(vector<vector<bool>> &board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j] == true)
        {
        if(isQueenSafe(board,i,j)==false)
        return false;
        }
        }
    }
            return true;

}

void coinChange(int coins[],int amt,string asf,int size){

    if(amt == 0){
        cout << asf << endl;
        return;
    }

    for(int i=0;i<size;i++){
        if(coins[i] <= amt){
            coinChange(coins,amt-coins[i],asf + to_string(coins[i]),size);
        }
    }
}

void coinChangeComb(int coins[],int amt,string asf,int size,int lc){

    if(amt == 0){
        cout << asf << endl;
        return;
    }

    for(int i=lc;i<size;i++){
        if(coins[i] <= amt){
            coinChangeComb(coins,amt-coins[i],asf + to_string(coins[i]),size,i);
        }
    }

}

main(int argc,char** argv){

    vector<vector<bool>> board {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    // queenPerm(board,0,"");
        // queenCombPro(board,0,-1);
        int arr[]={2,3,5};
        // coinChange(arr,7,"",3);
        // coinChangeComb(arr,7,"",3,0);
        nqueen2nComb(board,0,0,"");

}

