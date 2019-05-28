#include<iostream>
#include<vector>

using namespace std;

void lbs(vector<int> arr){
    int max1 =0;

    vector<int> lis(arr.size(),0);
    for(int i=0;i<arr.size();i++){
        lis[i] = 1;
        for(int j=0; j<i;j++){
            if(arr[j] < arr[i]){
                if(lis[j] + 1 > lis[i]){
                    lis[i] = lis[j]+1;
                }
            }
        }
    }

    vector<int> lbs(arr.size(),1);
    for(int i=arr.size()-2;i>=0;i--){

        for(int j =arr.size()-1;j>i;j--){
            if(arr[j] < arr[i]){
                if(lbs[j] + 1 > lbs[i]){
                    lbs[i] = lbs[j] + 1;
                }
            }
        }
        if(lis[i] + lbs[i] -1 > max1){
            max1 = lis[i] + lbs[i] -1;
        }
    }

    cout << max1 << endl;

    for(int i=0;i<lis.size();i++){
        cout << lis[i] << " ";
    }
    cout << endl;
    for(int i =0;i<lbs.size();i++){
        cout << lbs[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv){

    vector<int> arr{10,22,9,33,21,50,41,60,80,1};
    lbs(arr);
}