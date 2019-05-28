#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> getStairsPath(int n);
int main(int argc,char** argv){

    vector<string> result=getStairsPath(7);
    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }
    cout << result.size();

}

vector<string> getStairsPath(int n){
          vector<string> bres;

    if(n == 0){
      bres.push_back("");
      return bres;
    }
    if(n<0){
        return bres;
    }
   

    vector<string> path1=getStairsPath(n-1);
    vector<string> path2=getStairsPath(n-2);
    vector<string> path3=getStairsPath(n-3);

    vector<string> mres;
    for(int i=0;i<path1.size();i++){
        mres.push_back("1" + path1[i]);
    }
    for(int i=0;i<path2.size();i++){
        mres.push_back("2" + path2[i]);
    }
    for(int i=0;i<path3.size();i++){
        mres.push_back("3" + path3[i]);
    }

    return mres;


   

}