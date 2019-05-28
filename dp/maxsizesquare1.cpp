#include<iostream>
#include<vector>

using namespace std;

void maxSizeSquare(vector<vector<int>> arr){

    vector<vector<int>> strg(arr.size(), vector<int>(arr[0].size(),0));

    for(int i = arr.size()-1;i>=0;i--){
        for(int j=arr[0].size()-1;j>=0;j--){
            if(arr[i][j] == 0){
                strg[i][j] = 0;
            }
            else if(i == arr.size()-1 || j == arr.size()-1){
                strg[i][j] = arr[i][j];
            }
            else{
                strg[i][j] = min(strg[i+1][j+1], min(strg[i+1][j], strg[i][j+1]))+1;
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

    vector<vector<int>> arr{
        {0,1,1,0,0,1,0},
        {1,0,1,1,0,1,1},
        {1,1,1,1,0,1,0},
        {1,1,1,1,0,1,0},
        {0,1,1,1,1,1,0},
        {1,1,0,0,0,1,1}
    };

    maxSizeSquare(arr);
}