#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class hmnode{
    int data;
    string value;

    hmnode(int data, string value){
        this->data = data;
        this->value = value;
    }
};

class hm{

    hm(){

    }

    list<hmnode>* bucket[] = NULL;
    int size;
    void initbucket(int nob){
        bucket = new list<hmnode>(4);
        size = 0;
    }

    void erase(int key){

    }

    int count(int k){

    }

    string& operator[](int key){

    }

    vector<int> keyset(){

    }

    void display(){

    }

    private:
    int hashfn(int key){
        int hc = key;
        int cf = abs(hc) % nob;
        return cf;
    }



}

int main(int argc, char** argv){

}