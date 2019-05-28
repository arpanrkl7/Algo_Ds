#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;

    Node(int data){
        this->data = data;
    }

   
};

Node* construct(vector<int>& dList){
     Node* root = NULL;
     vector<Node*> nList;

     for(int i=0;i<dList.size();i++){
         if(dList[i] == -1){
             nList.pop_back();
         }
         else{

             Node* nn = new Node(dList[i]);
             if(nList.size() == 0){
                 root = nn;
             }
             else{
                 Node* ln=nList.back();
                 ln->children.push_back(nn);
             }
             nList.push_back(nn);
         }
     }
     return root;
}

 void display(Node* root){
     string s= to_string(root->data) + "->";
     for(int i=0;i<root->children.size();i++){
         s+=to_string(root->children[i]->data) + ",";

     }
     cout << s << "." << endl; 
     for(int i=0;i<root->children.size();i++){
         display(root->children[i]);
     }



 }
 int size(Node* root){
     if(root->children.size() == 0){
         return 1;
     }
     int count=0;
     for(int i=0;i<root->children.size();i++){
         count+=size(root->children[i]);
     }
     return count+1;

 }

 int max(Node* root){
     

     int maxtillnow=root->data;
     int localmax=0;

     for(int i=0;i<root->children.size();i++){
        localmax=max(root->children[i]);

        if(localmax>maxtillnow){
         maxtillnow= localmax;
     }

     }
     
     
     return maxtillnow;
 }

 int height(Node* root){ 
     int rh = 0;

     for(int i=0;i<root->children.size();i++){
        int ch = height(root->children[i]);
        rh = max(ch,rh);
     }
     rh+=1;
     return rh;

 }

 bool find(Node* root,int dtf){
     if(root->data == dtf){
         return true;
     }
     else{
     for(int i=0;i<root->children.size();i++){
         bool res=find(root->children[i],dtf);
         if(res == true){
             return true;
         }
     }
     }
     return false;
 }

 vector<int>* n2rPath(Node* root,int dtf){

     if(root->data == dtf){
         vector<int>* br=new vector<int>();
         br->push_back(root->data);
         return br;
     }
     else{
     for(int i=0;i<root->children.size();i++){
         vector<int>* res=n2rPath(root->children[i],dtf);
         if(res != NULL){
             res->push_back(root->data);
             return res;
         }
     }
     }
     return NULL;


 }

 int lca(Node* root,int d1,int d2){
     vector<int>* p1=n2rPath(root,d1);
     vector<int>* p2=n2rPath(root,d2);

     int i=p1->size()-1;
     int j=p2->size()-1;
     int prev=0;
     while(i>0 && j>0 && (*p1)[i] == (*p2)[j]){
         prev=(*p1)[i];
         i--;
         j--;
     }
     return prev;


 }

 int distance(Node* root,int d1,int d2){
     vector<int>* p1=n2rPath(root,d1);
     vector<int>* p2=n2rPath(root,d2);

     int i=p1->size()-1;
     int j=p2->size()-1;
     while(i>0 && j>0 && (*p1)[i] == (*p2)[j]){
         i--;
         j--;
     }
     return (i+1) + (j+1) + 1;

 }

 void mirror(Node* root){
     
     for(int i=0;i<root->children.size();i++){
         mirror(root->children[i]);
     }

     int left = 0;
     int right = root->children.size()-1;

     while(left<right){

         Node ln = root->children[left];
         Node rn = root->children[right];
         root->children[left] = rn;
         root->children[right] = ln;

         left++;
         right--;
     }


 }

 int main(int argc,char** argv){
     vector<int> dList{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
     Node* root=construct(dList);
     display(root);

     cout << size(root) << endl;
     cout << max(root) << endl;
     cout << height(root) << endl;
     cout << find(root,120) << endl;

     vector<int>* result=n2rPath(root,120);
     for(int i=0;i<result->size();i++){
         cout << (*result)[i] << " ";
     }

     cout << endl;

     cout << lca(root,110,120) << endl;

     cout << distance(root,60,120) << endl;

     mirror(root);
     display(root);

 }

