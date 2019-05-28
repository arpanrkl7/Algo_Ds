#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printss(string ques, string asf);
void printkpc(string ques, string asf);
void printStairs(int n,string asf);
void printMaze(int cr,int cc,int dr,int dc,string asf);
void printMazemm(int cr,int cc,int dr,int dc,string asf);
string arr[]={".;","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
main(int argc,char** argv){
    // string str = "abc";
    // // printss(str,"");
       printkpc("123","");
    // printStairs(7,"");
    // printMaze(0,0,2,2,"");
    // printMazemm(0,0,2,3,"");

    



}

void printss(string ques, string asf){

    if(ques.length() == 0){
        cout << asf << endl;
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);

    printss(roq, asf + ch);
    printss(roq, asf + "-");
}

void printkpc(string ques,string asf){

    if(ques.length()==0){
        cout << asf << endl;
        return;
    }

    string str=arr[ques[0]-'0'];
    for(int i=0;i<str.length();i++){
    printkpc(ques.substr(1),asf + str[i]);
    }
}

void printStairs(int n,string asf){
    
    if(n==0){
      cout << asf << endl;
      return;
    }
    if(n<0){
        return;
    }
    for(int i=1;i<=3;i++){
       printStairs(n-i,asf + to_string(i));
    }
}

void printMaze(int cr,int cc,int dr,int dc,string asf){
     
    if(cr == dr && cc == dc){
        cout << asf << endl;
        return;
    } 

    
        if(cc<dc){
        printMaze(cr,cc+1,dr,dc,asf + "H");
        }
        if(cr<dr){
        printMaze(cr+1,cc,dr,dc,asf + "V");
        }
    
}

void printMazemm(int cr,int cc,int dr,int dc,string asf){

    if(cr == dr && cc == dc){
        cout << asf << endl;
        return;
    }
    int i=1;
    while(i<=dr || i<=dc){
    if(cc+i<=dc){
        printMazemm(cr,cc+i,dr,dc,asf + "H" + to_string(i));
    }
    if(cr+i<=dr){
        printMazemm(cr+i,cc,dr,dc,asf + "V" + to_string(i));
    }
    if(cc+i<=dc && cr+i<=dr){
        printMazemm(cr+i,cc+i,dr,dc, asf + "D" + to_string(i));
    }
    i++;
}
}










