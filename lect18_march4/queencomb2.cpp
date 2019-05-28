#include<iostream>
#include<vector>
#include<string>
using namespace std;

void queenComb(int cb,int tb,int cq,int tq,string asf){

    if(cb==tb){
        if(cq==tq){
        cout << asf << endl;
        }
        return;
    }

    queenComb(cb+1,tb,cq+1,tq,asf+ "q" + to_string(cq) + "b" + to_string(cb));
    queenComb(cb+1,tb,cq,tq,asf);
}

main(int argc,char** argv){

queenComb(0,5,0,2,"");

}

