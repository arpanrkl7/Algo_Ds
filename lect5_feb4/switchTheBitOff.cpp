#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int b;

    cin >> n >> b;
    int bm=1<<b;
    int nbm=~bm;
    

    if((n & bm) == 1){
        cout << "bit is on" << endl;
        n= (n & nbm);
        cout << n;
    }

    else
    {
        cout << "bit is off" << endl;
    }
    
    

}
