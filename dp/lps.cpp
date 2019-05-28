#include<iostream>
#include<vector>

using namespace std;

void lps(string s){
    vector<vector<int>> strg(s.size(), vector<int>(s.size(),0));

    for(int gap=0;gap<s.size();gap++){
        for(int i = 0,j = i+gap;j<s.size();j++,i++){
            if(i == j){
                strg[i][j] = 1;
            }
            
            else if(s[i] == s[j]){
                strg[i][j] = strg[i+1][j-1] + 2;
            }
            else {
                strg[i][j] = max(strg[i][j-1], strg[i+1][j]);
            }
        }
    }

    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }
    cout << strg[0][s.size()-1] << endl;
}

int main(int argc, char** argv){

   // string s = "bddaghdab";
   // string s = "abckycbc";
   // string s = "GEEKSFORGEEKS";
    lps(s);
}