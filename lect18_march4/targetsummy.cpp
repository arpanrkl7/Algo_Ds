#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> tss(int arr[],int tar,int id,int n){

    if(id==n){
        vector<vector<int>> bsets;
        if(tar==0){
            vector<int> b;
            bsets.push_back(b);
        }
        return bsets;
    }

    vector<vector<int>> ires=tss(arr,tar-arr[id],id+1,n);
    vector<vector<int>> eres=tss(arr,tar,id+1,n);
    vector<vector<int>> mres;

    for(int i=0;i<ires.size();i++){
        ires[i].push_back(arr[id]);
        mres.push_back(ires[i]);

    }

    for(int i=0;i<eres.size();i++){
        mres.push_back(eres[i]);
    }

  

    return mres;
}

int main(int argc,char** argv){

    int arr[]={10,20,30,40,50};
    vector<vector<int>> result=tss(arr,50,0,5); 
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


}

