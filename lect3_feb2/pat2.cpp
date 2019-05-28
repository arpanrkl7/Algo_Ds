#include <iostream>
using namespace std;

main(int argc, char** argv){
    int n;
    cout << "row?" << endl;
    cin >> n;
    int val=1;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=r;c++){
            cout << val << "\t";
            val++;
        }
        cout << endl;
    }
}