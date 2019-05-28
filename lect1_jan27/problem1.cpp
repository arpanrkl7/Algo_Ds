#include<iostream>
using namespace std;

main(int argc,char** argv){

    int n,r;
    cout << "Please enter a number";
    cin >> n;
    cout << "Please enter Rotation";
    cin >> r;
    int temp=n;
    int count=0;
    while(n!=0){
        n=n/10;
        count++;
    }
    
    if(r>count){
        r=r%count;
    }
    if(r<0){
        r=r%count+count;
    }
    
    n=temp;
    int d=1;
    int m=1;

    for(int i=0;i<count;i++){
        if(i<r){
            d=d*10;
        }
        else
        m=m*10;

    }

    int val1=n%d;
    int val2=n/d;

    int result=val1*m + val2;
    cout << result;

}