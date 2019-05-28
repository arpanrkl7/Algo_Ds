#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int climbStairs(int n,vector<int>& strg){

    if(n == 0){
        return 1;
    }

    if(n<0){
        return 0;
    }

    if(strg[n] != 0){
        return strg[n];
    }

    int res = climbStairs(n-1,strg) + climbStairs(n-2,strg) + climbStairs(n-3,strg);
    cout << n << " " << res << endl;
    strg[n] = res;
    return res;
}

int climbStairsTab(int n, vector<int>& strg){

    strg[0] = 1;
    strg[1] = 1;
    strg[2] = 2;
    for(int i=3;i<=n;i++){
        strg[i] = strg[i-1] + strg[i-2] + strg[i-3];
    }

    return strg[n];
}

int countMaizepath1(int r, int c){
    vector<vector<int>> strg(r, vector<int>(c, 0));
    for(int i =r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(i == r-1 || j == c-1){
                strg[i][j] = 1;
            }

            else{
                strg[i][j] = strg[i+1][j] + strg[i][j+1];
            }
        }

    }

    return strg[0][0];
}

int countMaizepath2(int r, int c){

    vector<vector<int>> strg(r, vector<int>(c, 0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i == 0 || j == 0){
                strg[i][j] = 1;
            }

            else{
                strg[i][j] = strg[i-1][j] + strg[i][j-1];

            }
        }
    }
    return strg[r-1][c-1];
}

void cheapestPathPrint(vector<vector<int>>& strg, int i, int j, string asf){

    if(i == strg.size()-1 && j == strg[0].size()-1){
        cout << asf << endl;
        return;
    }
    if(i<strg.size() && j<strg[0].size()){
    if(strg[i][j+1] < strg[i+1][j]){
        cheapestPathPrint(strg, i, j+1, asf + "H");
    }

    else if(strg[i+1][j] < strg[i][j+1]){
        cheapestPathPrint(strg, i+1, j, asf + "V");
    }

    else{
        cheapestPathPrint(strg, i, j+1, asf + "H");
        cheapestPathPrint(strg, i+1, j, asf + "V");
    }
    }
}

int cheapestPath(int r, int c, vector<vector<int>> arr){

    vector<vector<int>> strg(r, vector<int> (c,0));
    for(int i = r-1; i>=0; i--){
        for(int j = c-1; j>=0; j--){
            if(i == r-1 && j == c-1){
                strg[i][j] = arr[i][j];
            }

            else if(i == r-1){
                strg[i][j] = arr[i][j] + strg[i][j+1];
            }

            else if(j == c-1){
                strg[i][j] = arr[i][j] + strg[i+1][j];
            }

            else{
                strg[i][j] = min(strg[i][j+1], strg[i+1][j]) + arr[i][j];
            }
        }
    }

    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    cheapestPathPrint(strg, 0, 0, "");
    return strg[0][0];
}

void goldMinePath(vector<vector<int>>& strg, int i, int j, string asf){

    if(i< 0 || i>=strg.size() || j<0 || j>=strg[0].size() ){
        return;
    }


    if(j == strg[0].size()-1){
        cout << asf << endl;
        return;
    }

    

    
    int mymax = max(i>0 && j<strg[0].size()-1 ? strg[i-1][j+1] : 0, max(j<strg[0].size()-1 ? strg[i][j+1] : 0,
                    i<strg.size()-1 && j<strg[0].size()-1 ? strg[i+1][j+1] : 0));
    
    if(i>0 && j<strg[0].size()-1){
    if(strg[i-1][j+1] == mymax){
        
        goldMinePath(strg, i-1, j+1, asf + "U");
        }
    }
    if(j<strg[0].size()-1){
    if(strg[i][j+1] == mymax){
        
        goldMinePath(strg, i, j+1, asf + "H");
        }
    }
    if(i<strg.size()-1 && j<strg[0].size()-1){
    if(strg[i+1][j+1] == mymax){
        
        goldMinePath(strg, i+1, j+1, asf + "D");
    }
    }


    

}

