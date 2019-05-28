#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n, vector<int>& qb){

    if(n==0){
        return 1;
    }

    if(n<0){
        return 0;
    }

    else if(qb[n] != 0){
        return qb[n];
    }


    int path = climbStairs(n-1, qb) + climbStairs(n-2, qb) + climbStairs(n-3, qb) ;
  //  cout << n << path << endl;
     qb[n] = path;
   

    return path;
}

int climbStairsmemo(int n){

    vector<int> strg(n+1, 0);
    strg[0] = 1;
    for(int i=1;i<=n;i++){
        strg[i] += strg[i-1];
        strg[i] += (i>=2) ? strg[i-2] : 0; 
        strg[i] += (i>=3) ? strg[i-3] : 0;
    }

    return strg[n];
      
}

int main(int argc, char** argv){

    vector<int> qb(8,0);
   cout << climbStairs(7,qb) << endl;

   cout << climbStairsmemo(7) << endl;


}