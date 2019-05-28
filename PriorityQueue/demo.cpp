#include<iostream>
#include<queue>

using namespace std;

static void demo1(){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(1);
    pq.push(13);
    pq.push(18);
    pq.push(9);
    pq.push(33);
    while(pq.size()>0){
        int top = pq.top();
        pq.pop();
        cout << top << " ";
    }
    cout << endl;

}

int main(int argc, char** argv){

    demo1();
}


