#include<iostream>
using namespace std;

int x = 10;

int* rfun_g();
int* rfun_s();
int* wfun();
void print(int n);
void stackDirDetect(int* p);
void nloop();
void s1loop();
void s2loop();

int main(int argc, char** argv){
    // int* p = wfun();
    // cout << p << endl;
    // cout << *p << endl;
    int x = 10;
    stackDirDetect(&x);
    print(5);
    cout << x << endl;
    // // cout << xx << endl;
    int* p = rfun_s();
    cout << p << " " << *p << endl;

    for(int i = 0; i < 5; i++){
        // nloop();
        s1loop();
       s2loop();
    }
}

void nloop(){
    int y = 10;
    y++; 
    cout << y << endl;
}

void s1loop(){
    static int y = 10;
    y++;
    cout << y << endl;
}

void s2loop(){
    static int y = 20;
    y++;
    cout << y << endl;
}

int* rfun_s(){
    static int xx = 20;
    return &xx;
}

int* rfun_g(){
    return &x;
}

int* wfun(){
    int x = 10;
    return &x;
}

void print(int n){
    if(n == 0){
        return;
    }
    cout << &n << " " << n << endl;
    print(n - 1);
}

void stackDirDetect(int *p){
    int y = 20;

    cout << &y << endl;
    cout << p << endl;
    if(&y > p){
        cout << "Bottom up";
    } else {
        cout << "Top down";
    }
}




