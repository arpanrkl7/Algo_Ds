#include <iostream>
using namespace std;

main(int argc,char** argv){

int n;
    cout << "row?" << endl;
    cin >> n;
    int val1=1;
    int val2=1;
    int res;
        for(int r=0;r<n;r++){
        for(int c=0;c<=r;c++){
            if(r ==0 || r==1){
                cout << r << "\t";
            }
            else{
                 res=val1+val2;
                 cout << res << "\t";
                 val1=val2;
                 val2=res;
            }
            
        }
        cout << endl;
    }



}