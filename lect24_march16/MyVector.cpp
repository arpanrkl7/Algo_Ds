#include<iostream>
#include<string>
using namespace std;

class MyVector{
    public:
    int* arr[];
    int* size;
    int capacity;
    int index=-1;

    MyVector(){
        capacity=10;
        *arr=new int[capacity];
        size=0;


    }

    void add(int data){
        if(index+1 == capacity){
            int* tempSize=capacity*2;
            int* temparr[]=new int[tempSize];
            capacity=tempsize;
            for(int i=0;i<arr.size();i++){
                temparr[i] = arr[i];
            }
            arr=temparr;
        }
        arr[++index] = data;
        size++;
    }
};

int main(int argc,char** argv){
    MyVector* mv=new MyVector();
    mv.add(10);
    mv.add(10);
    mv.add(10);
    mv.add(10);
    mv.add(10);
    mv.add(10);
    mv.add(10);
    mv.add(10);
    mv.add(10);
    cout << size << endl;

}