int goldMine(int r, int c, vector<vector<int>> arr){

    vector<vector<int>> strg(r, vector<int>(c, 0));

    for(int j = c-1; j>=0; j--){
        for(int i =0; i<r; i++){
            if(j == c-1){
                strg[i][j] = arr[i][j];
            }

            else if(i == 0){
                strg[i][j] = max(strg[i][j+1], strg[i+1][j+1]) + arr[i][j];
            }

            else if(i == r-1){
                strg[i][j] = max(strg[i-1][j+1], strg[i][j+1]) + arr[i][j];
            }

            else{
                strg[i][j] = max(strg[i-1][j+1], max(strg[i][j+1], strg[i+1][j+1])) + arr[i][j];
            }
        }
    }
    int max1 = 0;
    for(int i=0;i<r;i++){
        max1 = max(max1, strg[i][0]);
    }

    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0;i<r;i++){
        if(strg[i][0] == max1){
            goldMinePath(strg, i, 0, "");
        }
    }
    return max1;
}

void minJumpsPrint(vector<int>& strg, vector<int>& arr, int i, string asf){

    if(i>=strg.size()){
        return;
    }

    if(i == strg.size()-1){
        cout << asf << endl;
        return;
    }

    

    int myMin = INT_MAX;
    for(int j = i; j<arr[i] && j<strg.size(); j++){
        myMin = min(myMin,strg[j]!=INT_MAX ? strg[j] : INT_MAX);
    }

    

    for(int j = i; j<arr[i] && j<strg.size(); j++){
        if(strg[j] == myMin){
            minJumpsPrint(strg, arr, j, asf + to_string(j+1));
        }
    }

}

int minJumps(vector<int> arr){

    vector<int> strg(arr.size(), 0);

    for(int i = arr.size()-1; i>=0;i--){

        if(i == strg.size()-1){
            strg[i] = 0;
        }

        else if(arr[i] == 0){
            strg[i] = INT_MAX;
        }

        else{
            int min1 = INT_MAX;
            for(int j = i+1; j<= i + arr[i] && j<strg.size(); j++){
                min1 = min(min1, strg[j]);
            }
            strg[i] = min1 != INT_MAX ? min1+1 : INT_MAX;
        }
    }

    for(int i=0;i<strg.size();i++){
        cout << strg[i] << " ";
    }

    minJumpsPrint(strg, arr, 0, "");

    return strg[0];

}

int coinChangePerm(vector<int> coins, int sum){

    vector<int> strg(sum+1, 0);

    for(int i=0;i<=sum;i++){
        if(i == 0){
            strg[i] = 1;
        }

        else{
            for(int j =0;j<coins.size();j++){
                strg[i]+= i-coins[j] >=0 ? strg[i-coins[j]] : 0;
            }
        }
    }

    for(int i=0;i<strg.size();i++){
        cout << strg[i] << " ";
    }
    cout << endl;

    return strg[sum];
}

int coinChangeComb(vector<int> coins, int sum){

    vector<int> strg(sum+1, 0);
    strg[0] = 1;
    for(int i=0;i<coins.size();i++){
        for(int j = 0;j<strg.size();j++){
            strg[j]+= j-coins[i] >=0 ? strg[j-coins[i]] : 0;
        }
    }

    for(int i=0;i<strg.size();i++){
        cout << strg[i] << " ";
    }
    cout << endl;
    return strg[sum];
}

void tarSumSubsetPrint(vector<vector<int>>& strg, vector<int>& arr, int i, int j, string asf){
    if(i<0 || j<0){
        return;
    }
    if(j == 0){
        cout << asf << endl;
        return;
    }
    if(strg[i][j] == 0){
       // cout << asf << endl;
        return;
    }

    tarSumSubsetPrint(strg, arr, i-1, j, asf);
    tarSumSubsetPrint(strg, arr, i-1, j-arr[i-1], asf + to_string(arr[i-1]) + " ");
}

int tarSumSubset(vector<int> arr, int sum){

    vector<vector<int>> strg(arr.size()+1, vector<int>(sum+1,0));
    strg[0][0] = 1;

    for(int i=1;i<=arr.size();i++){
        for(int j=0;j<=sum;j++){

            if(j == 0){
                strg[i][j] = 1;
            }

            else{

                strg[i][j] = strg[i-1][j] + ((j-arr[i-1] >=0) ? strg[i-1][j-arr[i-1]] : 0);
            }
                        
        }
    }

    // for(int i=0;i<strg.size();i++){
    //     for(int j=0;j<strg[0].size();j++){
    //         cout << strg[i][j] << " ";
    //     }
    //     cout << endl;
    // }

  //  tarSumSubsetPrint(strg, arr, strg.size()-1, strg[0].size()-1, "");

    return strg[arr.size()][sum];
}

