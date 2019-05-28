#include <iostream>
using namespace std;

main(int argc,char** argv){

    int arr[]={-2,11,-4,13,-5,2};

    int loc_sum=0;
    int loc_str=0;
    int loc_end=0;
    int glob_sum=0;
    int glob_str=0;
    int glob_end=0;


    int n=sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i++){

        if(loc_sum+arr[i]>arr[i]){
            loc_sum=loc_sum+arr[i];
            loc_end=i;
        }
        else{
            loc_sum=arr[i];
            loc_str=i;
            loc_end=i;
        }
        if(glob_sum<loc_sum){
            glob_sum=loc_sum;
            glob_str=loc_str;
            glob_end=loc_end;
        }
    }

    cout << "max_sum is:" << glob_sum << endl;
    for(int i=glob_str;i<=glob_end;i++){
        cout << arr[i] << " ";
    }
    cout << endl;


        
}