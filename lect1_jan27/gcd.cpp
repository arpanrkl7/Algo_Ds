#include<iostream>
using namespace std;

int main(int argc,char** argv){
    int n1,n2;
    cout << "Please enter first no.";
    cin >> n1;
    cout << "Please enter second no.";
    cin >> n2;
    int val1=n1;
    int val2=n2;
    int r=1;
    while(r != 0){
        r=val1%val2;

         val1=val2;       
        val2=r;


    }
    cout << val1;
}