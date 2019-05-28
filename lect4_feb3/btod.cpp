#include <iostream>
using namespace std;

int main(int argc,char** argv){
    int dec = 0;
    int bin = 0;

    int rem;
    int res=0;
    int pv=1;  //2^0
    // cout << "no.?" << endl;
    cin >> bin;
    
    while(bin != 0){
        rem=bin%10;
        bin=bin/10;
        res+=rem*pv;
        pv=pv*2;
    }

    cout << res;
}