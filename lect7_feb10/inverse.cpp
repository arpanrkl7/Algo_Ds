#include <iostream>
using namespace std;

main(int argc,char** argv){

    int arr[]={4,2,0,1,3};
    int n=sizeof(arr)/sizeof(int);

    int inv[n];
    for(int i=0;i<n;i++){
        int val=arr[i];
        inv[val]=i;
    }
    for(int i=0;i<n;i++){
        cout << inv[i];
    }
}