#include<iostream>
#include<queue>

using namespace std;

class Helper{

    public:
    int lno;
    int dno;
    int data;

    Helper(int lno, int dno, int data){
        this->lno = lno;
        this->dno = dno;
        this->data = data;
    }

    bool operator>(const Helper& other )const{
        return this->data > other.data;
    }
};

void kList(vector<vector<int>> arr, int n){
    priority_queue<Helper, vector<Helper>, greater<Helper>> pq;
    for(int i=0; i<arr.size(); i++){
        
            Helper hp(i,0,arr[i][0]);
            pq.push(hp);
        
    }
    while(pq.size() > 0){
    Helper hp = pq.top();
    cout << hp.data << " ";
    pq.pop();
    if(hp.dno+1 < arr[hp.lno].size()){
    Helper temp(hp.lno, hp.dno+1, arr[hp.lno][hp.dno+1]);
    pq.push(temp);
    }
    }

    
}

int main(int argc, char** argv){

    vector<vector<int>> arr{
        {5,15,25,35,40},
        {11,14,22,28},
        {2,7,17},
        {9,12,18,24,36}
    };
    int n = 17;
    kList(arr, n);

}