#include<iostream>
#include<vector>

using namespace std;
int count = 0;

void calculate(int p, vector<vector<int>>& arr,int cp, vector<int>& flag){

    if(p == cp){
        count++;
        return;
    }


    for(int i=0;i<arr[cp].size();i++){
        if(flag[arr[cp][i]] == 0){
            flag[arr[cp][i]] = 1;
            calculate(p,arr,cp+1,flag);
            flag[arr[cp][i]] = 0;
        }
    }
}
int counter = 0;
int calculatebm(int p, vector<vector<int>>& arr,int cp, int capsTaken, vector<vector<int>>& strg){

    if(p == cp){
        return 1;
    }

    // if(strg[cp][capsTaken] != 0){
    //     return strg[cp][capsTaken];
    // }

    int myres = 0;

    for(int ci=0;ci<arr[cp].size();ci++){
      //  int bm =1<<i;
        int cap = arr[cp][ci];
        if((capsTaken & (1<<cap)) == 0){
         //   bm = (bm ^ arr[cp][i]);
            int rres = calculatebm(p,arr,cp+1,(capsTaken | (1<<cap)),strg);
         //   bm = (bm ^ arr[cp][i]);
         myres+=rres;
        }
    }
 //   cout << ++counter << ".[" << cp << "-" << capsTaken << "] =" << myres << endl;
  //  strg[cp][capsTaken] = myres;
    return myres;
}

int calculatereversebm(vector<vector<int>>& cpmap, vector<bool>& takenPersons, int cap, int capsTaken, vector<vector<int>>& strg){


    if(cap == cpmap.size()){

        for(int i=0;i<takenPersons.size();i++){
            if(takenPersons[i] == false){
                return 0;
            }
        }
        return 1;
    }

    if(strg[cap][capsTaken] != 0){
        return strg[cap][capsTaken];
    }
    
    int myres = 0;
    myres+= calculatereversebm(cpmap,takenPersons,cap+1, capsTaken, strg);
    for(int p =0;p<cpmap[cap].size();p++){

        int person = cpmap[cap][p];
        if((capsTaken & (1<<cap)) == 0){
            int rres = calculatereversebm(cpmap, takenPersons, cap+1, capsTaken | (1<<cap), strg);
            myres+=rres;
        }
    }

    strg[cap][capsTaken] = myres;
    return myres;
}


int calculatereverse(vector<vector<int>>& cpmap, vector<bool>& takenPersons, int cap){

    if(cap == cpmap.size()){

        for(int i=0;i<takenPersons.size();i++){
            if(takenPersons[i] == false){
                return 0;
            }
        }
        return 1;
    }
    
    int myres = 0;
    myres+= calculatereverse(cpmap,takenPersons,cap+1);
    for(int p =0;p<cpmap[cap].size();p++){

        int person = cpmap[cap][p];
        if(takenPersons[person] == false){
            takenPersons[person] = true;
            int rres = calculatereverse(cpmap, takenPersons, cap+1);
            myres+=rres;
            takenPersons[person] = false;
        }
    }
    return myres;
}

void calculatebmtabulation(int p, int c, vector<vector<int>> arr){

    vector<vector<int>> strg(p+1, vector<int>(1<<c, 0));
    for(int i = p; i>=0; i--){
        for(int j = (1<<c)-1; j>=0;j--){
            if(i == p){
                strg[i][j] = 1;
            }

            else{
                for(int k = 0; k<arr[i].size();k++){
                if((j & (1<<arr[i][k]) )== 0){
                    strg[i][j]+= strg[i+1][(j | (1<<arr[i][k]))];
                }
                
            }
            }
        }
    }

    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    cout << strg[0][0] << endl;
}

int main(int argc, char** argv){

            int p = 3;
            int c = 20;

            vector<vector<int>> arr{
                {5,7,19},
                {2,7},
                {19,5}
            };
        //     vector<int> flag(c,0);

             vector<vector<int>> strg(p,vector<int>(1<<c));

           cout <<  calculatebm(p,arr,0,0,strg) << endl;

        // int p = 3;
        // int c = 4;
        // vector<vector<int>> arr{
        //         {1,3},
        //         {1,2,3},
        //         {0,2}
        //     };

        //  calculatebmtabulation(p, c, arr);

            //  cout << count << endl;
            // vector<bool> flag (p,false);

            // vector<vector<int>> cpmap{
            //     {2},
            //     {0,1},
            //     {1,2},
            //     {0,1}
            // };

          // cout <<  calculatereverse(cpmap, flag, 0) << endl;
        //   vector<vector<int>> strg(c,vector<int>(1<<p));  
        //   cout <<  calculatereversebm(cpmap, flag, 0, 0, strg) << endl;
            
}