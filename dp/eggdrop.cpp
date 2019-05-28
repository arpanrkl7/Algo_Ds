#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void eggdropPath(vector<vector<int>>& strg, int i, int j, int egg, string asf){

    if(egg == 1){
        cout << asf << " ";
        for(int i=1; i<=j;i++){
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for(int k=1;k<=j;k++){
        int search = strg[i][j] -1;
        if(max(strg[i-1][k - 1],strg[i][j-k]) == search){
            eggdropPath(strg, i-1, k, egg-1, asf);
            eggdropPath(strg, i, j-k-1, egg, asf + to_string(search+1) + " ");
        }
    }


}

void eggdp(int egg, int floor){

    vector<vector<int>> strg(egg+1, vector<int>(floor+1, 0));

    for(int i=0;i<egg+1;i++){
        for(int j=0;j<floor+1;j++){
            if(i == 0 || j==0){
                strg[i][j] = 0;
            }

            else if(i == 1){
                strg[i][j] = j;
            }

            else{
                strg[i][j] = INT_MAX;
                for(int k=0;k<j;k++){
                    strg[i][j] = min(strg[i][j], max(strg[i-1][k], strg[i][j-k-1])+1);
                }
            }

        }
    }

    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }
    cout << strg[egg][floor] << endl;

    eggdropPath(strg, egg, floor, 2, "");
}



int main(int argc, char** argv){

    eggdp(2,10);
}