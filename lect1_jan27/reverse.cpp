#include<iostream>
using namespace std;

main(int argc,char** argv){
    int n;
    cin >> n;
    int val1=10;
    int val2=n;
    while(val2%val1!=0){
        cout << val2%val1;
        val2=val2/10;
    }
}