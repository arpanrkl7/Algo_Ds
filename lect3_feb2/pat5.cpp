#include <iostream>
using namespace std;
//seen
main(int argc,char** argv){
    int n;
    cout << "Row ?" << endl;
    cin >> n;
    for(int r=1;r<=n;r++){
        
      for(int c=1;c<=n;c++){
          if(r==c || c==n+1-r){
              cout << "*";
          }
          else
          {
              cout << " ";
          }
          

            
        }
        cout << endl;
    }
}