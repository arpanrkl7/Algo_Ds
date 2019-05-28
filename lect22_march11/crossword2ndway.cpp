#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool cptwh(vector<vector<char>>& board,string word,int i,int j){
    if(j + word.size() > board.size()){
        return false;
    }
    if(j > 0 &&  board[i][j-1] != '+'){
        return false;
    }
    if(j > 0 && board[i][j+word.size()] !='+'){
        return false;
    }
    for(int ii=i,jj=j;jj-j<word.size();jj++){
        if(board[ii][jj] != '-' && board[ii][jj] != word[jj-j]){
            return false;
        }
    }
    return true;
}

bool cptwv(vector<vector<char>>& board,string word,int i,int j){
    if(i + word.size() > board.size()){
        return false;
    }
    if(i > 0 &&  board[i-1][j] != '+'){
        return false;
    }
    if(i > 0 && board[i+word.size()][j] !='+'){
        return false;
    }
    for(int ii=i,jj=j;ii-i<word.size();ii++){
        if(board[ii][jj] != '-' && board[ii][jj] != word[ii-i]){
            return false;
        }
    }
    return true;
}

void ptwh(vector<vector<char>>& board,string word,int i,int j,bool reset[]){

    for(int ii=i,jj=j;jj-j<word.size();jj++){
        if(board[ii][jj] == '-'){
            reset[jj-j]=true;
            board[ii][jj] = word[jj-j];
        }
    }
}

void ptwv(vector<vector<char>>& board,string word,int i,int j,bool reset[]){

    for(int ii=i,jj=j;ii-i<word.size();ii++){
        if(board[ii][jj] == '-'){
            reset[ii-i]=true;
            board[ii][jj] = word[ii-i];
        }
    }
}

void uptwh(vector<vector<char>>& board,string word,int i,int j,bool reset[]){

    for(int ii=i,jj=j;jj-j<word.size();jj++){
        if(reset[jj-j]==true){
            
            board[ii][jj] = '-';
        }
    }
}

void uptwv(vector<vector<char>>& board,string word,int i,int j,bool reset[]){

    for(int ii=i,jj=j;ii-i<word.size();ii++){
        if(reset[ii-i]==true){
            
            board[ii][jj] = '-';
        }
    }
}


void crossword2ndway(vector<vector<char>>& board,vector<string> words,int cb,bool cw[]){

    if(cb == (board.size()*board.size())){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
            
        }
        return;
    }

    int i=cb/board.size();
    int j=cb%board.size();

    if(board[i][j] == '+'){
        crossword2ndway(board,words,cb+1,cw);
    }
    else
    {
        int count=0;
        for(int jj=0;jj<words.size();jj++){
            if(cw[jj] == false){
            if(cptwh(board,words[jj],i,j)){
                count++;

                bool reset[words[jj].size()];
                ptwh(board,words[jj],i,j,reset);
                crossword2ndway(board,words,cb+1,cw);
                uptwh(board,words[jj],i,j,reset);
            }
            if(cptwv(board,words[jj],i,j)){
                count++;
                bool reset[words[jj].size()];
                ptwv(board,words[jj],i,j,reset);
                crossword2ndway(board,words,cb+1,cw);
                uptwv(board,words[jj],i,j,reset);
            }
            }
        }

        if(count == 0 && board[i][j] != '-'){
            
                crossword2ndway(board,words,cb+1,cw);
            

        }
    }

    
}

int main(int argc,char** argv){

    vector<vector<char>> board{{'+','-','+','+','+','+','+','+','+','+'},
                               {'+','-','+','+','+','+','+','+','+','+'},
                               {'+','-','-','-','-','-','-','-','+','+'},
                               {'+','-','+','+','+','+','+','+','+','+'},
                               {'+','-','+','+','+','+','+','+','+','+'},
                               {'+','-','-','-','-','-','-','+','+','+'},
                               {'+','-','+','+','+','-','+','+','+','+'},
                               {'+','+','+','+','+','-','+','+','+','+'},
                               {'+','+','+','+','+','-','+','+','+','+'},
                               {'+','+','+','+','+','+','+','+','+','+'}};
    vector<string> words{"agra","norway","england","gwalior"};
    bool cw[words.size()];
    crossword2ndway(board,words,0,cw);


}

