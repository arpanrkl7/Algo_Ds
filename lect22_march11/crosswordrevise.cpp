#include<iostream>
#include<vector>
#include<string>
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

void crosswordMy(vector<vector<char>>& board,string words[],int wpsf,int tw){

    if(wpsf == tw){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
            
        }
        return;
    }

                    string word=words[wpsf];


    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){

            if(board[i][j] == '-' || board[i][j] == word[0]){
            if(cptwh(board,word,i,j)){
                bool reset[word.size()];
                ptwh(board,word,i,j,reset);
                crosswordMy(board,words,wpsf+1,tw);
                uptwh(board,word,i,j,reset);
            }
            if(cptwv(board,word,i,j)){
                bool reset[word.size()];
                ptwv(board,word,i,j,reset);
                crosswordMy(board,words,wpsf+1,tw);
                uptwv(board,word,i,j,reset);
            }
            }
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
    string words[4]={"agra","norway","england","gwalior"};
    crosswordMy(board,words,0,4);


}

