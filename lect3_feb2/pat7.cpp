#include <iostream>
using namespace std;
//seen
main(int argc,char** argv){
    int n;
    cout << "Row ?" << endl;
    cin >> n;
    
    int stars=n/2+1;
    int spaces=1;

    for(int r=1;r<=n;r++){

        

        for(int i=1;i<=stars;i++){
            cout << "*";
        }

        for(int i=1;i<=spaces;i++){
            cout << " ";
        }

        for(int i=1;i<=stars;i++){
            cout << "*";
        }

        if(r<=n/2){
            spaces+=2;
            stars--;
        }
        else
        {
            spaces-=2;
            stars++;
        }

        cout << endl;
        
    }
}