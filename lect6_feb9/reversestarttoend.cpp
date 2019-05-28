#include<iostream>
#include<bits/stdc++.h>

using namespace std;

main(int arg,char** argv){

    int arr[] = {2,5,7,9,1,3};
    int n = sizeof(arr) / sizeof(int);

    int start=1;
    int end=4;

    while(start<=end){
        int temp=arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }
    

}