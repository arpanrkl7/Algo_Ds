#include<iostream>
#include<vector>
#include<string>

using namespace std;

void goldminePath(int i, int j, vector<vector<int>>& global, string psf){

    if(j == global[0].size()-1){
        cout << psf << endl;
        return;
    }

    if(i == 0){

        int mymax = max(global[i][j+1] , global[i+1][j+1]);
        if(mymax == global[i][j+1]){
            goldminePath(i,j+1,global, psf + "H");
        }
        if(mymax == global[i+1][j+1]){
            goldminePath(i+1,j+1,global, psf + "D");
        }
    }

    else if(i == global.size()-1){

        int mymax = max(global[i-1][j+1] , global[i][j+1]);
        if(mymax == global[i-1][j+1]){
            goldminePath(i-1,j+1,global,psf + "U");
        }
        if(mymax == global[i][j+1]){
            goldminePath(i,j+1,global,psf + "H");
        }
    }

    else{

        int mymax = max(global[i-1][j+1],max(global[i][j+1],global[i+1][j+1]));
        if(mymax == global[i-1][j+1]){
            goldminePath(i-1,j+1,global,psf + "U");
        }
        if(mymax == global[i][j+1]){
            goldminePath(i,j+1,global,psf + "H");
        }
        if(mymax == global[i+1][j+1]){
            goldminePath(i+1,j+1,global, psf + "D");
        }

    }



}

int goldCount(vector<vector<int>>& mat, int r, int c){
    vector<vector<int>> path(r, vector<int>(c, 0));

    for(int j=c-1;j>=0;j--){
        for(int i=0;i<=r-1;i++){

            if(j == c-1){
                path[i][j] = mat[i][j];
            }

            else if(i == 0){
                path[i][j] = max(path[i][j+1],path[i+1][j+1]) + mat[i][j];
            }

            else if(i == r-1){
                path[i][j] = max(path[i-1][j+1],path[i][j+1]) + mat[i][j];
            }

            else{
                path[i][j] = max(path[i-1][j+1],max(path[i][j+1],path[i+1][j+1])) + mat[i][j];
            }
        }
    }
    int max1 = 0;
    for(int i=0;i<r;i++){
        max1 = max(max1,path[i][0]);
    }

    cout << max1 << endl;

    for(int i=0;i<r;i++){
        if(path[i][0] == max1){
            goldminePath(i,0,path,to_string(i));
        }
    }

    return 0;

    
}

int main(int argc, char** argv){

    vector<vector<int>> mat{
        {1,7,3,7,5,9},
        {3,6,2,0,8,2},
        {2,1,5,1,3,1},
        {0,4,3,2,0,4},
        {4,1,4,6,1,0},
        {5,4,0,7,9,6}
    };
    cout << goldCount(mat,6,6) << endl;


}