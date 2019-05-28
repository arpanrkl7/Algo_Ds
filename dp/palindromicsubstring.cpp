#include<iostream>
#include<vector>

using namespace std;

void pss(string s){

    vector<vector<bool>> strg(s.size(), vector<bool>(s.size(),false));

    for(int gap =0;gap<s.size();gap++){
        for(int i =0,j = i+gap;j<s.size();i++,j++){

            if(gap == 0){
                strg[i][j] = true;
            }
            else if (gap == 1){
                strg[i][j] = s[i] == s[j];
            }
            else{
                if(s[i] != s[j]){
                    strg[i][j] = false;
                }
                else{
                    if(strg[i+1][j-1] == false){
                        strg[i][j] = false;
                    }
                    else{
                        strg[i][j] = true;

                    }
                }
            }
        }
    }
    int count =0;
    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            if(strg[i][j] == true){
                count++;
            }
        }
    }

    cout << count << endl;
}

int main(int argc, char** argv){

    pss("abccbc");
}