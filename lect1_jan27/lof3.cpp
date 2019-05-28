#include<iostream>
using namespace std;

main(int argc,char** argv){
    int a=10;
    int b=20;
    int c=30;

    if(a>=b && a>=c){
        cout << "a = " << a << "is Largest" << endl;
    }
    else{
        if(b >= c){
            cout << "b =" << b << "is Largest" << endl;
        }
        else
        {
            cout << "c =" << c << "is Largest" << endl;
        }
    }
}