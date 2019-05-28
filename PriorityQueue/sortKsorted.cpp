#include<iostream>
#include<queue>

using namespace std;

void sortKsorted(vector<int> arr, int k){
    priority_queue<int ,vector<int>, greater<int>> pq;
    for(int i=0; i<=k; i++){
        pq.push(arr[i]);
    }

    for(int i=k+1; i<arr.size(); i++){
        cout << pq.top() << " ";
        pq.pop();
        pq.push(arr[i]);
    }

    while(pq.size()>0){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(int argc, char** argv){
  //  vector<int> arr{7,15,5,22,18,20,27,35,40,30};
    vector<int> arr{7,18,5,22,15,27,20,35,30};
    int k = 2;
    sortKsorted(arr,k);
}