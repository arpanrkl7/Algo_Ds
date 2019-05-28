#include<iostream>
#include<vector>

using namespace std;

void tarSubsetPrint(vector<vector<int>>& newarr, int r, int j, string asf){

    int newcol = 
    tarSubsetPrint(newarr,r-1,j,asf);
    tarSubsetPrint(newarr,r-1,)
}

int targetSubset(vector<int>& arr, int sum){

    vector<vector<int>> newarr(sum+1, vector<int>(sum+1, 0));

    for(int i=0;i<=sum;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0 && j==0){
                newarr[i][j] = 1;
            }

            else if(i == 0){
                newarr[i][j] = 0;
            }

            else if(j == 0){
                newarr[i][j] = 1;
            }

            else{
                if(j-arr[i-1] < 0){
                    newarr[i][j] = newarr[i-1][j];
                }
                else{
                    newarr[i][j] = newarr[i-1][j] + newarr[i-1][j-arr[i-1]];
                }
            }
        }
    }

    tarSubsetPrint(newarr,sum,sum,"");
    return newarr[sum][sum];
}

int main(int argc, char** argv){

    vector<int> arr{5,2,1,4,3,7,6};
    int sum = 7;
    cout << targetSubset(arr,sum) << endl;
}