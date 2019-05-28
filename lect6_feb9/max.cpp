#include <iostream>
#include <bits/stdc++.h>
using namespace std;

main(int argc,char** argv){

    int i;
    int arr[8]={40,50,70,90,2,33,-14,61};
    int max=INT_MIN;

    for(int i=0;i<8;i++){
        if(arr[i]>max){
            max=arr[i];
        }

    }
    cout << "maximum value is :" << max <<endl;
}