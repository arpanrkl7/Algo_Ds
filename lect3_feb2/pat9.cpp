#include <iostream>
using namespace std;
//seen
main(int argc,char** argv){
    int n;
    cout << "Row ?" << endl;
    cin >> n;
    
    int stars=1;
    int spaces=(2*n)-3;;

    for(int r=0;r<n;r++){

        int temp=1;

        for(int i=1;i<=stars;i++){
            cout << temp;
            temp++;
        }

        for(int i=1;i<=spaces;i++){
            cout << " ";
        }

        for(int i=1;i<=stars;i++){
            cout << temp;
            temp--;
        }

        
        
            spaces-=2;
            stars++;
        

        cout << endl;
        
    }
}