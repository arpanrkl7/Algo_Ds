#include<iostream>
#include<string>
#include<vector>

using namespace std;

int coinChangePerm(vector<int>& arr, int sum){

    vector<int> newarr(sum+1,0);
    newarr[0] = 1;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<arr.size();j++){
            if(i-arr[j] >=0){
                newarr[i]+= newarr[i-arr[j]];
            }
        }
    }
    return newarr[sum];
}

int coinChangeCombb(vector<int>& arr, int sum){

    vector<int> newarr(sum+1,0);
    newarr[0] = 1;
    for(int j=0;j<arr.size();j++){
    for(int i=1;i<=sum;i++){
        
            if(i-arr[j] >=0){
                newarr[i]+= newarr[i-arr[j]];
            }
        }
    }
    return newarr[sum];
}

int main(int argc,char** argv){

    vector<int> arr{2,3,5};
    int sum = 7;
    cout << coinChangePerm(arr,sum) << endl;
    cout << coinChangeCombb(arr,sum) << endl;
}