#include<iostream>
#include<cmath>
using namespace std;

void find1(int sum , int opsf,int option,int po);
int powerSum(int X, int N);
static int count1 = 0;

int main(int argc,char** argv){
    int ans = powerSum(800,2);
    cout << ans << endl;

}


int powerSum(int X, int N) {
    int no = X;
    int po = N;
    int op = pow(no,1.0/po);
   // cout << op << endl;
    find1(no,1,op,po);

    return count1;

}
void find1(int sum ,int opsf,int to,int po){

    if(sum == 0){

        //cout << "a";
        count1++;
        return;
    }


     if(opsf > to){
        return;
    }
    if(sum<0){
        return;
    }
    
    
   

    for(int i=opsf;i<=to;i++){
        int rs = sum-pow(i,po);
        find1(rs, i+1,to,po);
    }

}