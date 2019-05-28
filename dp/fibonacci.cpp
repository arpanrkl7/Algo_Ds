#include<iostream>
#include<string>
#include<vector>

using namespace std;

int fib(int n){

    if(n==0 || n==1){
        return n;
    }

    int res = fib(n-1) + fib(n-2);
  //  cout << "hello" << n << res << endl;

    return res;
}

int fibmemo(int n, vector<int>& qb){
    if(n == 0 || n==1){
        return n;
    }

    if(qb[n] != 0){
        return qb[n];
    }

    int res = fibmemo(n-1, qb) + fibmemo(n-2, qb);
    cout << "hello" << n << "  " << res << endl;
    qb[n] = res;
    return res;
}

int fibtabulation(int n){

    vector<int> strg(n+1, 0);
    strg[0] = 1;
    strg[1] = 1;
    for(int i=2;i<=n;i++){
        strg[i] = strg[i-1] + strg[i-2];
    }
    for(int i=0;i<strg.size();i++){
        cout << strg[i] << " ";
    }
    return strg[n-1];
}

int main(int argc,char** argv){

    vector<int> qb(44,0);
    cout << fibmemo(43, qb) << endl;

//    cout << fib(50) << endl;

 //  cout << fibtabulation(6) << endl;


}