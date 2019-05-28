#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void mcp(vector<int> arr){

    vector<vector<int>> strg(arr.size()-1, vector<int>(arr.size()-1, 0));

    for(int gap=0; gap<strg.size(); gap++){
        for(int i=0,j=i+gap; j<strg.size(); i++,j++){

            if(gap == 0){
                strg[i][j] = 0;
            }

            else if(gap == 1){
                strg[i][j] = arr[i] * arr[j] * arr[j+1];
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
                strg[i][j]+= arr[i]*arr[j]*arr[j+1];
                

            

            }
        }
    }
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-1;j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }
    cout << strg[0][arr.size()-2] << endl;
}

int main(int argc, char** argv){
    vector<int> arr{10,20,30,40,50,60};
    mcp(arr);
}