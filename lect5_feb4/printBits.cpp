#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;

    cin >> n;

    for(int i = 31; i >=0; i--)
    {
        int bm = 1<<i;
        cout << ((n & bm) ==0 ? 0:1);
    }
    
    
}

