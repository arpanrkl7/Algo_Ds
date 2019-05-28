#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int arr[]={1,2,3,4,5,6,7,8};
    int n;
    cin >> n;

    int low=0;
    int high=7;

    while(low+1!=high){
        int mid=(low+high)/2;
        if(n>mid){
            low=mid+1;
        }
        else if(n<mid){
            high=mid-1;
        }
        else if(n==mid){
            cout << "no. found" << endl;
            return 1;
        }
    }

    return -1;



}