#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permq(string q,string a){

    if(q.size()==0)
    {
        cout << a << " ";
        cout << endl;
    }

    
    
        for(int i=0;i<q.size();i++){
            char ans=q[i];
            string first=q.substr(0,i);
            string second=q.substr(i+1);
        permq(first+second,a + ans);

        }
    
}

void perma(string q, string a){
    if(q.size()==0)
    {
        cout << a << " ";
        cout << endl;
        return;
    }

   
    for(int i=0;i<a.size()+1;i++){

        char ans=q[0];
        string left=a.substr(0,i);
        string right=a.substr(i);
        perma(q.substr(1),left+ans+right);
    }
}

void permquesd(string q, string a){

    if(q.size()==0)
    {
        cout << a << endl;
        return;
    }

    int bm=0;
    for(int i=0;i<q.size();i++){
        char ch = q[i];
        string left=q.substr(0,i);
        string right=q.substr(i+1);
        if((bm & (1 << (ch-97))) == 0){
            bm = bm | (1 << (ch-97));
            permquesd(left+right,a + ch);

        }
              

    }
}

int main(int argc,char** argv){

    // permq("abc","");
    // perma("abc","");
        permquesd("baba","");


}