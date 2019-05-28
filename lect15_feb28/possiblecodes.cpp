#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> possiblecodes(string str);
string arr[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
main(int argc,char** argv){
    vector<string> result= possiblecodes("1123");
    for(int i=0;i<result.size();i++){

        cout << result[i] << endl;
    }

}

vector<string> possiblecodes(string str){
    if(str.length()==0){
      vector<string> bres;
      bres.push_back("");
      return bres;
    }

    char ch1=str[0];
    char ch2=str[1];
    vector<string> rres=possiblecodes(str.substr(1));
    vector<string> mres;
    string firstChar=arr[(ch1 - '0')-1];
    string secondChar=(ch1-'0')*10 + (ch2 - '0') -1

    for(int i=0;i<rres.size();i++){
            mres.push_back(firstChar + rres[i]);
    }

    return mres;
}
