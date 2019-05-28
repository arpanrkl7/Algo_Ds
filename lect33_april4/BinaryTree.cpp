#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
    public:
        int data;
        Node* left = NULL;
        Node* right = NULL;
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
                 if(ln->left == NULL){
                     ln->left = nn;
                 }
                 else{
                     ln->right = nn;
                 }
             }
             nList.push_back(nn);
         }
     }
     return root;
}

void display(Node* root){
    if(root == NULL){
        return;
    }
    
    if(root->left!=NULL){
        cout << root->left->data << "-> ";
    }
    else{
        cout << "." << "-> ";
    }
    cout << root->data << " <- ";
    if(root -> right!=NULL){
        cout << root->right->data << endl;

    }
    else{
        cout << "." << endl;
    }

    while(root != NULL){
        
        display(root->left);
    
        
        display(root->right);
        return;
    
    }
}

int size(Node* root){
if(root->left == NULL || root->right == NULL){
    return 1;
}
int count=0;

    count+=size(root->left);
    count+=size(root->right);


return count+1;

}

 int max(Node* root){
     if(root ->left == NULL && root->right == NULL){
         return root->data;
     }
     

     int maxtillnow=root->data;
     int localmax=0;

     
        localmax=max(root->left);
        if(localmax>maxtillnow){
         maxtillnow= localmax;
     }
        localmax=max(root->right);

        if(localmax>maxtillnow){
         maxtillnow= localmax;
     }

     
     
     
     return maxtillnow;
 }

 int height(Node* root){ 
     if(root->left == NULL && root->right == NULL){
         return 1;
     }
     int rh = 0;

     
        int ch = height(root->left);
        rh = max(ch,rh);
        ch = height(root->right);
        rh = max(ch,rh);
     
     rh+=1;
     return rh;

 }

 bool find(Node* root,int dtf){
     if(root == NULL){
         return false;
     }
     if(root->data == dtf){
         return true;
     }
     else{
     
         bool res=find(root->left,dtf);
         if(res == true){
             return true;
         }
         res=find(root->right,dtf);
         if(res == true){
             return true;
         }

     
     }
     return false;
 }

 vector<int>* n2rPath(Node* root,int dtf){
    if(root == NULL){
        return NULL;
    }

     if(root->data == dtf){
         vector<int>* br=new vector<int>();
         br->push_back(root->data);
         return br;
     }
     else{
     
         vector<int>* res=n2rPath(root->left,dtf);
         if(res != NULL){
             res->push_back(root->data);
             return res;
         }
         res=n2rPath(root->right,dtf);
         if(res != NULL){
             res->push_back(root->data);
             return res;
         }
     
     }
     return NULL;


 }

  vector<Node*>* n2rPathModified(Node* root,int dtf){
    if(root == NULL){
        return NULL;
    }

     if(root->data == dtf){
         vector<Node*>* br=new vector<Node*>();
         br->push_back(root);
         return br;
     }
  
     
         vector<Node*>* res=n2rPathModified(root->left,dtf);
         if(res != NULL){
             res->push_back(root);
             return res;
         }
         res=n2rPathModified(root->right,dtf);
         if(res != NULL){
             res->push_back(root);
             return res;
         }
     
     
     return NULL;


 }

 void kDown(Node* node,int k){
     if(node == NULL){
         return;
     }

     if(k==0){
         cout << node->data << " ";
     }

     kDown(node->left,k-1);
     kDown(node->right,k-1);
 }

 void kDownModified(Node* node,Node* prob,int k){
     if(node == NULL || node == prob){
         return;
     }

     if(k==0){
        cout << node->data << " ";
         return;
     }

     kDownModified(node->left,prob,k-1);
     kDownModified(node->right,prob,k-1);
 }

 void kFar(Node* root,int node,int k){
     vector<Node*>* path = n2rPathModified(root,node);
    
     for(int i=0;i<=k && i<path->size();i++){
         if(i==0){
         kDownModified((*path)[i],NULL,k-i);
         }
         else{
             kDownModified((*path)[i],(*path)[i-1],k-i);
         }

     }

 }

 Node* removeLeaves(Node* root){
     
     if(root->left == NULL && root->right == NULL){
         delete root;
         return NULL;
     }

     root->left = removeLeaves(root->left);
     root->right = removeLeaves(root->right);
     return root;


 }

 void printSingleChildren(Node* root){
    if(root == NULL){
        return;
    }

    if((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL)){
        cout << root->data << " ";
    }

    
    printSingleChildren(root->left);
    printSingleChildren(root->right);
 }

 void printrtlpinRange(Node* root,int low,int high,int sum){
     if(root == NULL){
         return;
     }
     sum = sum + root->data;
     printrtlpinRange(root->left,low,high,sum);
     if(low<sum<high){
         cout << root->data << " ";
         return;
     }
     printrtlpinRange(root->right,low,high,sum);
     if(low<sum<high){
         cout << root->data << " ";
         return;
     }





 }





    


 int main(int argc,char** argv){
     vector<int> dList{50,25,12,-1,37,30,-1,40,-1,-1,-1,75,62,60,-1,70,-1,-1,87,-1,-1,-1};
     Node* root=construct(dList);
     display(root);
     cout << size(root) << endl;
     cout << max(root) << endl;
     cout << height(root) << endl;
     cout << find(root,62) << endl;
     vector<int>* res=n2rPath(root,87);
     for(int i=0;i<res->size();i++){
         cout << (*res)[i] << endl;
     }
     kDown(root->left,2);
     cout << endl;
     vector<int> list1 {
        1, 2, 4, -1, 5, 6, 8, 20, 22, -1, -1, 21, -1, -1, 9, 12, 14, -1, 15, 18, -1, 19, -1, -1, -1, 13, -1, -1, -1, 7, 10, -1, 11, 16, -1, 17, -1, -1, -1, -1, -1, 3, -1, -1
    };
    Node* nr = construct(list1);
    kFar(nr, 9, 3);
    cout << endl;
   // display(nr);
   removeLeaves(root);
   display(root);
   printSingleChildren(nr);

 }
