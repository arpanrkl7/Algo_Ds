#include<iostream>
#include<vector>

using namespace std;

// class Helper{
//     int start;
//     int end;

//     operator<(start,end){
//         if(this.end > end){
//             this.end = end;
//         }
//     }
// }

int main(int argc, char** argv){

    // vector<int> start{3,0,1,8,5,5};
    // vector<int> end{4,6,2,9,9,7};

    vector<int> start{1,3,0,5,8};
    vector<int> end{2,4,6,7,9};

   // Helper hp = new Helper();
    int k=0;
    vector<int> arr(end.size(), 0);
    for(int i=0;i<end.size();i++){
        if(i == 0){
            arr[i] = 1;
        }

        else{
            if(start[i] > end[k]){
                arr[i] = arr[i-1] + 1;
                k++;
            }
            else{
                arr[i] = arr[i-1];
            }
        }
    }

    cout << arr[arr.size()-1] << endl;


}