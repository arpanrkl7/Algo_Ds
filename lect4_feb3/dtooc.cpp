#include <iostream>
using namespace std;

int main(int argc,char** argv){
    int dec = 0;
    int bin = 0;

    int rem;
    int res=0;
    int pv=1;
    // cout << "no.?" << endl;
    cin >> dec;
    
    while(dec != 0){
        rem=dec%8;
        dec=dec/8;
        res+=rem*pv;
        pv=pv*10;
    }

    cout << res;
}