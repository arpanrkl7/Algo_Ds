#include<iostream>
#include<vector>

using namespace std;

void countSubsets(vector<int> arr){

    vector<int> inc(arr.size(), 0);
    vector<int> exc(arr.size(), 0);

    for(int i=0;i<arr.size();i++){

        if(i ==0){
            inc[i] = arr[i];
            exc[i] = 0;
        }

        else{
            inc[i] = exc[i-1] + arr[i];
            exc[i] = inc[i-1]; 
        }
    }

    cout << inc[arr.size()-1] << endl;
}

int main(int argc, char** argv){

    vector<int> arr{5,6,10,100,10,5};
    countSubsets(arr);
}