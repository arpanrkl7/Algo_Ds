#include<iostream>
using namespace std;

static int count=0;
int size=0;

void display(int* arr,int n,int vidx);
// void displayr(int* arr,int n,int vidx);
int max(int* arr,int n,int vidx);
bool find(int* arr,int n,int vidx,int d);
// int fi(int* arr,int n,int vidx,int d);
// int li(int* arr,int n,int vidx,int d);
// int* allOccurence(int* arr,int n,int vidx,int d);


int main(int argc,char** argv){
    int* arr=new int[5];
    arr[0]=11;
    arr[1]=55;
    arr[2]=22;
    arr[3]=55;
    arr[4]=99;

    display(arr,5,0);
//     displayr(arr,5,0);
    cout << max(arr,5,0) << endl;
    cout << (find(arr,5,0,99)) << endl;
//      
//     cout << fi(arr,5,0,55) << endl;
//     cout << li(arr,5,0,55) << endl;
//    int* res= allOccurence(arr,5,0,55);
//    for(int i=0;i<size;i++){
//        cout << res[i] << " ";
//    }
//    cout << endl;

//     delete[] arr;

}

void display(int* arr,int n,int vidx){
    
    if(vidx == n){
        return;
    }
    cout << arr[vidx] << " " << endl;
    display(arr,n,vidx+1);
}

void displayr(int* arr,int n,int vidx){

    if(vidx ==n){
        return;
    }
    displayr(arr,n,vidx+1);
    cout << arr[vidx] << " " << endl;
}

int max(int* arr,int n,int vidx){

    if(vidx == n-1){
        return arr[vidx];
    }
   int misa= max(arr,n,vidx+1);  
   if(misa>arr[vidx]){
       return misa;
   } 
   else
   return arr[vidx];
}

bool find(int* arr,int n,int vidx,int d){
    if(vidx ==n){
        return false;
    }
    
    bool misa = find(arr,n,vidx+1,d);
    if(misa == true)
    return true;
    else{
        if(arr[vidx] == d)
        return true;
        else 
        return false;
    }

}

int fi(int* arr,int n,int vidx,int d){
    if(vidx == n){
        return -1;
    }
    if(arr[vidx] == d){
        return vidx;
    }
    int res=fi(arr,n,vidx+1,d);
    return res;
}

int li(int* arr,int n,int vidx,int d){

    if(vidx == n){
        return -1;
    }
   int res= li(arr,n,vidx+1,d);
    if(arr[vidx] == d && res==-1){
         res = vidx;
    }
    return res;
   
}

int* allOccurence(int* arr,int n,int vidx,int d){
    if(vidx == n){
        int* newarr = new int[count];
        return newarr;
    }
    if(arr[vidx]==d){
        count++;
        size++;
    }
    int* res=allOccurence(arr,n,vidx+1,d);
    if(arr[vidx] == d){
        res[count-1] = vidx;
        count--;
    }
    return res;
}










