#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printPerm(int cq,int boxbm,string asf,int tq,int tb){

    if(cq>tq){
        cout << asf << endl;
        return;
    }

    for(int i=0;i<tb;i++){
        int bm=1<<i;
        if((boxbm & (bm)) ==0){
            boxbm=(boxbm ^ (bm));
         printPerm(cq+1,boxbm,asf + "q" + to_string(cq) + "b" + to_string(i) ,tq,tb);
         boxbm=(boxbm ^ (bm));


        }

    }


}

int main(int argc,char** argv){
    printPerm(1,0,"",2,4);


}

