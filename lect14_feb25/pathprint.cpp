#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> printPath(int rs,int cs,int re,int ce);
int main(int argc,char** argv){

    vector<string> path=printPath(0,0,2,3);
    for(int i=0;i<path.size();i++){
        cout << path[i] << endl;
    }

}

vector<string> printPath(int rs,int cs,int re,int ce){

    if(rs == re && cs==ce){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    vector<string> hPath;
    vector<string> vPath;
    if(cs<ce){
    hPath=printPath(rs,cs+1,re,ce);
    }
    if(rs<re){
    vPath=printPath(rs+1,cs,re,ce);
    }
    vector<string> mres;
    for(int i=0;i<vPath.size();i++){
        mres.push_back("V" + vPath[i]);
    }
    for(int i=0;i<hPath.size();i++){
        mres.push_back("H" + hPath[i]);
    }
    
    return mres;    

}