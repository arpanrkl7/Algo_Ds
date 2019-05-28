#include<iostream>
#include<vector>

using namespace std;

void zo(int n){
    vector<int> zero(n+1, 0);
    vector<int> one(n+1, 0);

    zero[0] = one[0] = 0;
    zero[1] = one[1] = 1;
    zero[2] = 1;
    one[2] = 2;

    for(int i=3;i<=n;i++){
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }

    cout << zero[n] + one[n] << endl;

}

int zeroone(int n){

    int a = 1;
    int b = 1;

    for(int i=2; i<=n; i++){
        int na = b;
        int nb = a+b;
        a = na;
        b = nb;
    }

    cout << a+b << endl;
}

int main(int argc, char** argv){
    int n = 5;
    zo(n);
   zeroone(5);
}