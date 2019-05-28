#include<iostream>
#include<string>
#include<vector>
#include<climits>

using namespace std;

// void minSteps(vector<int>& local){

//     vector<int> global(local.size() , 0);
//     global[local.size()-1] = 0;

//     for(int i=local.size()-2;i>=0;i--){
//         int mins = INT_MAX;
//         for(int j=1; j<=local[i] && i+j < local.size();j++){
//             int stepsf = global[i+j];
//             if(stepsf != INT_MAX){
//                 if(stepsf < mins){
//                     mins = stepsf;
//                 }
//             }
//         }
//         if(mins != INT_MAX){
//         global[i] = mins +1;
//     }
//     else{
//         global[i] = INT_MAX;
//     } 
//     }
//         cout << global[0] << endl;


    
// }

void minSteps(vector<int>& local){

    vector<int> global(local.size(),0);
    for(int i=local.size()-2;i>=0;i--){

        int min = INT_MAX;
        for(int j=1;j<=local[i];j++){
            int mymin = global[i+j];
            if(mymin != INT_MAX){
            if(mymin<min){
                min = mymin;
            }
            }
        }
        if(min != INT_MAX){
        global[i] = min + 1;
        }
        else{
            global[i] = INT_MAX;
        }
    }
    cout << global[0] << endl;

}

int main(int argc, char** argv){

    vector<int> arr{3,4,0,1,3,1,0,3,0,1,1};
    minSteps(arr);



}