int knapsack01(vector<int> prices, vector<int> weights, int tw){

    vector<vector<int>> strg(weights.size()+1, vector<int>(tw+1,0));

    for(int i=1;i<=weights.size();i++){
        for(int j=1;j<=tw;j++){

            strg[i][j] = max(strg[i-1][j], (j-weights[i-1]>=0 ? (strg[i-1][j-weights[i-1]] + prices[i-1]) : 0));

        }
    }

    for(int i=0;i<strg.size();i++){
        for(int j=0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    return strg[weights.size()][tw];
}

int unboundedKnapsack(vector<int> prices, vector<int> weights, int tw){

    vector<int> strg(tw+1,0);
    for(int i = 1;i<=tw; i++){
        for(int j = 0; j<weights.size(); j++){
            strg[i] = max(strg[i], (i-weights[j] >=0 ? (prices[j] + strg[i-weights[j]]) : 0));
        }
    }
    for(int i=0;i<strg.size();i++){
        cout << strg[i] << " ";
    }
    cout << endl;
    return strg[tw];
}

void lcsPrint(string s1, string s2, vector<vector<int>>& strg, int i, int j, string asf){

     if(i == s1.size() && j == s2.size()){
        cout << asf << endl;
        return;
    }

    else if(i == s1.size() || j == s2.size()){
        return;

    }

   


    if(s1[i] == s2[j]){
        lcsPrint(s1, s2, strg, i+1, j+1, asf+ s1[i]);
    }

    else{
        int mymax = max(strg[i+1][j], strg[i][j+1]);
        if(strg[i+1][j] == mymax){
            lcsPrint(s1, s2, strg, i+1, j, asf);
        }

        if(strg[i][j+1] == mymax){
            lcsPrint(s1, s2, strg, i, j+1, asf);
        }
    }
    
}

int lcs(string s1, string s2){

    vector<vector<int>> strg(s1.size()+1, vector<int>(s2.size()+1,0));
    for(int i = s1.size(); i>=0; i--){
        for(int j = s2.size(); j>=0; j--){
            if(i == s1.size() || j == s2.size()){
                strg[i][j] = 0;
            }

            else{
                if(s1[i] == s2[j]){
                    strg[i][j] = 1 + strg[i+1][j+1];
                }
                else{
                    strg[i][j] = max(strg[i+1][j], strg[i][j+1]);
                }
            }
        }
    }

    // for(int i=0;i<strg.size();i++){
    //     for(int j=0;j<strg[0].size();j++){
    //         cout << strg[i][j] << " ";
    //     }
    //     cout << endl;
    // }

  //  lcsPrint(s1, s2, strg, 0, 0, "");

    return strg[0][0];
}

int lps(string s){

    vector<vector<int>> strg(s.size(), vector<int>(s.size(),0));
    for(int gap = 0; gap<strg.size(); gap++){
        for(int i=0,j=i+gap; j<strg.size();i++,j++){
            if(gap == 0){
                strg[i][j] = 1;
            }

            else{
                if(s[i] == s[j]){
                    strg[i][j] = 2 + strg[i+1][j-1];
                }
                else{
                    strg[i][j] = max(strg[i][j-1], strg[i+1][j]);
                }
            }
        }
    }

    for(int i=0; i<strg.size(); i++){
        for(int j=0; j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    return strg[0][s.size()-1];
}

int cps(string s){

    vector<vector<int>> strg(s.size(), vector<int>(s.size(),0));
    for(int gap = 0; gap<strg.size(); gap++){
        for(int i=0,j=i+gap; j<strg.size(); i++,j++){
            if(gap == 0){
                strg[i][j] = 1;
            }
            else{
                if(s[i] != s[j]){
                    strg[i][j] = strg[i][j-1] + strg[i+1][j] - strg[i+1][j-1];
                }
                else{
                    strg[i][j] = strg[i][j-1] + strg[i+1][j] + 1;
                }
            }
        }
    }

    return strg[0][strg.size()-1];
}

int cpsubstring(string s){
    int count = 0;
    int length = 0;
    vector<vector<bool>> strg(s.size(), vector<bool>(s.size(),false));

    for(int gap = 0; gap<strg.size(); gap++){
        for(int i=0,j=i+gap; j<strg.size(); i++,j++){

            if(gap == 0){
                strg[i][j] = true;
                count++;
            }
            else if(gap == 1){
                if(s[i] == s[j]){
                    strg[i][j] = true;
                    count++;
                }
                else{
                    strg[i][j] = false;
                }
            }

            else{
                if(s[i] == s[j]){
                    strg[i][j] = strg[i+1][j-1] == true ? (true && count++) : false;
                }
                else{
                    strg[i][j] = false;
                }
            }

            if(strg[i][j] == true){
                length = gap + 1;
            }
        }
    }
    cout << count << " " << length << endl;
    return count;
}

int cbswna0(int n){
    int z = 1,o = 1;
    for(int i=1;i<n;i++){
        int nz = o;
        int no = z+o;
        z = nz;
        o = no;
    }
    return z+o;
}

int countabc(string s){

    int ca = 0, cb = 0, cc = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a'){
            ca = 2*ca +1;
        }

        else if(s[i] == 'b'){
            cb = ca + 2*cb;
        }

        else if(s[i] == 'c'){
            cc = cb + 2*cc;
        }
    }

    return cc;

}

void lisPrint(vector<int>& strg, vector<int>& arr, int pos, int mymax){
    if(mymax == 0){
        return;
    }

    for(int i=0; i<pos; i++){
        if(strg[i] == mymax-1 && arr[i] < arr[pos]){
            lisPrint(strg, arr, i, mymax-1);
            cout << arr[i] << " ";
        }
    }
}

int lis(vector<int> arr){

    vector<int> strg(arr.size(), 0);
    for(int i=0; i<arr.size(); i++){
        if(i == 0){
            strg[i] = 1;
        }

        else{
            for(int j=0; j<i; j++){
                strg[i] = arr[i] > arr[j] ? max(strg[i], strg[j]+1) : max(strg[i], 1);
            }
            
        }
    }
    int max1 = 0;
    for(int i=0; i<strg.size();i++){
        cout << strg[i] << " ";
        max1 = max(max1, strg[i]);
    }
    cout << endl;

    for(int i=0; i<strg.size();i++){
        if(strg[i] == max1){
            lisPrint(strg, arr, i, max1);
        }
    }

    return max1;
}

int lbs(vector<int> arr){

    vector<int> strg1(arr.size(),1);
    for(int i=1; i<strg1.size(); i++){
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i]){
                strg1[i] = max(strg1[i], strg1[j]+1);
            }
            
        }
    }

    vector<int> strg2(arr.size(), 1);
    for(int i=arr.size()-2; i>=0; i--){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]){
                strg2[i] = max(strg2[i], strg2[j]+1);
            }
        }
    }
    int mymax = 0;
    for(int i=0; i<strg1.size(); i++){
        mymax = max(mymax, (strg1[i]+strg2[i]));
    }
    return --mymax;
}

