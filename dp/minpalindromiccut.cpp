#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void mpc(string s){

    vector<vector<int>> strg(s.size(),vector<int>(s.size(), 0));

    for(int gap=0;gap<s.size();gap++){
        for(int i =0,j = i+gap; j<s.size();i++,j++){
            
            if(gap == 0){
                strg[i][j] = 0;
            }
            else if(gap == 1){
                if(s[i] == s[j]){
                    strg[i][j] = 0;
                }
                else{
                    strg[i][j] = 1;
                }
            }
            else if(s[i] == s[j]){
                if(strg[i+1][j-1] == 0 ){
                    strg[i][j] = 0;
                }

                else{
                strg[i][j] = INT_MAX;
                for(int k =i; k<j;k++){
                    int l = i+1;
                    int temp = strg[i][k]+strg[l][j];
                strg[i][j] = min(strg[i][j],temp);
                l++;
            }
            strg[i][j]++;
            }
                
                
            }
            else{
                strg[i][j] = INT_MAX;
                for(int k =i; k<j;k++){
                    int l = i+1;
                    int temp = strg[i][k]+strg[l][j];
                strg[i][j] = min(strg[i][j],temp);
                l++;
            }
            strg[i][j]++;
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

void mpc1(string s){

    vector<vector<int>> strg(s.size(), vector<int>(s.size(), 0));

    for(int gap = 0; gap<s.size();gap++){
        for(int i = 0,j = i+gap;j<s.size();i++,j++){
            if(gap == 0){
                strg[i][j] = 0;
            }

            else if(gap == 1 && s[i] != s[j]){
                strg[i][j] = 1;
            }

            else if(s[i] == s[j]){
                if(strg[i+1][j-1] == 0){
                        strg[i][j] = 0;
                }

                else{
               
                strg[i][j] = INT_MAX;
                int lo = gap;
                int ro = 1;
                while(lo>=1 && ro<= gap){
                    int lhs = strg[i][j-lo];
                    int rhs = strg[i+ro][j];

                    strg[i][j] = min(strg[i][j], (lhs+rhs));
                    lo--;
                    ro++;
                }
                strg[i][j]++;
                

            }

                
            }
            else{
               
                strg[i][j] = INT_MAX;
                int lo = gap;
                int ro = 1;
                while(lo>=1 && ro<= gap){
                    int lhs = strg[i][j-lo];
                    int rhs = strg[i+ro][j];

                    strg[i][j] = min(strg[i][j], (lhs+rhs));
                    lo--;
                    ro++;
                }
                strg[i][j]++;
                

            }
        }
    }

    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv){

  //  mpc("abccbc");
    mpc1("abbaab");
}