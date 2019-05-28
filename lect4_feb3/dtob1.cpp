#include<iostream>
using namespace std;

main(int argc,char** argv){
    int num=57;
    int pv=1;
    int result=0;

    while(num!=0){
        int rem=num%2;
        num=num/2;
        result+=rem*pv;
        pv=pv*10;
        

    }
    cout << result << endl;
}