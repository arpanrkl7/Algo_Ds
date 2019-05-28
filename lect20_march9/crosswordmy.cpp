#include<iostream>
#include<vector>
#include<string>
using namespace std;
void crosswordMy(vector<vector<char>>& board,string words[],int wpsf,int tw);

bool cptwh(vector<vector<char>>& board,int i,int j,string word){

    if(j+word.size()>board.size()){
            return false;
        }
    else if(j>0 && board[i][j-1] != '+' ){
            return false;
        }

    else if( board[i][j+word.size()] !='+'){
        return false;
    }    



    for(int jj=j,ii=i;jj - j<word.size();jj++){
        if(board[ii][jj] != '-' && board[ii][jj]!=word[jj-j]){
            return false;
        }

    }


    return true;

}

bool cptwv(vector<vector<char>>& board,int i,int j,string word){

    if(i+word.size()>board.size()){
            return false;
        }
        else if(i>0 && (board[i-1][j] != '+')){
            return false;
        }
        else if(i + word.size() < board.size() && board[i+word.size()][j] !='+'){
            return false;
        }
    for(int ii=i,jj=j;ii - i<word.size();ii++){
        if(board[ii][jj] != '-' && (board[ii][jj]!=word[ii-i])){
            return false;
        }
     
    }
        
    return true;

}

void ptwh(vector<vector<char>>& board,int i,int j,string word,bool reset[]){
    for(int jj=j,ii=i;jj - j<word.size();jj++){
        if(board[ii][jj] == '-'){
            reset[jj-j]=true;
            board[ii][jj]=word[jj-j];
        }
        
      
        
    }

}

void ptwv(vector<vector<char>>& board,int i,int j,string word,bool reset[]){
    for(int ii=i,jj=j;ii - i<word.size();ii++){
        if(board[ii][jj] == '-'){
            reset[ii-i]=true;
        board[ii][jj]=word[ii-i];
        }
      
      
        
    }

}

void uptwh(vector<vector<char>>& board,int i,int j,string word,bool reset[]){
    for(int jj=j,ii=i;jj - j<word.size();jj++){
       if(reset[jj-j] == true){
        board[ii][jj]='-';
    }
    }
    
}

void uptwv(vector<vector<char>>& board,int i,int j,string word,bool reset[]){
    for(int ii=i,jj=j;ii - i<word.size();ii++){
        if(reset[ii-i] == true){
        board[ii][jj]='-';
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

        // cout<< " level: " << " "<<to_string(wpsf)<< " " <<words[wpsf]<<"-->region U "<<endl;
        for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            
            if(board[i][j] =='-' || board[i][j] == words[wpsf][0]){
                if(cptwh(board,i,j,words[wpsf])){
                    bool reset[words[wpsf].size()] {false};
                    ptwh(board,i,j,words[wpsf],reset);

// cout<< " level: " << " "<<to_string(wpsf)<< " " <<words[wpsf]<<"-->region U "<< "Horizontal do"<<endl;

                    crosswordMy(board,words,wpsf+1,tw);
// cout<< " level: " << " "<<to_string(wpsf)<< " " <<words[wpsf]<<"-->region U "<< "Horizontal done"<<endl;
                    uptwh(board,i,j,words[wpsf],reset);

                }

                if(cptwv(board,i,j,words[wpsf])){
                    bool reset[words[wpsf].size()] {false};
                    ptwv(board,i,j,words[wpsf],reset);
                    
// cout<< " level: " << " "<<to_string(wpsf)<< " " <<words[wpsf]<<"-->region U "<< "Vertically do"<<endl;

                    crosswordMy(board,words,wpsf+1,tw);


// cout<< " level: " << " "<<to_string(wpsf)<< " " <<words[wpsf]<<"-->region U "<< "Vertically done"<<endl;

                    uptwv(board,i,j,words[wpsf],reset);

                }

            }
            
        }
        }

        // cout<< " level: " << " "<<to_string(wpsf)<< " " <<words[wpsf]<<"-->region D "<<endl;
    }