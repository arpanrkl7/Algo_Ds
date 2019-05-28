#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[]={10,20,20,20,30,30,30,40,50,50};
    int n;
    cin >> n;

    int low=0;
    int high=7;
    int ans=-1;

    while(low+1!=high){
        int mid=(low+high)/2;
        if(n>arr[mid]){
            low=mid+1;
        }
        else if(n<arr[mid]){
            high=mid-1;
        }
        else if(n==arr[mid]){
             ans=mid;
             low=mid;
        }
    }

    cout << ans;



}