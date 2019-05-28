#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>>* gts(int arr[],int tar,int sp,int ep){

    if(sp == ep){
        vector<vector<int>>* bsets=new vector<vector<int>>();
        if(tar ==0){
            vector<int> bv;
            bsets->push_back(bv);
        }
        return bsets;
    }

    vector<vector<int>>* isets=gts(arr,tar - arr[sp],sp+1,ep);
    vector<vector<int>>* esets=gts(arr,tar,sp+1,ep);
    vector<vector<int>>* msets=new vector<vector<int>>();

    for(int i=0;i<isets->size();i++){
        (*isets)[i].push_back(arr[sp]);
        msets->push_back((*isets)[i]);
    }

    for(int i=0;i<esets->size();i++){
        msets->push_back((*esets)[i]);
    }

    delete isets;
    delete esets;

    return msets;



}

int main(int argc,char** argv){

    int arr[]={10,20,30,40,50,60,70};
    int tar = 70;
    vector<vector<int>>* res = gts(arr,tar,0,7);
    for(int i=0;i<res->size();i++){
        for(int j=0;j<(*res)[i].size();j++){
            cout << (*res)[i][j] << " ";
        }
        cout << endl;
    }
}

