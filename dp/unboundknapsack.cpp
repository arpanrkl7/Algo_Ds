#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int> prices, vector<int> weight, int tw){

    vector<int> strg(tw+1, 0);

    for(int i=1;i<=tw;i++){
        for(int j=0;j<weight.size();j++){
            if(i - weight[j] < 0){
                continue;
            }
            else{
               strg[i] =  max(strg[i] , (strg[i - weight[j]] + prices[j]));
            }
        }
    }

    return strg[tw];
}

int main(int argc, char** argv){

    vector<int> prices{15,14,10,45,30};
    vector<int> weight{2,5,1,3,4};
    int tw = 7;
    cout << knapsack(prices,weight,tw) << endl;
}