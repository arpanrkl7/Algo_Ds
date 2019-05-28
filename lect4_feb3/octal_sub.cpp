#include<iostream>
using namespace std;

main(int argc,char** argv){

    int num1,num2;
    int res=0;
    int c=0;
    int pv=1;  //10 ^ 1
    
    cin >> num1 >> num2;

    while(num1 !=0){
        int rem1=num1%10;
        num1=num1/10;
        int rem2=num2%10;
        num2=num2/10;
        
        if(rem1+c<rem2){
            res+=((rem1+c+8)-rem2)*pv;
            c=-1;
            pv=pv*10;
            


        }
        else
        {
            res+=((rem1+c)-rem2)*pv;
            pv=pv*10;
            c=0;
        }
        

    }
    
     cout << res;

   
}