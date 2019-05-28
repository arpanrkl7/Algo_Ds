#include <iostream>
using namespace std;

main(int argc,char** argv){

    int arr[]={2,3,0,1,4};
    int n=sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i++){
        int val=arr[i];
        if(arr[val]==i){
            if(i==n-1){
                cout << "mirror image" << endl;
                break;
            }
            continue;
            
        }
        else{
            cout << "Not Mirror image" << endl;
            break;
        }
    }
    
}