int minPaldcut(string s){

    vector<vector<int>> strg(s.size(), vector<int>(s.size(),0));
    for(int gap = 0; gap<strg.size(); gap++){
        for(int i=0,j=i+gap; j<strg.size(); i++,j++){
            if(gap == 0){
                strg[i][j] = 0;
            }
            else if(gap == 1){
                if(s[i] == s[j]){
                    strg[i][j] = 0;
                }
                else{
                    strg[i][j] = 1;
                }

            }

            else{
                if(s[i] == s[j] && (strg[i+1][j-1] == 0)){
                    strg[i][j] = 0;
                }
                else{
                strg[i][j] = INT_MAX;
                for(int k = i,l = i; l<j; l++){
                    strg[i][j] = min(strg[i][j], strg[k][l] + strg[l+1][j]);
                }
                strg[i][j]++;
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
}

int rodcut(vector<int> arr){

    vector<int> strg(arr.size()+1,0);
    for(int i=1; i<strg.size(); i++){
        if(i == 1){
            strg[i] = arr[i-1];
        }
        else{
            strg[i] = arr[i-1];
            for(int k = 1,l=i-1; k<=l; k++,l--){
                strg[i] = max(strg[i], (strg[k] + strg[l]));
            }
        }
    }
    for(int i=0; i<strg.size(); i++){
        cout << strg[i] << " ";
    }
    cout << endl;
    return strg[arr.size()];
}

int mcm(vector<int> arr){

    vector<vector<int>> strg(arr.size()-1, vector<int>(arr.size()-1,0));
    for(int gap = 0; gap<strg.size(); gap++){
        for(int i=0,j=i+gap; j<strg.size(); i++,j++){
            if(gap == 0){
                strg[i][j] = 0;
            }


            else if(gap == 1){
                strg[i][j] = arr[i] * arr[j] * arr[j+1];
            }

            else{
                strg[i][j] = INT_MAX;
                for(int k = i,l = i; l<j; l++){
                    strg[i][j] = min(strg[i][j], (strg[k][l] + strg[l+1][j] + arr[k]*arr[l+1]*arr[j+1] ));
                }
            }
        }
    }

    for(int i = 0;i<strg.size();i++){
        for(int j = 0;j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    return strg[0][strg.size()-1];
}

int eggdrop(int egg, int floor){

    vector<vector<int>> strg(egg+1, vector<int>(floor+1,0));
    for(int i=0;i<=egg;i++){
        for(int j=0;j<=floor;j++){
            if(i == 0){
                strg[i][j] = 0;
            }
            else if(i == 1){
                strg[i][j] = j;
            }

            else{

                if(j == 0 || j == 1){
                    strg[i][j] = j;
                }
                else{
                    strg[i][j] = INT_MAX;
                    for(int k = i-1,l=0; l<j; l++){
                        strg[i][j] = min(strg[i][j], max(strg[k][l], strg[k+1][j-l-1]));
                    }
                    ++strg[i][j];
                }
            }
        }
    }
    for(int i = 0; i<strg.size(); i++){
        for(int j = 0; j<strg[0].size();j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    return strg[egg][floor];
}
int count = 0;
void personCaps(int c, int p, vector<vector<int>>& pcmap, int cp, vector<bool>& flag, string asf){

    if(p == cp){
        count++;
        cout << asf << endl;
        return;
    }

    for(int i = 0; i<pcmap[cp].size(); i++){
        if(flag[pcmap[cp][i]] == false){
            flag[pcmap[cp][i]] = true;
        personCaps(c, p, pcmap, cp+1, flag, asf + to_string(pcmap[cp][i]) + " ");
        flag[pcmap[cp][i]] = false;
        }
    }
}

void personCapsbm(int c, int p, vector<vector<int>>& pcmap, int cp, string asf, int bm){

    if(p == cp){
        count++;
        cout << asf << endl;
        return;
    }
   // int bm = 0;
    for(int i = 0; i<pcmap[cp].size(); i++){
        
        if((bm & (1<<pcmap[cp][i])) == 0){
            
            bm = (bm ^ (1<<pcmap[cp][i]));
            personCapsbm(c, p, pcmap, cp+1, asf + to_string(pcmap[cp][i]) + " ",bm);
            bm = (bm ^ (1<<pcmap[cp][i]));
        
        }
    }
}
int counter = 0;
int personCapsbmMemo(int c, int p, vector<vector<int>>& pcmap, int cp, string asf, vector<vector<int>>& strg, int bm){

    if(p == cp){
        
      //  cout << asf << endl;
        return 1;
    }
    if(strg[cp][bm] != 0){
        return strg[cp][bm];
    }
    int res = 0;
    for(int i = 0; i<pcmap[cp].size(); i++){
        
        if((bm & (1<<pcmap[cp][i])) == 0){
            
            bm = (bm ^ (1<<pcmap[cp][i]));
            int mres = personCapsbmMemo(c, p, pcmap, cp+1, asf + to_string(pcmap[cp][i]) + " ", strg, bm);
            bm = (bm ^ (1<<pcmap[cp][i]));
            res+=mres;
        }
    }
    cout << ++counter << ".[" << cp << "-" << bm << "] =" << res << endl;
    strg[cp][bm] = res;
    return res;

}



int main(int argc, char** argv){
    // int n =7;
    // vector<int> strg(n+1,0);
    // cout << climbStairsTab(n,strg) << endl;
    // cout << countMaizepath2(4,5) << endl;

    // vector<vector<int>> cost{
    //     {2,1,3,0,4,3},
    //     {1,0,1,2,7,1},
    //     {0,1,0,4,1,9},
    //     {1,2,1,1,4,2},
    //     {7,0,3,9,5,8}
    // };
  //  vector<vector<int>> path(5, vector<int>(6,0));
    // cout << cheapestPath(5,6,cost) << endl;

    // vector<vector<int>> mat{
    //     {1,7,3,7,5,9},
    //     {3,6,2,0,8,2},
    //     {2,1,5,1,3,1},
    //     {0,4,3,2,0,4},
    //     {4,1,4,6,1,0},
    //     {5,4,0,7,9,0}
    // };
    // cout << goldMine(6,6,mat) << endl;

   // vector<int> arr{3,4,0,1,3,1,0,3,0,1,1};
    // vector<int> arr{1,3,5,8,9,2,6,77,6,8,9};
    // cout << minJumps(arr) << endl;

    // vector<int> arr{2,3,5};
    // int sum = 7;
    // cout << coinChangePerm(arr, sum) << endl;
    // cout << coinChangeComb(arr, sum) << endl;

    // vector<int> arr{10,20,30,40,50,60,70};
    vector<int> arr{886,777,915,793,335,386,492,649,421,362,27,690,59,763,926,540,426,172,736,211,368,567,429,782,530,862,123,67,135,929,802,22,58,69,167,393,456,11,42,229,373,421,919,784,537,198,324,315,370,413,526,91,980,956,873,862,170,996,281,305,925,84,327,336,505,846,729,313,857,124,895,582,545,814,367,434,364,43,750,87,808,276,178,788};
    int sum = 20139;
    // int sum = 70;
     cout << tarSumSubset(arr, sum) << endl;
    // vector<int> prices {15,14,10,45,30};
    // vector<int> weights{2,5,1,3,4};
    // int tw = 7;
    //cout << knapsack01(prices, weights, tw) << endl;
    //cout << unboundedKnapsack(prices, weights, tw) << endl;

    //cout << lcs("AGGTAB", "GXTXAYB") << endl;
    //cout << lcs("abcd", "aebd") << endl;

   // cout << lcs("LRBBMQBHCDARZOWKKYHIDDQSCDXRJMOWFRXSJYBLDBEFSARCBYNECDYGGXXPKLORELLNMPAPQFWKHOPKMCO"
   //             ,"QHNWNKUEWHSQMGBBUQCLJJIVSWMDKQTBXIXMVTRRBLJPTNSNFWZQFJMAFADRRWSOFSBCNUVQHFFBSAQXWPQCAC") << endl;

   // cout << lps("bddaghdab") << endl;
   //cout << cps("acbkca") << endl;
  // cpsubstring("abccbc");
 //  cout << cbswna0(5) << endl; 
  // cout << countabc("abcabc") << endl;

   //vector<int> arr{10,22,9,33,21,50,41,60,80,1};
   
   //cout << lis(arr) << endl;
  // cout << lbs(arr) << endl;

 // minPaldcut("abccbc");
  //minPaldcut("abbaab");
    // vector<int> arr{3,5,6,15,10,25,12,24};
    // cout << rodcut(arr) << endl;
    // vector<int> arr{10,20,30,40,50,60};
    // cout << mcm(arr) << endl;
    //cout << eggdrop(2,10) << endl;
    // vector<vector<int>> pcmap{
    //     {5,7,19},
    //     {2,7},
    //     {19,5}
    // };
    vector<vector<int>> pcmap{
        {5,7,19},
        {2,7},
        {19,5},
        {11,12},
        {7,19,11}
    };
    int p = 5;
    int c = 20;
   // vector<bool> flag(c,false);
  //  personCaps(20,3,pcmap,0,flag, "");
   // cout << count << endl;
    // personCapsbm(c,p,pcmap,0,"",0);
    // cout << count << endl;

    //  vector<vector<int>> strg(p, vector<int>(1<<c,0));
    // cout << personCapsbmMemo(c,p,pcmap,0,"",strg,0) << endl;

}