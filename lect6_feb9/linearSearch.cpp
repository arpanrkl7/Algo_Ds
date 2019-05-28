#include <iostream>
using namespace std;

main(int argc,char** argv){

    int i;
    int arr[8]={40,50,70,90,2,33,-14,61};
    int j=0;
    cin >> j;
    int x=0;

    for(int i=0;i<8;i++){
        if(arr[i] == j){
            cout << "no found" << endl;
            x=1;
        }

    }
    if(x==0)
    cout << "no. not found" << endl;
}