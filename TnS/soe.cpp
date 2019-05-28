#include<iostream>
#include<vector>

using namespace std;

int main(int argc,char** argv){

    int n=100;

    vector<bool> primes(n+1,true);
    primes[0] = primes[1] = false;

    for(int i = 2;i*i<=n;i++){

        if(primes[i] == true){
            for(int j=i;i*j<=n;j++){
                primes[j*i] = false;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(primes[i] == true){
            cout << i << " ";
        }

    }
    cout << endl;
}