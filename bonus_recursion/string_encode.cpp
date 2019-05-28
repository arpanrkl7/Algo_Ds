#include<iostream>
#include<string>
#include<vector>
using namespace std;

void str_encode(string q,string a,char arr[]){
    if(q.size() == 0){
        cout << a << endl;
    }
    char char1=q.substr(0,1);
    int ans1=char1 - '0';
    int ans2=stoi(q.substr(0,2));
    if(ans1<=26){
        str_encode(q.substr(1),a + arr[ans1-1],arr);
    }
    if(ans2 <= 26){
        str_encode(q.substr(2), a + arr[ans2 - 1],arr);
    }
    
}
vector<string> words{"man","go","mango","ice","cream","icecream","loves"};
string str="mangolovesicecream";
vector<vector<string>> getAllSentences(words,str){


}



int main(int argc,char** argv){

char arr[]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
// str_encode("1123","",arr);
}

