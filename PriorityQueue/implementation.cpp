#include<iostream>
#include<vector>

using namespace std;

class MyPQ{

    private:
    vector<int> list;
    void upheapify(int i){
        if(i == 0){
            return;
        }

        else{
            int pos = (i-1)/2;
            while(i != 0){
                if(list[pos] > list[i]){
                    int temp = list[pos];
                    list[pos] = list[i];
                    list[i] = temp;
                }
                
                i = pos;
                pos = (pos-1)/2;
            }
        }
            
            //this will also works.
        
            // int pos = (i-1)/2;
            
            //     if(list[pos] > list[i]){
            //         int temp = list[pos];
            //         list[pos] = list[i];
            //         list[i] = temp;
            //         upheapify(pos);
            //     }
                
                
            
    

    }

    void downheapify(int i){
        int minidx = i;
        int lci = (2 * i) + 1;
        int rci = (2 * i) + 2;

        if(lci < list.size() &&  list[lci] < list[minidx]){
            minidx = lci;
        }

        if(rci < list.size() && list[rci] < list[minidx]){
            minidx = rci;
        }

        if(minidx != i){
            int temp = list[i];
            list[i] = list[minidx];
            list[minidx] = temp;
            downheapify(minidx);
        }
    }

    public:

    MyPQ(vector<int> content){

        for(int i=0; i<content.size(); i++){
            list.push_back(content[i]);
        }
        for(int i = list.size()/2-1; i>=0; i--){
            downheapify(i);
        }
    }

    int peek(){
        return list[0];
    }
    void remove(){
       // list[0] = list[list.size()-1];
       int temp = list[0];
       list[0] = list[list.size()-1];
       list[list.size()-1] = temp;
        list.pop_back();
        downheapify(0);

    }
    
    void add(int data){
        list.push_back(data);
        upheapify(list.size()-1);
    }

    int size(){
        return list.size();
    }
};

int main(int argc, char** argv){

    MyPQ pq(vector<int>{22,88,67,3,76,25});
//     pq.add(8);
//    pq.add(1);
//     pq.add(88);
//     pq.add(78);
//     pq.add(45);
//     pq.add(90);
//     pq.add(5);
   
    while(pq.size() != 0){
        int val = pq.peek();
        pq.remove();
        cout << val << " ";
    }
    cout << endl;

}