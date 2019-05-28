#include <iostream>
using namespace std;

main(int argc, char** argv){

    int num1,num2;
    
    int res=0;
    int pv_old=1;

    cin >> num1 >> num2;
    int restore=num1;

    while(num2!=0){
        int rem2=num2%10;
        num2=num2/10;
        int pv=1;
        int c=0;
        int res1=0;
        while(num1!=0 || c!=0){
            int rem1=num1%10;
            num1=num1/10;
            res1+=(((rem1*rem2)+c)%8)*pv;
            pv=pv*10;
            c=((rem1*rem2)+c)/8;



        }
        num1=restore;
        res+=(res1*pv_old);
        pv_old=pv_old*10;

    }

    cout << res;



}