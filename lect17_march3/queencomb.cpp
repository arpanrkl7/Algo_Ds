#include<iostream>
#include<string>
using namespace std;

void printCombb(int cq,bool boxes[],string asf,int tq,int tb,int lqp){

    if(cq>tq){
        cout << asf << endl;
        return;
    }

    for(int i=lqp+1;i<tb;i++){
        if(boxes[i] == false){
            boxes[i]=true;
        printCombb(cq+1,boxes,asf + "q" + to_string(cq) + "b" + to_string(i),tq,tb,i);
        boxes[i] = false;
        }
    }


}
main(int argc,char** argv){

bool boxes[5];
printCombb(1,boxes,"",2,5,-1);

}