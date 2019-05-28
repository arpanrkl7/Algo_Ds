#include<iostream>
using namespace std;

main(int argc,char** argv){
     int n;
     int i=2;
     cout << "Please enter a no. \n";
     cin >> n;
     while(i * i < n){
         if(n%i==0){
             cout << n << " is not a prime no. \n";
             return 0;
         }
         i++;
     }
     cout << n << " is a prime no. \n";
}