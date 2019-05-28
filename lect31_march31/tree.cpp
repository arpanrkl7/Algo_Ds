#include<iostream>
#include<vector>
#include<climits>
#include<list>
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

//  void mirror(Node* root){
     
//      for(int i=0;i<root->children.size();i++){
//          mirror(root->children[i]);
//      }

//      int left = 0;
//      int right = root->children.size()-1;

//      while(left<right){

//          Node ln = root->children[left];
//          Node rn = root->children[right];
//          root->children[left] = rn;
//          root->children[right] = ln;

//          left++;
//          right--;
//      }


//  }

 void ceilnfloor(Node* root,int depth,int& sz,int& ht,int& mn,int& mx,int& ceil,int& floor,int& data){
     sz++;
     ht=depth>ht ? depth:ht;
     mn = root->data < mn ?root->data:mn;
     mx = root->data > mx ? root->data:mx;
     ceil = root->data > data && root->data < ceil  ? root->data : ceil;
     floor = root->data < data && root-> data >floor ? root->data : floor;


     for(int i=0;i<root->children.size();i++){
         ceilnfloor(root->children[i],depth+1,sz,ht,mn,mx,ceil,floor,data);
     }
 }
 
 void predessornsuccesor(Node* root,int& status,int& predessor,int& succesor,int& data){

     if(status ==0){
         if(root->data != data){
             predessor = root->data;
         }
         else{
             status =1;
         }
     }
     else if(status ==1){
         succesor = root->data;
         status++;
     }
     for(int i=0;i<root->children.size();i++){
         predessornsuccesor(root->children[i],status,predessor,succesor,data);
     }
 }

 void predessornsuccesor2ndStyle(Node* root,int key,int& prev,int& curr,int& pred,int& succ){

     prev = curr;
     curr = root->data;

     if(curr == key){
         pred = prev;
     }
     else if(prev == key){
         succ = curr;
     }

     for(int i=0;i<root->children.size();i++){
         predessornsuccesor2ndStyle(root->children[i],key,prev,curr,pred,succ);
     }
 }

 void floorkthLargest(Node* root,int& floor,int data){
     
     floor = root->data < data && root-> data >floor ? root->data : floor;


     for(int i=0;i<root->children.size();i++){
         floorkthLargest(root->children[i],floor,data);
     }

 }

 int kthLargest(Node* root,int k){
     int data = INT_MAX;
     int res = INT_MIN;
     for(int i=0;i<k;i++){
         floorkthLargest(root,res,data);
         data = res;
         res = INT_MIN;

     }
     return data;


 }

 int diameter(Node* root){
     int maxHeightTillNow =0;
     int firstheight= height(root);
     for(int i=0;i<root->children.size();i++){
     int secondheight = height(root->children[i]);
     if(secondheight>maxHeightTillNow){
         maxHeightTillNow = secondheight;
     }


     }

     return maxHeightTillNow + firstheight -1;
 }

//  void levelOrderTraversal(Node* root){

//      int height1 = height(root);
//      for(int i=0;i<height1;i++){
//          levelOrderTraversalPrint(root,i);
//      }
//  }

//  void levelOrderTraversalPrint(root,level){
//      if(level == 0){
//          cout << root->data << " " << endl;
//      }

//      for(int i=0;i<root->children.size();i++){
//          levelOrderTraversalPrint(root->children[i],level--);
//      }

//  }

 void levelOrder(Node* root){
     list<Node*> queue;
     queue.push_back(root);
     while(queue.size() != 0){
         Node* fr=queue.front();
         queue.pop_front();
         cout << fr->data << " ";
         for(int i=0;i<fr->children.size();i++){
             queue.push_back(fr->children[i]);
         }

     }
     cout << endl;
 }

 void levelOrderlw(Node* root){

     list<Node*>* curr = new list<Node*>();
     list<Node*>* next = new list<Node*>();
     curr->push_back(root);
     while(curr->size() != 0){
         Node* fr=curr->front();
         curr->pop_front();
         cout << fr->data << " ";
         for(int i=0;i<fr->children.size();i++){
             next->push_back(fr->children[i]);
         }

         if(curr->size() ==0){
             delete curr;
             curr = next;
             next = new list<Node*>();
             cout << endl;
         }


     }
     delete curr;
     delete next;
     


 }
 
 void levelOrderZigzag(Node* root){
      list<Node*>* curr = new list<Node*>();
     list<Node*>* next = new list<Node*>();
     curr->push_back(root);
     bool ltr = true;
     while(curr->size() != 0){
         Node* fr=curr->front();
         curr->pop_front();
         cout << fr->data << " ";
         if(ltr){
         for(int i=0;i<fr->children.size();i++){
             next->push_front(fr->children[i]);
         }
         }
         else{
             for(int i=fr->children.size()-1;i>=0;i--){
             next->push_front(fr->children[i]);
         }

         }

         if(curr->size() ==0){
             delete curr;
             curr = next;
             next = new list<Node*>();
             ltr = !ltr;
             cout << endl;
         }


     }
     delete curr;
     delete next;
     

 }

 void EulerIteration(Node* root){
     

      
 }

 int main(int argc,char** argv){
     vector<int> dList{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
     Node* root=construct(dList);
    //  display(root);

    //  cout << size(root) << endl;
    //  cout << max(root) << endl;
    //  cout << height(root) << endl;
    //  cout << find(root,120) << endl;

    //  vector<int>* result=n2rPath(root,120);
    //  for(int i=0;i<result->size();i++){
    //      cout << (*result)[i] << " ";
    //  }

    //  cout << endl;

    //  cout << lca(root,110,120) << endl;

    //  cout << distance(root,60,120) << endl;

    // //  mirror(root);
    //  display(root);
     int sz=0;
     int ht=0;
     int mn=INT_MAX;
     int mx=INT_MAX;
     int ceil=INT_MAX;
     int floor=0;
     int data=68;
     ceilnfloor(root,0,sz,ht,mn,mx,ceil,floor,data);
     cout << ceil << endl;
     cout << floor << endl;
     int predessor=0;
     int succesor=0;
     int status=0;
     int data1=90;
     predessornsuccesor(root,status,predessor,succesor,data1);
     cout << predessor << endl;
     cout << succesor << endl;
     int prev=0;
     int curr=0;
     int pred =0;
     int  succ =0;
     predessornsuccesor2ndStyle(root,data1,prev,curr,pred,succ);
     cout << pred << endl;
     cout << succ << endl;
     cout << kthLargest(root,5) << endl;
     cout << diameter(root) << endl;
    //  levelOrderTraversal(root);
     levelOrder(root);
     levelOrderlw(root);
     levelOrderZigzag(root);


 }

