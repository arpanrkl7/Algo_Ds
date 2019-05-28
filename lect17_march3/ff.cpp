#include<iostream>
#include<vector>
#include<string>
using namespace std;

void ff(int cr,int cc,int dr,int dc,vector<vector<int>> arr,string psf){

   if(cr == dr && cc == dc){
       cout << psf << endl;
       return;
   }

    if(cc<dc && arr[cr][cc+1]!=1 &&  arr[cr][cc+1]!=2){
        arr[cr][cc+1]=2;
        ff(cr,cc+1,dr,dc,arr,psf + "r");
        arr[cr][cc+1]=0;
    }
    if(cr<dr && arr[cr+1][cc]!=1 && arr[cr+1][cc]!=2){
        arr[cr+1][cc]=2;
        ff(cr+1,cc,dr,dc,arr,psf + "d");
        arr[cr+1][cc]=0;
    }
    if(cc-1>=0 && arr[cr][cc-1]!=1 && arr[cr][cc-1]!=2){
        arr[cr][cc-1]=2;
        ff(cr,cc-1,dr,dc,arr,psf + "l");
        arr[cr][cc-1]=0;

    }
    if(cr-1>=0 && arr[cr-1][cc]!=1 &&  arr[cr-1][cc]!=2){
        arr[cr-1][cc]=2;
        ff(cr-1,cc,dr,dc,arr,psf + "t");
        arr[cr-1][cc]=0;

    }
}

int main(int argc,char** argv){
        vector<vector<int>> arr {{0,1,0,0,0,0},{0,1,0,1,1,0},{0,1,0,1,1,0},{0,0,0,0,0,0},{0,1,0,1,1,0},{0,1,0,0,0,0}};
        // vector<vector<bool>> mark;
        ff(0,0,5,5,arr,"");
    }


   
