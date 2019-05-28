#include<iostream>
#include<vector>
#include<string>
using namespace std;

void permq(string q,string a){

    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    for(int i=0;i<q.size();i++){
        char ch=q[i];
        string left=q.substr(0,i);
        string right=q.substr(i+1);
        permq(left+right,a+ch);
    }
}

void perma(string q, string a){

    if(q.size() == 0){
        cout << a << endl;
        return;
    }

    char ch=q[0];
    string ros=q.substr(1);
    for(int i=0;i<a.length()+1;i++){
        string left = a.substr(0,i);
        string right = a.substr(i);
        perma(ros, left+ch+right);
    }
}



void permqd(string q, string a){

    if(q.size() == 0){
        cout << a << endl;
        return;
    }


    int bm =0;
    for(int i=0;i<q.size();i++){

        char ch=q[i];
        string left = q.substr(0,i);
        string right = q.substr(i+1);

        if((bm & (1<< (ch-97))) == 0){
            bm = bm | (1<< (ch-97));
            permqd(left+right,a+ch);
        }
    }
}

int main(int argc,char** argv){
    // permq("abc","");
    //  perma("baba","");
    permqd("baba","");


}