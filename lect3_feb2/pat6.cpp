#include <iostream>
using namespace std;
//seen
main(int argc,char** argv){
    int n;
    cout << "Row ?" << endl;
    cin >> n;
    
    int stars=1;
    int spaces=n/2;

    for(int r=1;r<=n;r++){

        for(int i=1;i<=spaces;i++){
            cout << " ";
        }

        for(int i=1;i<=stars;i++){
            cout << "*";
        }

        if(r<=n/2){
            stars+=2;
            spaces--;
        }
        else
        {
            stars-=2;
            spaces++;
        }

        cout << endl;
        
    }
}