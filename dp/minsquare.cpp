#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int cms(int l, int b, vector<vector<int>>& strg){
    
    if(l == 0 || b==0){
        return 0;
    }
    else if(l == b){
        return 1;
    }

    if(strg[b][l] != 0){
        return strg[b][l];
    }

    int sd = min(l,b);
    int res = INT_MAX;

    for(int i =1; i<=sd;i++){
    
    int c1 = cms(l-i,i,strg) + cms(l,b-i,strg)+1;
    int c2 = cms(l-i,b,strg) + cms(i,b-i,strg)+1;

    res = min(res, min(c1,c2));

    }
    strg[b][l] = res;

    return res;
}


int main(int argc, char** argv){

    int h = 36;
    int v = 30;
    vector<vector<int>> strg(v+1, vector<int> (h+1,0));
    cout << cms(h,v,strg) << endl;
}