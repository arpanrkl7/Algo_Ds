#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void getcomelement(vector<int> one, vector<int> two){

    unordered_map<int, int> mp;
    for(int i=0; i<one.size(); i++){
        mp[one[i]] = 1;

    }

    for(int i=0; i<two.size(); i++){
        if(mp.count(two[i])==1){
            cout << two[i] << " ";
            mp.erase(two[i]);
        }
    }
    cout << endl;
}

void getcomelement2(vector<int> one, vector<int> two){

    unordered_map<int, int> mp;
    for(int i=0; i<one.size(); i++){
        if(mp.count(one[i]) == 0){
            mp[one[i]] = 1;
        }
        else{
            mp[one[i]]++;
        }
    }

    for(int i=0; i<two.size(); i++){
        if(mp.count(two[i]) == 1 && mp[two[i]]>0){
            cout << two[i] << " ";
            mp[two[i]]--;
        }
    }
}

int main(int argc, char** argv){

    vector<int> one{5,1,3,2,2,1,2};
    vector<int> two{1,4,1,2,2,1,5};

    getcomelement2(one, two);
}