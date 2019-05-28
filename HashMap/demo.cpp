#include<iostream>
#include<unordered_map>

using namespace std;

int main(int argc, char** argv){

    unordered_map<string,int> mp;
    mp["a"] = 10;
    mp["b"] = 20;
    mp["c"] = 30;
    cout << mp["a"] << mp["b"] << mp["c"] << endl;
    mp["b"] = 50;
    cout << mp["a"] << mp["b"] << mp["c"] << endl;

    if(mp.find("b") != mp.end()){
        auto a = mp.find("b");
        cout << a->first << " " << a->second << endl;
    }
  //  cout << mp.find("b") << endl;

    cout << mp.count("a") << endl;

    if(mp.count("z") == 0){
        mp["z"];
        cout << mp["z"] << endl;
    }

    mp.erase("a");
    cout << mp.count("a") << endl;
}