#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> printPath(int rs,int cs,int re,int ce);
int main(int argc,char** argv){

    vector<string> path=printPath(0,0,2,2);
    for(int i=0;i<path.size();i++){
        cout << path[i] << endl;
    }
    cout << path.size();

}

vector<string> printPath(int rs,int cs,int re,int ce){
    
    if(rs == re && cs==ce){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    vector<string> mres;
    

    for(int i=1;i<=ce-cs;i++){
    vector<string> hPath=printPath(rs,cs+i,re,ce);
    for(int j=0;j<hPath.size();j++){
        mres.push_back("H" + to_string(i) + hPath[j]);
    }
    }

    for(int i=1;i<=re-rs;i++){
    vector<string> vPath=printPath(rs+i,cs,re,ce);
    for(int j=0;j<vPath.size();j++){
        mres.push_back("V" + to_string(i) + vPath[j]);
    }
    }

    for(int i=1;i<=ce-cs && i<= re-rs;i++){
    vector<string> dPath=printPath(rs+i,cs+i,re,ce);
    for(int j=0;j<dPath.size();j++){
        mres.push_back("D" + to_string(i) + dPath[j]);
    }
    }


    
    

    return mres;

    

}