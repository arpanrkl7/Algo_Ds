#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> gkpc(string str);
string arr[]={".;","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
int main(int argc,char** argv){


vector<string> result=gkpc("123");
for(int i=0;i<result.size();i++){
    cout << result[i] << endl;
}

}

vector<string> gkpc(string str){
    if(str.length()==0){
      vector<string> bres;
      bres.push_back("");
      return bres;
    }
    char ch=str[0];
    vector<string> rres=gkpc(str.substr(1));
    vector<string> mres;
    string chr=arr[ch-'0'];
    for(int i=0;i<rres.size();i++){
        for(int j=0;j<chr.size();j++){
            mres.push_back(chr[j] + rres[i]);
        }

    }
     return mres;



}