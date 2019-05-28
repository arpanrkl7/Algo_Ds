#include<iostream>
#include<string>
#include<vector>
using namespace std;
void displayr(int* arr,int n,int vidx);
int max(int* arr,int n,int vidx);
bool find(int* arr,int n,int vidx,int d);
int fi(int* arr,int n,int vidx,int d);
int li(int* arr,int n,int vidx,int d);
int* allOccurence(int* arr,int n,int vidx,int d);
vector<string> getss(string str,int ep);
vector<string> printPath(int rs,int cs,int re,int ce);
vector<string> gkpc(string str);
vector<string> getStairsPath(int n);
string arr[]={".;","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
vector<string> gmpmm(int rs,int cs,int re,int ce);
void printss(string ques, string asf);
void printkpc(string ques, string asf);
void printStairs(int n,string asf);
void printMaze(int cr,int cc,int dr,int dc,string asf);
void ff(int cr,int cc,int dr,int dc,vector<vector<int>>& arr,string psf);
void printPermmy(int cq,bool boxes[],string asf,int tq,int tb);
void printCombb(int cq,bool boxes[],string asf,int tq,int tb,int lqp);




int max(int* arr,int n,int vidx){
    if(vidx == n-1){
        return arr[vidx];
    } 

    int res=max(arr,n,vidx+1);
    if(res > arr[vidx]){
        return res;
    }
    else
    return arr[vidx];
}

bool find(int* arr,int n,int vidx,int d){
    if(n == vidx){
        return false;
    }
    bool res=find(arr,n,vidx+1,d);
    if(res == true){
        return true;
    }
    else{
        if(arr[vidx] == d){
            return true;
        }
        else
        return false;
    }

}

int fi(int* arr,int n,int vidx,int d){
    if(n == vidx){
        return -1;
    }
    if(arr[vidx] == d){
        return vidx;
    }


    int ans=fi(arr,n,vidx+1,d);
    return ans;
}

int li(int* arr,int n,int vidx,int d){
    if(vidx == n-1){
       return vidx;
    }


    int ans=li(arr,n,vidx+1,d);
    if(arr[ans] == d){
        return ans;
    }
    else if(arr[vidx] == d){
        return vidx;
    }
    else return -1;

}
int count=0;
int size=0;

int* allOccurence(int* arr,int n,int vidx,int d){
     if(vidx == n){
         size=count;
        int* arr1=new int[count];
        return arr1;
    }

    if(arr[vidx] == d){
        count++;
    }
   

    int* arrres=allOccurence(arr,n,vidx+1,d);
    if(arr[vidx] == d){
        arrres[count-1] = vidx;
        count--;
    }
    return arrres;
}

void displayr(int* arr,int n,int vidx){
    if(n == vidx){
        return;

    }
    displayr(arr,n,vidx+1);
    cout << arr[vidx] << " ";
}

vector<string> getss(string str,int ep){

    if(ep<0){
        vector<string> bres;
        bres.push_back("");
        return bres;

    }

    char ch=str[ep];
    vector<string> rres=getss(str,ep-1);
    vector<string> mres;
    for(int i=0;i<rres.size();i++){
        mres.push_back(rres[i] + "_");
        mres.push_back(rres[i] + ch);


    }
    return mres;
}


vector<string> printPath(int rs,int cs,int re,int ce){

    if(cs == ce && rs == re){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    vector<string> hPath;
    vector<string> vPath;
    if(cs<ce){
    hPath=printPath(rs,cs+1,re,ce);
    }
    if(rs<re){
    vPath=printPath(rs+1,cs,re,ce);
    }
    vector<string> mPath;
    for(int i=0;i<hPath.size();i++){
        mPath.push_back(hPath[i] + "H");

    }
    for(int i=0;i<vPath.size();i++){
        mPath.push_back(vPath[i] + "V");
    }

    return mPath;
}



vector<string> gkpc(string str){

    if(str.size() == 0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    char first=str[0];
    vector<string> rres=gkpc(str.substr(1));
    vector<string> mres;
    string word=arr[(first-'0')-1];
    for(int i=0;i<word.size();i++){ 
        for(int j=0;j<rres.size();j++){
            mres.push_back(word[i] + rres[j]);
        }
    }

    return mres;

}



vector<string> getStairsPath(int n){
            vector<string> bres;

    if(n==0){

        bres.push_back("");
        return bres;
    }
    if(n<0){
        return bres;
    }


    vector<string> path1=getStairsPath(n-1);
    vector<string> path2=getStairsPath(n-2);
    vector<string> path3=getStairsPath(n-3);
    vector<string> mres;

    for(int i=0;i<path1.size();i++){
        mres.push_back("1" + path1[i]);
    }
    for(int i=0;i<path2.size();i++){
        mres.push_back("2" + path2[i]);
    }
    for(int i=0;i<path3.size();i++){
        mres.push_back("3" + path3[i]);
    }

    return mres;


}

vector<string> gmpmm(int rs,int cs,int re,int ce){
    if(cs == ce && rs == re){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }



    vector<string> mPath;
    for(int i=1;i<=ce-cs;i++){
        vector<string> hPath=gmpmm(rs,cs+i,re,ce);
        for(int j=0;j<hPath.size();j++){
        mPath.push_back(hPath[j] + "H" + to_string(i));
        }
    }

    for(int i=1;i<=re-rs;i++){
        vector<string> vPath=gmpmm(rs+i,cs,re,ce);
        for(int j=0;j<vPath.size();j++){
        mPath.push_back(vPath[j] + "V" + to_string(i));
        }
    }

    for(int i=1,j=1;i<=re-rs && j<=ce-cs ; i++,j++){
        vector<string> dPath=gmpmm(rs+i,cs+i,re,ce);
        for(int j=0;j<dPath.size();j++){
        mPath.push_back(dPath[j] + "D" + to_string(i));
        }
    }
    return mPath;
}




void printss(string ques, string asf){
    if(ques == ""){
        cout << asf << endl;
        return;
    }

    char first=ques[0];
    string qsf=ques.substr(1);
    printss(qsf,asf + first);
    printss(qsf,asf + "_");
}





void printkpc(string ques, string asf){
    if(ques.length()==0){
        cout << asf << endl;
        return;
    }

    char first=ques[0];
    int no=first-'0';
    string options=arr[no-1];
    for(int i=0;i<options.length();i++){
        printkpc(ques.substr(1),asf+options[i]);
    }
}



void printStairs(int n,string asf){
    

    if(n==0){
        cout << asf << endl;
        return;
    }
    if(n<0){
        return;
    }

    printStairs(n-1,asf+to_string(1));
    printStairs(n-2,asf+to_string(2));
    printStairs(n-3,asf+to_string(3));
}



void printMaze(int cr,int cc,int dr,int dc,string asf){

    if(cr>dr || cc>dc){
        return;
    }
    if(cr==dr && cc==dc){
        cout << asf << endl;
        return;
    }

    printMaze(cr,cc+1,dr,dc,asf + "H");
    printMaze(cr+1,cc,dr,dc,asf + "V");

}

void printMazemm(int rs,int cs,int re,int ce,string asf){

    if(rs == re && cs == ce){
            cout << asf << endl;
            return;
    }

    for(int i=1;i<=ce-cs;i++){
        printMazemm(rs,cs+i,re,ce,asf + "H"+to_string(i));
        
        
    }

    for(int i=1;i<=re-rs;i++){
        printMazemm(rs+i,cs,re,ce,asf + "V"+to_string(i));
        
        
    }

    for(int i=1,j=1;i<=re-rs && j<=ce-cs ; i++,j++){
        printMazemm(rs+i,cs+i,re,ce,asf + "D"+to_string(i));
        
        
    }


}



void ff(int cr,int cc,int dr,int dc,vector<vector<int>>& arr,string psf){
    if(cr == dr && cc == dc){
        cout << psf << endl;
        return;
    }


    if(cr+1<=dr && arr[cr+1][cc]!=1){
        arr[cr+1][cc] = 1;
        ff(cr+1,cc,dr,dc,arr,psf + "D");
        arr[cr+1][cc] = 0;
    }
    if(cc+1<=dc && arr[cr][cc+1]!=1) {
        arr[cr][cc+1] = 1;
        ff(cr,cc+1,dr,dc,arr,psf + "R");
        arr[cr][cc+1] = 0;
    }
    if(cr-1>=0 && arr[cr-1][cc]!=1){
        arr[cr-1][cc] = 1;
        ff(cr-1,cc,dr,dc,arr,psf + "T");
        arr[cr-1][cc] = 0;
    }
    if(cc-1>=0 && arr[cr][cc-1]!=1){
        arr[cr][cc-1] = 1;
        ff(cr,cc-1,dr,dc,arr,psf + "L");
        arr[cr][cc-1] = 0;
    }
}






void printPermmy(int cq,bool boxes[],string asf,int tq,int tb){
    if(cq>tq){
        cout << asf << endl;
        return;
    }

    for(int i=0;i<tb;i++){
        if(boxes[i]==false){
            boxes[i]=true;
    printPermmy(cq+1,boxes,asf + "q" + to_string(cq) + "b" + to_string(i),tq,tb);
    boxes[i]=false;
    }
    }
}

void printPerm(int cq,int boxbm,string asf,int tq,int tb){

    if(cq>tq){
        cout << asf << endl;
        return;
    }

    for(int i=0;i<tb;i++){
        int bm = 1<<i;
        if((bm & (boxbm)) == 0){
            boxbm = (bm ^ boxbm);
            printPerm(cq+1,boxbm,asf + "q" + to_string(cq) + "b" + to_string(i),tq,tb);
            boxbm = (bm^boxbm);
        }
    }
}



void printCombb(int cq,bool boxes[],string asf,int tq,int tb,int lqp){
    if(cq>tq){
        cout << asf << endl;
        return;
    }

    for(int i=lqp+1;i<=tb;i++){
        if(boxes[i] == false){
            boxes[i] = true;
    printCombb(cq+1,boxes,asf + "q" + to_string(cq) + "b" + to_string(i),tq,tb,i);
            boxes[i] = false;
        }
    }
}

void printCombb2(int cq,int cb,string asf,int tq,int tb){

    if(cq == tq){
        cout << asf << endl;
        return;
    }
    if(cb == tb){
        return;
    }

    printCombb2(cq+1,cb+1,asf + "q" +  to_string(cq) + "b" + to_string(cb) ,tq,tb);
    printCombb2(cq,cb+1,asf,tq,tb);
}

vector<vector<int>>* gts(int arr[],int tar,int sp,int ep){
    if(tar == 0){
        vector<int> bb;
        vector<vector<int>>* base = new vector<vector<int>>();
        base->push_back(bb);
        return base;

    }
    if(sp == ep){
        vector<vector<int>>* base = new vector<vector<int>>();
        return base;
    }

    vector<vector<int>>* path1 = gts(arr,tar - arr[sp],sp+1,ep);
    vector<vector<int>>* path2 = gts(arr,tar,sp+1,ep);
    vector<vector<int>>* mPath = new vector<vector<int>>();
    for(int i=0;i<path1->size();i++){
        vector<int> bres = (*path1)[i];
        bres.push_back(arr[sp]);
        mPath->push_back(bres);
    }
    for(int i=0;i<path2->size();i++){
        mPath->push_back((*path2)[i]);
    }
    return mPath;
}
int count1 = 0;
void nqueenPerm(vector<vector<bool>>& board,int cq,int cb,string asf){
    if(cq==4){
        count1++;
       cout << count1 << endl;
        return;
    }
    

    for(int i=0;i<board.size()*board.size();i++){
        int row = i/board.size();
        int col = i%board.size();
        if(board[row][col] == false){
            board[row][col] = true;
            nqueenPerm(board,cq+1,cb+1,asf + "q" + to_string(cq) + "b" + to_string(row) + to_string(col));
            board[row][col] = false;
        }
    }
}

bool isQueenSafe(vector<vector<bool>>& board,int row,int col){
    for(int i=row,j=0;j<board.size();j++){
        if(j == col){
            continue;
        }
        else{
            if(board[i][j] == false){
                continue;
            }
            else{
                return false;
            }
      
        }
    }
    for(int i =0,j=col;i<board.size();i++){
        if(i==row){
            continue;
        }
        else{
            if(board[i][j] == false){
                continue;
            }
            else{
                return false;
            }
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j] == true)
    return false; 
    }
    for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){
        if(board[i][j] == true)
    return false; 
    }
    for(int i = row+1,j=col-1;i<board.size() && j>=0;i++,j--){
        if(board[i][j] == true)
    return false; 
    }
    for(int i = row+1,j=col+1;i<board.size() && j<board.size();i++,j++){
        if(board[i][j] == true)
    return false; 
    }
    return true;

}

bool isBoardSafe(vector<vector<bool>>& board){
    for(int i=0;i<board.size()*board.size();i++){
        int row = i/board.size();
        int col = i%board.size();
        bool qs = false;
        if(board[row][col] == true){
            qs = isQueenSafe(board,row,col);
            if(qs == false){
            return false;
        }
        }
        
       

    }
    return true;

}

void nqueenComb(vector<vector<bool>>& board,int cq,int cb,string asf,int lqp){
    if(cq==4){
        if(isBoardSafe(board) == true){
            cout << asf << endl;
        }
       // count1++;
       // cout << asf << endl;
      //  cout << count1 << endl;
        return;
    }
    

    for(int i=lqp+1;i<board.size()*board.size();i++){
        int row = i/board.size();
        int col = i%board.size();
        if(board[row][col] == false){
            board[row][col] = true;
            nqueenComb(board,cq+1,cb+1,asf + to_string(row) + to_string(col) + " ",i);
            board[row][col] = false; 
        }
    }
    
}

void nqueen2nComb(vector<vector<bool>>& board,int cq,int cb,string asf){
    if(cb == board.size()*board.size()){
        return;
    }
    if(cq == 4){
        if(isBoardSafe(board)){
            cout << asf << endl;

        }
        return;
    }

    int row = cb/board.size();
    int col = cb%board.size();
    if(board[row][col] == false){
        board[row][col] = true;
        nqueen2nComb(board,cq+1,cb+1,asf + to_string(row) + to_string(col) + " ");
        board[row][col] = false;
        nqueen2nComb(board,cq,cb+1,asf);
    }
}

void coinChangePerm(int coins[],int amt,string asf){
    if(amt == 0){
        cout << asf << endl;
        return;
    }
    if(amt < 0){
        return;
    }

    for(int i=0;i<3;i++){
        coinChangePerm(coins,amt-coins[i],asf + to_string(coins[i]) + " ");
    }
}

void coinChangeComb(int coins[],int amt,string asf,int lcp){
    if(amt == 0){
        cout << asf << endl;
        return;
    }
    if(amt < 0){
        return;
    }

    for(int i=lcp;i<3;i++){
        
        coinChangeComb(coins,amt-coins[i],asf + to_string(coins[i]) + " ",i);
        
    }
}

bool isNoSafe(vector<vector<int>>& board,int no,int row,int col){

    for(int i=row,j=0;j<board.size();j++){
        if(board[i][j] == no && j!=col){
            return false;
        }
    }

    for(int i=0,j=col;i<board.size();i++){
        if(board[i][j] == no && i!=row){
            return false;
        }
    }

    int i=(row/3)*3;
    int j=(col/3)*3;
    for(int ii=i;ii<i+3;ii++){
        for(int jj=j;jj<j+3;jj++){
            if(board[ii][jj] == no && ii!=row && jj!=col){
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
        return;
    }

    
        int row = bno/board.size();
        int col = bno%board.size();
        if(board[row][col] == 0){
            for(int i=1;i<=9;i++){
                if(isNoSafe(board,i,row,col)){
                    board[row][col] = i;
                    sudoku(board,bno+1);
                    board[row][col] = 0;
                }
            }
        }
        else
        sudoku(board,bno+1);
    

}

int rbm[9]{0};
int cbm[9]{0};
int sm[3][3]{0};

bool isNoSafebm(int no,int row,int col){
    return (((rbm[row] & 1<<no) == 0) && ((cbm[col] & 1<<no) == 0) && ((sm[row/3][col/3] & 1<<no) == 0));
}



void sudokubm(vector<vector<int>>& board,int bno){
    if(bno == board.size()*board.size()){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
       // return;
    }

    
        int row = bno/board.size();
        int col = bno%board.size();
        if(board[row][col] == 0){
            for(int i=1;i<=9;i++){
                if(isNoSafebm(i,row,col)){
                    rbm[row] = 1<<i;
                    cbm[col] = 1<<i;
                    sm[row/3][col/3] = 1<<i;
                    board[row][col] = i;
                    sudokubm(board,bno+1);
                    board[row][col] = 0;
                    rbm[row] = (rbm[row] ^ (1<<i));
                    cbm[col] = (cbm[col] ^ (1<<i));
                    sm[row/3][col/3] = (sm[row/3][col/3] ^ (1<<i));

                }
            }
        }
        else
        sudokubm(board,bno+1);


}

bool cptwh(vector<vector<char>>& board,int i,int j,string word){
    if(j>0 && board[i][j-1]=='-'){
        return false;
    }

    if(j+word.size()-1<board.size() && board[i][j+word.size()] == '-'){
        return false;
    }

    for(int ii=i,jj=j;jj-j<word.size();jj++){
        if(board[ii][jj]!='-' && board[ii][jj]!=word[jj-j]){
            return false;
        }
    }

    return true;

}

bool cptwv(vector<vector<char>>& board,int i,int j,string word){
    if(i>0 && board[i-1][j] == '-'){
        return false;
    }

    if(i+word.size()-1<board.size() && board[i+word.size()][j] == '-'){
        return false;
    }

    for(int ii=i,jj=j;ii-i<word.size();ii++){
        if(board[ii][jj] !='-' && board[ii][jj] != word[ii-i]){
            return false;
        }
    }

    return true;


}

void ptwh(vector<vector<char>>& board,int i,int j,string word){

    for(int ii=i,jj=j;jj-j<word.size();jj++){
        board[ii][jj] = word[jj-j];
    }

}

void ptwv(vector<vector<char>>& board,int i,int j,string word){

    for(int ii=i,jj=j;ii-i<word.size();ii++){
        board[ii][jj] = word[ii-i];
    }

}

void uptwh(vector<vector<char>>& board,int i,int j,string word){
    for(int ii=i,jj=j;jj-j<word.size();jj++){
        board[ii][jj] = '-';
    }

}

void uptwv(vector<vector<char>>& board,int i,int j,string word){

    for(int ii=i,jj=j;ii-i<word.size();ii++){
        board[ii][jj] = '-';
    }


}

void crossword(vector<vector<char>>& board,string words[],int wpsf,int tw){

    if(wpsf == tw){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    for(int i=0;i<board.size()*board.size();i++){
        int row = i/board.size();
        int col = i%board.size();
        if(board[row][col] == '-' || board[row][col] == words[wpsf][0]){
            if(cptwh(board,row,col,words[wpsf])){
                ptwh(board,row,col,words[wpsf]);
                crossword(board,words,wpsf+1,tw);
                uptwh(board,row,col,words[wpsf]);

            }
            else if(cptwv(board,row,col,words[wpsf])){
                ptwv(board,row,col,words[wpsf]);
                crossword(board,words,wpsf+1,tw);
                uptwv(board,row,col,words[wpsf]);

            }


        }
        

    }
}

void tarsumstring(int arr[],int idx,int tar,string asf,int n){

    if(tar == 0){
        cout << asf << endl;
        return;
    }

    if(idx == n){
        return;
    }


    tarsumstring(arr,idx+1,tar - arr[idx], asf + to_string(arr[idx]) + " ", n);
    tarsumstring(arr,idx+1,tar,asf,n);
}

void tarsumvector(int arr[],int idx,int tar,vector<int>& asf,int n){

    //practice for different euler


    // if(tar == 0){
       
       
       
    //     cout << endl;
    //     return;
    // }

    if(idx == n){
         for(int i=0;i<asf.size();i++){
            cout << asf[i] << " ";
        }
        cout << endl;
        
        return;
    }
    tarsumvector(arr,idx+1,tar,asf,n);
    
    asf.push_back(arr[idx]);
    tarsumvector(arr,idx+1,tar - arr[idx], asf , n);
  //  asf.pop_back();
    
    
}

void equiSets(int arr[],int n,int idx,string set1, int sos1,string set2,int sos2){

    if(idx == n){
        if(sos1 == sos2){
           // if(set1<(set2)){
            cout << set1 << "-----"  << set2;
            cout << endl;
          //  }
        }
        return;
    }

    equiSets(arr,n,idx+1,set1 + to_string(arr[idx]) + " ", sos1+arr[idx],set2,sos2);
    if(idx!=0){
    equiSets(arr,n,idx+1,set1,sos1,set2 + to_string(arr[idx]) + " ", sos2+arr[idx]);
    }
}

void permq(string q,string a){

    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    for(int i=0;i<q.size();i++){
        char ans = q[i];
        string nques = q.substr(0,i) + q.substr(i+1);
        permq(nques, a + ans);

    }
}

void perma(string q, string a){
    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    for(int i=0;i<a.size()+1;i++){

        string nq = q.substr(1);
        string na = a.substr(0,i) + q[0] + a.substr(i);
        perma(nq,na);
    }
}



int main(int argc,char** argv){
// int* arr=new int[5];
//     arr[0]=55;
//     arr[1]=33;
//     arr[2]=55;
//     arr[3]=55;
//     arr[4]=77;
//     cout << max(arr,5,0) << endl;
//     displayr(arr,5,0);
//     cout << endl;
//     cout << find(arr,5,0,99) << endl;
//     cout << fi(arr,5,0,55) << endl;
//     cout << li(arr,5,0,555) << endl;
//     int* arrres1=allOccurence(arr,5,0,55);
//     for(int i=0;i<size;i++){
//         cout << arrres1[i] << " ";
//     }
//     cout << endl;

//     vector<string> result=getss("abc",2);
//     for(int i=0;i<result.size();i++){
//         cout << result[i] + " " << endl;
//     }

//     vector<string> result1=printPath(0,0,2,3);
//     for(int i=0;i<result1.size();i++){
//         cout << result1[i] + " " << endl;
//     }

//     vector<string> result2 = gkpc("234");
//     for(int i=0;i<result2.size();i++){
//         cout << result2[i] + " " << endl;
//     }

//     vector<string> result3 = getStairsPath(3);
//     for(int i=0;i<result3.size();i++){
//         cout << result3[i] + " " << endl;
//     }

//     vector<string> result4=gmpmm(0,0,2,2);
//     for(int i=0;i<result4.size();i++){
//         cout << result4[i] + " " << endl;
//     }

//     printss("abc","");
//     printkpc("234","");
//     printStairs(4,"");
//     printMaze(0,0,2,2,"");
//     printMazemm(0,0,2,2,"");

//     vector<vector<int>> arr1 {{0,1,0,0,0,0},{0,1,0,1,1,0},{0,1,0,1,1,0},{0,0,0,0,0,0},{0,1,0,1,1,0},{0,1,0,0,0,0}};
//         ff(0,0,5,5,arr1,"");

//     bool boxes[4];
// //     // printPermmy(1,boxes,"",2,4);
//     printCombb(1,boxes,"",2,5,-1);
//         // printPerm(1,0,"",2,4);

        // printCombb2(0,0,"",2,4);
    //     int arr[]={10,20,30,40,50,60,70};
    // int tar = 70;
    // vector<vector<int>>* res = gts(arr,tar,0,7);
    // for(int i=0;i<res->size();i++){
    //     for(int j=0;j<(*res)[i].size();j++){
    //         cout << (*res)[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //  vector<vector<bool>> board {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    // // nqueenPerm(board,0,0,"");
    //  nqueenComb(board,0,0,"",-1);
    //  nqueen2nComb(board,0,0,"");
    // int arr[]{2,3,5};
    // // coinChangePerm(arr,7,"");
    // coinChangeComb(arr,7,"",0);

    // vector<vector<int>> board{{3,0,6,5,0,8,4,0,0},
    //                           {5,2,0,0,0,0,0,0,0},
    //                           {0,8,7,0,0,0,0,3,1},
    //                           {0,0,3,0,1,0,0,8,0},
    //                           {9,0,0,8,6,3,0,0,5},
    //                           {0,5,0,0,9,0,6,0,0},
    //                           {1,3,0,0,0,0,2,5,0},
    //                           {0,0,0,0,0,0,0,7,4},
    //                           {0,0,5,2,0,6,3,0,0}};
   // sudoku(board,0);   
    // for(int i=0;i<board.size();i++){
    //     for(int j=0;j<board.size();j++){
    //         if(board[i][j] !=0){
    //         rbm[i] = (rbm[i] ^ (1<<board[i][j]));
    //         cbm[j] = (cbm[j] ^ (1<<board[i][j]));
    //         sm[i/3][j/3] = (sm[i/3][j/3] ^ (1<<board[i][j]));
    //         }
            
    //     }
    // }
    // sudokubm(board,0);

    // vector<vector<char>> board{{'+','-','+','+','+','+','+','+','+','+'},
    //                            {'+','-','+','+','+','+','+','+','+','+'},
    //                            {'+','-','-','-','-','-','-','-','+','+'},
    //                            {'+','-','+','+','+','+','+','+','+','+'},
    //                            {'+','-','+','+','+','+','+','+','+','+'},
    //                            {'+','-','-','-','-','-','-','+','+','+'},
    //                            {'+','-','+','+','+','-','+','+','+','+'},
    //                            {'+','+','+','+','+','-','+','+','+','+'},
    //                            {'+','+','+','+','+','-','+','+','+','+'},
    //                            {'+','+','+','+','+','+','+','+','+','+'}};
    // string words[4]={"agra","norway","england","gwalior"};
    // crossword(board,words,0,4);
    int arr[]{10,20,30,40,50,60,70};
    //tarsumstring(arr,0,70,"",7);
    // vector<int> asf;
    // tarsumvector(arr,0,30,asf,3);

  //  equiSets(arr,7,0,"",0,"",0);
 // permq("abc","");
    perma("abc","");
}

