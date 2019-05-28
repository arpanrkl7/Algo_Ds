#include <iostream>
using namespace std;
//seen
main(int argc,char** argv){
    int n;
    cout << "Row ?" << endl;
    cin >> n;
    
    int stars=1;
    int spaces=n/2;
    int val=1;

    for(int r=1;r<=n;r++){

        int temp=val;
        for(int i=1;i<=spaces;i++){
            cout << " ";
        }

        for(int i=1;i<=stars;i++){
            cout << temp;

            if(i<=stars/2){
            temp++;
        }
        else
        {
            
            temp--;
        }
            

        }
            
        

        if(r<=n/2){
            stars+=2;
            spaces--;
            val++;
        }
        else
        {
            stars-=2;
            spaces++;
            val--;
        }

        cout << endl;
        
    }
}