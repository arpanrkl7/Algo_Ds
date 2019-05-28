#include <iostream>
using namespace std;

void swap(int arr[],int i,int j);

main(int argc,char** argv){
    int arr[]={44,22,77,11,99};
    int n=sizeof(arr)/sizeof(int);

    for(int i=0;i<=n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
            swap(arr,j,j+1);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    
  

}

void swap(int arr[],int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
