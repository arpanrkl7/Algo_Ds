#include<iostream>
#include<vector>
#include<string>
using namespace std;
void equiSetsVector(int arr[],int n,int idx,vector<int> set1,int sos1,vector<int> set2,int sos2);
void tarsumstring(int arr[],int idx,int tar,string asf,int n);

void tarsumstring(int arr[],int idx,int tar,string asf,int n){
    if(idx==n){
        if(tar==0){
            cout << asf << endl;
        }
        return;

    }
        
        tarsumstring(arr,idx+1,tar-arr[idx],asf + to_string(arr[idx]) + " ",n);
        tarsumstring(arr,idx+1,tar,asf,n);

    


}
void tarsum(int arr[],int idx,int tar,vector<int>& asf,int n){

}

void equiSets(int arr[],int n,int idx,string set1, int sos1,string set2,int sos2){
    if(idx == n){
    if(sos1 == sos2){
        cout << set1 << " ";
        cout << set2 << " ";
        cout << endl;
    }
            return;

    }
    

    equiSets(arr,n,idx+1,set1+ to_string(arr[idx]) + " ",sos1+arr[idx],set2,sos2);
    equiSets(arr,n,idx+1,set1,sos1,set2 + to_string(arr[idx]) + " ",sos2+arr[idx]);
}


void equiSetsVector(int arr[],int n,int idx,vector<int> set1,int sos1,vector<int> set2,int sos2){
    if(idx == n){
    if(sos1 == sos2){
        for(int i=0;i<set1.size();i++){
            cout << set1[i] << " ";
        }
        for(int i=0;i<set2.size();i++){
            cout << set2[i] << " ";
        }
        cout << endl;
    }
            return;

    }
    
    set1.push_back(arr[idx]);
    equiSetsVector(arr,n,idx+1,set1,sos1+arr[idx],set2,sos2);
    set1.pop_back();

    set2.push_back(arr[idx]);
    equiSetsVector(arr,n,idx+1,set1,sos1,set2,sos2+arr[idx]);
    set2.pop_back();
}

vector<vector<int>> tss(int arr[],int idx,int tar,int n){

    if(idx==n){
        vector<vector<int>> bsets;
        if(tar==0){
            vector<int> b;
            bsets.push_back(b);
        }
        return bsets;
    }

    vector<vector<int>> ires=tss(arr,idx+1,tar-arr[idx],n);
    vector<vector<int>> eres=tss(arr,idx+1,tar,n);
    vector<vector<int>> mres;

    for(int i=0;i<ires.size();i++){
        ires[i].push_back(arr[idx]);
        mres.push_back(ires[i]);

    }

    for(int i=0;i<eres.size();i++){
        mres.push_back(eres[i]);
    }

  

    return mres;
}

int main(int argc,char** argv){
    int arr[]={10,20,30,40,50};
    vector<vector<int>> result=tss(arr,0,50,5); 
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    // tarsumstring(arr,0,50,"",5);
    //    equiSets(arr,7,0,"",0,"",0);
    // vector<int> set1;
    // vector<int> set2;
    //     equiSetsVector(arr,7,0,set1,0,set2,0);
}