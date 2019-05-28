#include<iostream>
#include<unordered_map>
#include<queue>
#include<string>

using namespace std;

class Node{

    char data;
    int freq;
    Node* left = NULL;
    Node* right = NULL;

    Node(char data, int freq){
        this->data = data;
        this->freq = freq;

    }

    Node(Node nn){
        this->data = nn->data;
        this->freq = nn->freq;
        this->left = nn->left;
        this->right = nn->right;
    }
}

class huffman{

    unordered_map<char, string> encoder;
    unordered_map<string, char> decoder;

    huffman(string feeder){
        unordered_map<char, int> mp;
        for(int i=0; i<feeder.size(); i++){
            if(mp.count(feeder[i]) == 0){
                mp[feeder[i]] = 1;
            }
            else{
                mp[feeder[i]]++;
            }
        }
        
        vector<Node, vector<Node>, greater<Node>> pq;
        for(auto i = mp.begin(); i!= mp.end(); i++){
            Node n1(i->first,i->second);
            pq.push(n1);
        }

        while(pq.size()!=1){
            Node fn = pq.top();
            pq.pop();
            Node sn = pq.top();
            pq.pop();
            Node nn("$",fn->freq+sn->freq);
            nn->left = new Node(fn);
            nn->right = new Node(sn);
            pq.push(nn);
        }

    }

    string encode(string str){
       
    }
    

    string decode(string str){

    }


};

int main(int argc, char** argv){

    string s = "abcdbcda";
    huffman* hm = new huffman();
    hm->encode(s);
}