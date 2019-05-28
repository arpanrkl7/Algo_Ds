#include<iostream>
#include<vector>

using namespace std;

int PathCount(int r, int c){

    vector<vector<int>> path(r+1, vector<int>(c+1, 0));

    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){

            if(i == 0 && j==0){
                path[i][j] = 1;
            }

            else if(i == 0){
                path[i][j] = path[i][j-1];
            }

            else if(j==0){
                path[i][j] = path[i-1][j];
            }
            else{
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
    }
    return path[r][c];
}

int PathCount1(int r, int c){

    vector<vector<int>> path(r+1, vector<int>(c+1,0));

    for(int i=r; i>=0; i--){
        for(int j=c; j>=0; j--){

            if(i == r && j==c){
                path[i][j] = 1;
            }
            else if(i == r){
                path[i][j] = path[i][j+1];
            }

            else if(j == c){
                path[i][j] = path[i+1][j];
            }

            else{
                path[i][j] = path[i+1][j] + path[i][j+1];
            }
        }
    }

    return path[0][0];
}

void pathPrint(vector<vector<int>>& path, int i, int j, string asf){

    if(i == path.size()-1 && j == path[0].size()-1){

        cout << asf << endl;
        return;
    }

    if(j == path[0].size()-1){
        pathPrint(path,i+1,j,asf + "D");

    }

    else if(i == path.size()-1){
        pathPrint(path,i,j+1,asf + "H");

    }

    else{

        int mymin = min(path[i][j+1] , path[i+1][j]);

        if(path[i][j+1] == mymin){
            pathPrint(path,i,j+1,asf + "H");
        }

        if(path[i+1][j] == mymin){
            pathPrint(path,i+1,j,asf + "D");
        }

    }

   
}

int PathCountwcost(int r, int c, vector<vector<int>> cost, vector<vector<int>>& path){

    

    for(int i=r-1; i>=0; i--){
        for(int j=c-1; j>=0; j--){

            if(i == r-1 && j==c-1){
                path[i][j] = cost[i][j];
            }
            else if(i == r-1){
                path[i][j] = path[i][j+1] + cost[i][j];
            }

            else if(j == c-1){
                path[i][j] = path[i+1][j] + cost[i][j];
            }

            else{
                path[i][j] = min(path[i+1][j] , path[i][j+1]) + cost[i][j];
            }
        }
    }
    cout << path[0][0] << endl;
    pathPrint(path,0,0,"");

    return path[0][0];
}



int main(int argc, char** argv){

  //  cout << PathCount1(2,3) << endl;

    vector<vector<int>> cost{
        {2,1,3,0,4,3},
        {4,0,1,2,7,1},
        {3,7,0,4,1,9},
        {1,2,1,8,4,2},
        {7,0,3,9,5,8}
    };
    vector<vector<int>> path(5, vector<int>(6,0));
    cout << PathCountwcost(5,6,cost,path) << endl;
    
    
}