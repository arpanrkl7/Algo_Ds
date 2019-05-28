#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc,char** argv){

    string s1="send";
    string s2="more";
    string s3="money";
    string qs="";

    bool uc[26];
    for(int i=0;i<s1.size();i++){
        if(uc[s1[i]-'a'] !=true){
        uc[s1[i]-'a']=true;
        qs+=s1[i];
        }
    }
    for(int i=0;i<s2.size();i++){
       if(uc[s2[i]-'a'] !=true){
        uc[s2[i]-'a']=true;
        qs+=s2[i];
        }
    }
    for(int i=0;i<s3.size();i++){
       if(uc[s3[i]-'a'] !=true){
        uc[s3[i]-'a']=true;
        qs+=s3[i];
        }
    }
    int map[26];
    bool dusf[10];

    crypto(s1,s2,s3,qs,map,dusf);



}

void crypto(string s1,string s2,string s3,string qs,int map[],bool dusf[]){

    char fc=qs[0];
    for(int i=0;i<10;i++){
        
        map[fc-'a']=i;
        crypto(s1,s2,s3,qs.substr(1),map);

    }
}