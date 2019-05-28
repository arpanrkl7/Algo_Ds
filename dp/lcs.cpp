#include<iostream>
#include<vector>
#include<string>

using namespace std;

void lcsPrint(vector<vector<int>>& strg,int i, int j,string s1, string s2, string asf){

    if(i==s1.size() || j==s2.size()){
        cout << asf << endl;
        return;
    }

    
    if(s1[i] == s2[j]){
        lcsPrint(strg, i+1, j+1, s1, s2, asf+s1[i]);
    }
    else{
        if(strg[i][j+1] > strg[i+1][j]){
            lcsPrint(strg, i, j+1, s1,s2,asf);
        }
        else if(strg[i][j+1] < strg[i+1][j]){
            lcsPrint(strg, i+1, j, s1, s2, asf);
        }
        else{
            lcsPrint(strg, i, j+1, s1,s2,asf);
            //lcsPrint(strg, i+1, j, s1, s2, asf);
        }
    }

}

void lcs(string s1, string s2){

    vector<vector<int>> strg(s1.size()+1, vector<int>(s2.size()+1,0));

    for(int i = s1.size();i>=0;i--){
        for(int j=s2.size();j>=0;j--){

            if(i == s1.size()){
                strg[i][j] = 0;
            }

            else if(j == s2.size()){
                strg[i][j] = 0;
            }

            else{
                if(s1[i] == s2[j]){
                    strg[i][j] = strg[i+1][j+1]+1;
                }
                else{
                    strg[i][j] = max(strg[i][j+1], strg[i+1][j]);
                }
            }
        }
    }
    lcsPrint(strg,0,0,s1,s2,"");

    cout << strg[0][0] << endl;
}

int main(int argc, char** argv){

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    lcs(s1,s2);
}