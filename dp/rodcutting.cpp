#include<iostream>
#include<vector>

using namespace std;

void rc(vector<int> arr){

    vector<int> strg(arr.size(), 0);
    strg[1] = arr[1];
    for(int i = 2;i<arr.size();i++){
        int max1 =0;
        int j = 1;
        int k = i-1;
        while(j<=k){
            max1 = max(max1,strg[j]+strg[k]);
            j++;
            k--;
        }
        max1 = max(max1,arr[i]);
        strg[i] = max1;
    }

    for(int i=0;i<strg.size();i++){
        cout << strg[i] << " ";
    }
    cout << endl;
    cout << strg[arr.size()-1] << endl;
}

int main(int argc, char** argv){
    vector<int> arr{0,3,5,6,15,10,25,12,24};
    rc(arr);
}