#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void merge(int one[],int os,int two[],int ts,int merged[],int ms){

    int i=0,j=0,k=0;

    while(i<os && j<ts){

        if(one[i] < two[j]){
            merged[k] = one[i];
            k++;
            i++;

        }
        else
        {
            merged[k] = two[j];
            k++;
            j++;
        }
    }

    while(i<os){
        merged[k] = one[i];
            k++;
            i++;
    }

    while(j<ts){
        merged[k] = two[j];
            k++;
            j++;
    }
}

// int merge1(int arr[],int lo,int mid,int hi){
//     int newarr[9];
//     int c=0;
//     int i=lo,j=mid+1,k=0;

//     while(i<=mid && j<=hi){
//         if(arr[i] < arr[j]){
//             newarr[k] = arr[i];
//             k++;
//             i++;
//         }
//         else{
//             newarr[k] = arr[j];
//             c=+(mid-i)+1;
//             k++;
//             j++;
//         }

//     }

//     while(i<=mid){
//         newarr[k] = arr[i];
//             k++;
//             i++;
//     }

//     while(j<=hi){
//         newarr[k] = arr[j];
//             k++;
//             j++;

//     }

//     for(int i=0;i<k;i++){
//         arr[i+lo] = newarr[i];
//     }
//     return c;
// }

int merge1(int arr[],int lo,int mid,int hi){
    int size = 8;
    int newarr[size];
    int i = lo;
    int j = mid+1;
    int k=0;

    while(i<=mid && j<=hi){
        if(arr[i] < arr[j]){
            newarr[k] = arr[i];
            k++;
            i++;

        }
        else{
            newarr[k] = arr[j];
            k++;
            j++;
        }

    }

    while(i<=mid){
        newarr[k] = arr[i];
        k++;
        i++;
    }

    while(j<=hi){
        newarr[k] = arr[j];
        k++;
        j++;
    }

    for(int ii=0;ii<k;ii++){
        arr[ii+lo] = newarr[ii];
    }
}

// int mergesort(int arr[], int lo, int hi){

//     if(lo == hi){
//         return 0;
//     }

//     int mid = (lo+hi) /2;
//     int li = mergesort(arr,lo,mid);
//     int ri = mergesort(arr,mid+1,hi);
//     int mi = merge1(arr,lo,mid,hi);
//     return li+ri+mi;
// }

int mergesort(int arr[], int lo, int hi){
    if(lo == hi){
        return arr[lo];
    }

    int mid = (lo+hi)/2;
    mergesort(arr,lo,mid);
    mergesort(arr,mid+1,hi);
    merge1(arr,lo,mid,hi);

}

int partitioning(int arr[], int pivot,int n){

    int i=0;
    int p=0;

    while(i<n){
        if(arr[i] <= pivot){
            int temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
            i++;
            p++;

        }

        else if(arr[i] > pivot){

            i++;
        }

        

    }

    return arr[p-1];
}

void movenztoend(int arr[],int n){
    int z=n-1;
    int nz=n-1;

    while(z>=0){

        if(arr[z] == 0){
            z--;
        }

        else{
            int temp= arr[z];
            arr[z] = arr[nz];
            arr[nz] = temp;
            z--;
            nz--;
        }
    }
}

void sort012(int arr[], int n){

    int z=0,o=0,t=0;

    while(t<n){
        if(arr[t] == 2){
            t++;
        }

        else if(arr[t] == 1){
            int temp = arr[o];
            arr[o] = arr[t];
            arr[t] = temp;
            o++;
            t++;
        }

        else if(arr[t] == 0){
            int temp = arr[o];
            arr[o] = arr[t];
            arr[t] = temp;
            t++;
            int temp1 = arr[z];
            arr[z] = arr[o];
            arr[o] = temp1;
            z++;
            o++;


        }
    }
}

int partitioning1(int arr[],int low,int high){

    int i=low;
    int p=low;

    int pivot = arr[high];

    while(i<=high){
        if(arr[i] <= pivot){
            int temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
            i++;
            p++;

        }

        else {

            i++;
        }

        

    }

    return p-1;


}

void quicksort(int arr[], int lo, int hi){

    if(lo >= hi){
        return;
    }

    int pos = partitioning1(arr, lo , hi);
    quicksort(arr,lo,pos-1);
    quicksort(arr,pos+1,hi);



}

void countsort(int arr[], int n){

    vector<int> fm(10, 0);

    for(int i=0;i<n;i++){
        fm[arr[i]]++;
    }

    for(int i=0;i<fm.size();i++){
        fm[i] += fm[i-1];
    }


    int out[n];
    for(int i=n-1;i>=0;i--){
        out[fm[arr[i]] - 1] = arr[i];
        fm[arr[i]]--;
    }

    for(int i=0;i<n;i++){
        cout << out[i] << " ";
    }
    cout << endl;

}

void countsort1(int arr[], int n){

    vector<int> fm(10, 0);

    for(int i=0;i<n;i++){


    }

}

void countsortmodified(int arr[], int n, int j, int k){

    vector<int> fm(10, 0);

    for(int i=0;i<n;i++){
        fm[(arr[i]/k) % j]++;
    }

    for(int i=0;i<fm.size();i++){
        fm[i] += fm[i-1];
    }


    int out[n];
    for(int i=n-1;i>=0;i--){
        out[fm[(arr[i]/k) % j] - 1] = arr[i];
        fm[(arr[i]/k) % j]--;
    }


    for(int i=0;i<n;i++){
        arr[i] = out[i];
       // cout << out[i] << " ";
    }
   // cout << endl;


}

void radixsort(int arr[], int n){

    int j=10;
    int k=1;
    int max1 = INT_MIN;
    int mymax = 0;
    for(int i=0;i<n;i++){
        mymax = max(arr[i] , max1);
    }
    while(mymax>0){
    countsortmodified(arr,n,j,k);
       
     k= k*j;
     
     mymax = mymax/10;

    }
     for(int i=0;i<n;i++){
       // arr[i] = out[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    // countsortmodified(arr,n,1000);
    


}
   






int main(int argc,char** argv){

    int one[] = {10,20,30,40,50};
    // int two[] = {11,15,19,22,28,65,67,70,80};
    // int merged[14];

    // merge(one, 5, two, 9, merged, 14);

    // for(int i=0;i<14;i++){
    //     cout << merged[i] << " ";
    // }
    // cout << endl;


    int arr[] = {2,7,5,4,6,8,9,1};
    int c = mergesort(arr,0,7);
    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << c << endl;
    // int arr1[] = {2,3,9,1,8,16,7,4};
    // cout << partitioning(arr1,8,8) << endl;

    // int arr[]={2,0,5,8,0,7,0,0,9};
    // movenztoend(arr,9);
    // int arr[]={0,1,1,2,0,2,1,0,1,0,2,0,2};
    // sort012(arr,13);
    // for(int i=0;i<13;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //  int arr[] = {2,7,5,4,6,8,9,1};
    // quicksort(arr,0,7);
    // for(int i=0;i<8;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // int arr[] = {2,9,9,8,1,7,1,3,2,6,6,5,4,1,1,5,2,7,8,1};
    // int n= sizeof(arr)/sizeof(int);
    // countsort(arr,n);

    // int arr[] = {-5,-3,1,4,8,2,2,-5,-3,-2,4,9,7,-3,1,1,4,2,5};
    // int n = sizeof(arr) / sizeof(int);
    // countsort1(arr, n);
    // int arr[] = {74,362,87,92,371,544,19,47,496,382,211,631,345,912,900};
    // int n = sizeof(arr) / sizeof(int);
    // radixsort(arr, n);
    


    
}