#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> tss1(int arr[],int idx,int tar,int n){

    if(idx == n){
        vector<vector<int>> bres;
        if(tar == 0){
            vector<int> b;
            bres.push_back(b);
        }
        return bres;
    }

    vector<vector<int>> itss=tss1(arr,idx+1,tar-arr[idx],n);
    vector<vector<int>> etss=tss1(arr,idx+1,tar,n);
    vector<vector<int>> mres;
    
    for(int i=0;i<itss.size();i++){
        itss[i].push_back(arr[idx]);
        mres.push_back(itss[i]);
    }

    for(int i=0;i<etss.size();i++){
        mres.push_back(etss[i]);
    }

    return mres;
}

void tarsumstring(int arr[],int idx,int tar,string asf,int n){

    if(idx == n){
        if(tar == 0){
            cout << asf << " " ;
            cout << endl;
        }
        return;
    }

    tarsumstring(arr,idx+1,tar-arr[idx],asf + to_string(arr[idx]) + " ",n);
    tarsumstring(arr,idx+1,tar,asf,n);
}

void tarsumvector(int arr[],int idx,int tar,vector<int>& asf,int n){

    if(idx == n){
        if(tar ==0){
            for(int i=0;i<asf.size();i++){
                cout << asf[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    asf.push_back(arr[idx]);
    tarsumvector(arr,idx+1,tar-arr[idx],asf,n);
    asf.pop_back();
    tarsumvector(arr,idx+1,tar,asf,n);


}

void tarsumvectornegativecheck(int arr[],int idx,int tar,vector<int>& asf,int n){

    if(idx == n){
        
            for(int i=0;i<asf.size();i++){
                cout << asf[i] << " ";
            }
            cout << endl;
        
        return;
    }
    tarsumvectornegativecheck(arr,idx+1,tar,asf,n);
    asf.push_back(arr[idx]);
    tarsumvectornegativecheck(arr,idx+1,tar-arr[idx],asf,n);
  

}

void equiSets(int arr[],int n,int idx,string set1, int sos1,string set2,int sos2){
    if(idx == n){
        if(sos1 == sos2){
            
            cout << set1 << " ";
            cout << "----";
            cout << set2 << " ";
            cout << endl;
            
        }
        // if(sos1 == sos2){
        //     if(set1.compare(set2)<0){
        //     cout << set1 << " ";
        //     cout << "----";
        //     cout << set2 << " ";
        //     cout << endl;
        //     }
        // }
        return;
    }

    equiSets(arr,n,idx+1,set1+to_string(arr[idx]) + " ",sos1+arr[idx],set2,sos2);
    equiSets(arr,n,idx+1,set1,sos1,set2 + to_string(arr[idx]) + " ",sos2 + arr[idx]);

}

void equiSetsVector(int arr[],int n,int idx,vector<int> set1,int sos1,vector<int> set2,int sos2){

    if(idx == n){
        if(sos1 == sos2){
            for(int i=0;i<set1.size();i++){
                cout << set1[i] << " ";
            }
            cout << "----";
            for(int i=0;i<set2.size();i++){
                cout << set2[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    set1.push_back(arr[idx]);
    equiSetsVector(arr,n,idx+1,set1,sos1 + arr[idx],set2,sos2);
    set1.pop_back();

    set2.push_back(arr[idx]);
    equiSetsVector(arr,n,idx+1,set1,sos1,set2,sos2 + arr[idx]);
    set2.pop_back();
}

int main(int argc,char** argv){
    int arr[]={10,20,30,40,50,60,70};
    // vector<vector<int>> result=tss1(arr,0,50,5);
    // for(int i=0;i<result.size();i++){
    //     for(int j=0;j<result[i].size();j++){
    //         cout << result[i][j] + " ";
    //     }
    //     cout << endl;
    // }
    // tarsumstring(arr,0,50,"",5);
    // vector<int> asf;
    // tarsumvector(arr,0,50,asf,5);
    // tarsumvectornegativecheck(arr,0,30,asf,3);
    vector<int> set1;
    vector<int> set2;
    set1.push_back(arr[0]);
    // equiSets(arr,7,0,"",0,"",0);
    // equiSets(arr,7,1,to_string(arr[0]) + " ",arr[0],"",0);
    // equiSetsVector(arr,3,0,set1,0,set2,0);
    equiSetsVector(arr,7,1,set1,arr[0],set2,0);
}

