#include<iostream>
#include<vector>

using namespace std;

void cps(string s){

    vector<vector<int>> strg(s.size(), vector<int>(s.size(),0));

    for(int gap=0;gap<s.size();gap++){
        for(int i = 0,j = i+gap;j<s.size();j++,i++){
            if(i == j){
                strg[i][j] = 1;
            }
           else if(s[i] == s[j]){
               strg[i][j] = strg[i][j-1] + strg[i+1][j] + 1;
           }
           else{
               strg[i][j] = strg[i][j-1] + strg[i+1][j] - strg[i+1][j-1];
           }
        }
    }

    cout << strg[0][s.size()-1] << endl;
}

int main(int argc, char** argv){

    cps("acbkca");
}