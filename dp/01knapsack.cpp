#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int> prices, vector<int> weight,int tw){

    vector<vector<int>> strg(weight.size()+1, vector<int>(tw+1, 0));

    for(int i=0;i<=weight.size();i++){
        for(int j=0;j<=tw;j++){
            if(i == 0 || j == 0){
                strg[i][j] = 0;
            }

            else{
                if(j-weight[i-1]<0){
                    strg[i][j] = strg[i-1][j];
                }
                else{
                    strg[i][j] = max(strg[i-1][j], (prices[i-1] + strg[i-1][j-weight[i-1]]));
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

    return strg[weight.size()][tw];
}

int main(int argc, char** argv){

    vector<int> prices{15,14,10,45,30};
    vector<int> weight{2,5,1,3,4};
    int tw = 7;
    cout << knapsack(prices,weight,tw) << endl;
}