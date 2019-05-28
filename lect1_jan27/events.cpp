#include<iostream>
using namespace std;

main(int argc,char** argv){
    int s1,e1,s2,e2;
    cout << "Pl. enter events";
    cin >> s1 >> e1 >> s2 >> e2;

    if(s2>=s1 && s2<=e1 && e2>=s1 && e2<=e1){
        cout << "e2 is in e1";
    }
    else if(s1>=s2 && s1<=e2 && e1<=e2 && e1>=s2){
        cout << "e1 is in e2";
    }
    else if ((s1>s2 && e1>e2) || (s2>s1 && e2>e1)){
        cout << "no overlap";
    }
    else {
        cout << "partially overlapping";
    }
}