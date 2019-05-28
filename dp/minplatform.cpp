#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv){

    vector<int> arr {900,940,950,1100,1500,1800};
    vector<int> dept {910,1120,1130,1200,1900,2000};
    int max1 = 0;
    int count = 0;
    int i = 0;
    int j = 0;

    while(i<arr.size()){
        if(arr[i]  < dept[j]){
            count = count+1;
            max1 = max(count,max1);
            i++;

        }

        else{
            count--;
            j++;
        
        }
    }

    cout << max1 << endl;
}