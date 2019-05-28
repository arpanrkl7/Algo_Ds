#include <iostream>
using namespace std;

main(int argc,char** argv){

    int arr[]={1,2,3,4,5,6};
    int arr1[]={1,2,3,4,5,6,7};

    int size1=sizeof(arr)/sizeof(int);
    int size2=sizeof(arr1)/sizeof(int);

    int newarr[size2];

    int size = sizeof(newarr)/sizeof(int);

    for(int i=0;i<size1;i++){
        newarr[i]=arr[i]+arr1[i];
       

    }
    for(int i=size2-1;i<size2;i++){
        newarr[i]=arr1[i];
    }

    for(int i=0;i<size;i++){
        cout << newarr[i] << " ";
    }
    cout << endl;

}