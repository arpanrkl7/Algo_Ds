#include<iostream>
using namespace std;

main(){
    int oc;
    cin >> oc;
    int rem=0;
    int pv=1;   //1000^0
    int res=0;

    while(oc!=0){
      rem=oc%10;
      oc=oc/10;
      
      
      switch(rem){
      case 0:{
      rem=0;
      break;
      }

      case 1:{
      rem=1;
      break;}

      case 2:{
      rem=10;
      break;}

      case 3:{
      rem=11;
      break;}

      case 4:{
      rem=100;
      break;}

      case 5:{
      rem=101;
      break;}

      case 6:{
      rem=110;
      break;}

      case 7:{
      rem=111;
      break;}

      }
     res+=rem*pv;
     pv=pv*1000;
    }
    cout << res;
}