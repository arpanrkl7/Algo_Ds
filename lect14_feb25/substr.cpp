#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> getss(string str,int ep);
main(int argc,char** argv){
    string str = "abc";
    vector<string> res = getss(str,str.size()-1);

    for(int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }



}

vector<string> getss(string str,int ep){
    if(ep == -1){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    char ch = str[ep];
    vector<string> rres=getss(str,ep-1);
    vector<string> mres;
    
    for(int i=0;i<rres.size();i++){
        mres.push_back(rres[i] + "_");
        mres.push_back(rres[i] + ch);
    }

    return mres;





}