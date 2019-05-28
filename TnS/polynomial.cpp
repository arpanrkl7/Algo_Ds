#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main(int argc,char** argv){

    int x=2;
    int n=3;
    int i=1;
    int ans =0;
    while(n>0){
        ans+= n*x*i;
        n--;
        i++;
    }
    cout << ans << endl;
}