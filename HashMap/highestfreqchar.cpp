#include<iostream>
#include<unordered_map>

using namespace std;

char hfc(string word){
    unordered_map<char, int> mp;
    for(int i=0; i<word.size(); i++){
        if(mp.count(word[i]) == 0){
            mp[word[i]] = 1;
        }
        else{
            mp[word[i]]++;
        }
    }
    char res;
    int mymax = 0;
    for(auto i = mp.begin(); i!=mp.end(); i++){
        if(i->second > mymax){
            mymax = i->second;
            res = i->first;
        }
    }
  //  cout << res << endl;
    return res;
}

int main(int argc, char** argv){
    string word = "abcabbbbcaa";
    cout << hfc(word) << endl;
}