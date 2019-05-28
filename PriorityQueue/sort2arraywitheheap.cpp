#include<iostream>

using namespace std;

int get(int a[], int b[], int as, int bs, int i){

    if(i<as){

        return a[i];
    }
    else{
        return b[i-as];
    }
}

void set(int a[], int b[], int as, int bs, int i, int value){
    if(i<as){
        a[i] = value;
    }
    else{
        b[i-as] = value;
    }
}

void swap(int a[], int b[], int as, int bs, int i, int j){
    
    int ith = get(a,b,as,bs,i);
    int jth = get(a,b,as,bs,j);
    set(a,b,as,bs,i,jth);
    set(a,b,as,bs,j,ith);
}


void downheapify(int a[], int b[], int as, int bs, int i, int n){
    int minidx = i;
        int lci = (2 * i) + 1;
        int rci = (2 * i) + 2;

        if(lci < n &&  get(a,b,as,bs,lci) > get(a,b,as,bs,minidx)){
            minidx = lci;
        }

        if(rci < n && get(a,b,as,bs,rci) > get(a,b,as,bs,minidx)){
            minidx = rci;
        }

        if(minidx != i){
            swap(a,b,as,bs,minidx,i);
            downheapify(a,b,as,bs,minidx,n);
        }
}




void heapsort(int a[], int b[], int as, int bs){
    for(int i=(as+bs)/2 - 1; i>=0; i--){
        downheapify(a, b, as, bs, i, as+bs);
    }

    int cse = 0;
    while(cse<as+bs-1){
    swap(a, b, as, bs, 0, as+bs-1-cse);
    cse++;
    downheapify(a, b, as, bs, 0, as+bs-cse);
    }


}

int main(int argc, char** argv){
    int a[] = {5,19,3};
    int b[]= {0,16,12,4,-4};
    heapsort(a,b,3,5);
    for(int i=0; i<3; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    for(int i=0; i<5; i++){
        cout << b[i] << " ";
    }
    cout << endl;
}