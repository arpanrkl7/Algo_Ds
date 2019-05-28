#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int b;

    cin >> n >> b;

    int bm=1<<b;

    if((n & bm) == 0){
        cout << "bit is off" << endl;
        n= (n | bm);
        cout << n;
    }

    else
    {
        cout << "bit is on" << endl;
    }
    
    

}
