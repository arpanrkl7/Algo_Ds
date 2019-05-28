#include<iostream>
#include<vector>
#include<string>
using namespace std;

void canHorizontalPlace();
void canVerticalPlace();
void HorizontalPlace();
void VerticalPlace();
void removeHorizontal();
void removeVertical();
int main(int argc,char** argv){


}

void canHorizontalPlace(vector<vector<char>>& board,string words[],int r,int c){

    if(c+words.size()>board.size()){
        return false;
    }
    else if(r+words.size()<board.size() && board[r+words.size()][c] = '+'){
        return false;
    }
    else if(board[r][c-1] !='+' || board[r][c+1] !='+'){
        return false;
    }
    else{
        for(int i=0;i<words.size();i++){
            if(board[r+j][c] != '-' && board[r+j][c] !=words[j]){
                return false;
            }
        }
    }
    return true;

}

void crossWord(vector<vector<char>>& board,string names[],int wpsf){

    if(wpsf == names.size()){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

   for(int i=0;i<board.size();i++){
       for(int j=0;j<board.size();i++){
               if(canPlacedHr(board,i,j,wpsf)){
                   
                HorizontalPlace(board,i,j,wpsf);
                removeHorizontal(board,i,j,wpsf);
                

           }
           else
           {

           }
       }
   }


    int row=cb/board.size();
    int col=cb%board.size();
    if(board[row][col] == '-'){
        board[row][col] = cc;
        for(int i=0;i<names.size();i++){
            for(int j=1;j<names[i].size();j++){
            crossWord(board,names[i].getchar(j)) 
            }
        }
        
    }

}