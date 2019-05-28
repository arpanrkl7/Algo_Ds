#include <iostream>
using namespace std;

main(int argc,char** argv){
    int arr[]={1,2,3,4,6,4,3,2,1};
    int n=sizeof(arr)/sizeof(int);
    int uninue=0;
    for(int i=0;i<n;i++){
        uninue=uninue^arr[i];

    }

    cout << uninue << endl;
}