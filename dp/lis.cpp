#include<iostream>
#include<vector>

using namespace std;

void lis(vector<int> arr){

    vector<int> strg(arr.size()+1,0);
    vector<int> pos(arr.size()+1,0);

    for(int i=0;i<=arr.size();i++){
        if(i == 0){
            strg[i] = 1;
            pos[i] = 0;
        }

        else{
            if(arr[i] > pos[i-1]){
                strg[i] = strg[i-1]  + 1;
                pos[i] = i;
            }

            else{
                strg[i] = strg[i-1];
                pos[i] = pos[i-1];

            }
        }
    }

    cout << strg[arr.size()] << endl;
}

void lis2(vector<int> arr){

    vector<int> strg(arr.size(),0);
    for(int i=0;i<arr.size();i++){
        strg[i] = 1;
        for(int j=0; j<i;j++){
            if(arr[j] < arr[i]){
                if(strg[j] + 1 > strg[i]){
                    strg[i] = strg[j]+1;
                }
            }
        }
    }
    int max1 = 0;
    for(int i=0;i<strg.size();i++){
        max1 = max(max1,strg[i]);
        cout << strg[i] << " ";
    }
    cout << endl;
    cout << max1 << endl;
}

int main(int argc, char** argv){

    vector<int> arr{10,22,9,33,21,50,41,60,80,1};
    lis2(arr);
}