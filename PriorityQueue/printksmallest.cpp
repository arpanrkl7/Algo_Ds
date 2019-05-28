#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void printKsmallest(vector<int>& arr, int k){

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<arr.size(); i++){
      //  cout << arr[i] << " ";
        int temp = arr[i];
       // cout << temp << " ";
        pq.push(temp);
    }

    for(int i=0; i<k; i++){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void printKsmallestsmart(vector<int> arr, int k){

    priority_queue<int> q;
    for(int i=0; i<k; i++){
        q.push(arr[i]);
    }
    for(int i = k; i<arr.size(); i++){
        if(arr[i] < q.top()){
            q.pop();
            q.push(arr[i]);
        }
        
    }
    while(q.size()>0){
        cout << q.top() << " ";
        q.pop();
    }
}


int main(int argc, char** argv){

vector<int> arr{10,15,2,17,7,18,22,9,3};
printKsmallestsmart(arr, 4);

}