#include <iostream>
using namespace std;

main(int argc,char** argv){
    int n;
    cout << "Row ?" << endl;
    cin >> n;
    for(int r=0;r<n;r++){
        int val=1;
        for(int c=0;c<=r;c++){
            cout << val << "\t";
            val=(val*(r-c))/(c+1);
        }
        cout << endl;
    }

   
}