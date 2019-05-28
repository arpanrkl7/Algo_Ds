#include<iostream>

using namespace std;

void downheapify(int arr[], int i, int n){
    int minidx = i;
        int lci = (2 * i) + 1;
        int rci = (2 * i) + 2;

        if(lci < n &&  arr[lci] > arr[minidx]){
            minidx = lci;
        }

        if(rci < n && arr[rci] > arr[minidx]){
            minidx = rci;
        }

        if(minidx != i){
            int temp = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = temp;
            downheapify(arr,minidx,n);
        }
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapsort(int arr[],int n){
    for(int i=n/2 - 1; i>=0; i--){
        downheapify(arr, i, n);
    }

    int cse = 0;
    while(cse<n-1){
    swap(arr,0,n-1-cse);
    cse++;
    downheapify(arr,0,n-cse);
    }


}

int main(int argc, char** argv){
    int arr[] = {3,1,9,5,4,8,0,2};
    heapsort(arr,8);
    for(int i=0; i<8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}