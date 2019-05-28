#include<iostream>
#include<string>
#include<vector>
using namespace std;


void printPermmy(int cq,bool boxes[],string asf,int tq,int tb){

    if(cq>tq){
        cout << asf  << endl;
        return;
    }

    for(int i=0;i<tb;i++){
        if(boxes[i]==false){
        boxes[i]=true;
        printPermmy(cq+1,boxes,asf + "q" + to_string(cq) + "b" + to_string(i) ,tq,tb);
        boxes[i]=false;
        }

    }
}



void printPermsir(int cq,bool boxes[],string asf,int tq,int tb){
    if(cq>tq){
        cout << asf << endl;
        return;
    }
    for(int b = 0;b<tb;b++){
        if(boxes[b] == false){
            boxes[b]=true;
            printPermsir(cq+1,boxes,asf + "q" + to_string(cq) + "b" + to_string(b) ,tq,tb);
            boxes[b]=false;
        }
    }
}

int main(int argc,char** argv){
    bool boxes[5];
    printPermsir(1,boxes,"",2,5);


}