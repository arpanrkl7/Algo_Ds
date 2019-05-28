#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

void lces(vector<int> arr){

    unordered_map<int, bool> mp;
    for(int i=0; i<arr.size(); i++){
        mp[arr[i]] = true;
    }

    for(int i=0; i<arr.size(); i++){
        if(mp.count(arr[i] - 1) > 0){
            mp[arr[i]] = false;
        }

    }
    int ga = 0;
    int gb = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(mp[arr[i]] == true){
            int a = arr[i];
            int b = 0;

            while(mp.count(a+b) > 0){
                b++;
            }

            if(b > gb){
                gb = b;
                ga = a;
                
            }
        }
    }

    cout << ga << "@" << gb << endl;
}

int main(int argc, char** argv){
    vector<int> arr{2,12,9,16,10,5,3,20,25,11,1,8,6};
    lces(arr);

}