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

Node* construct(int arr[],int low,int high){
    if(low>high){
        return NULL;
    }

    int mid = (low+high)/2;
    Node* nn = new Node(arr[mid]);
    nn->left = construct(arr,low,mid-1);
    nn->right = construct(arr,mid+1,high);
    return nn;


}

bool find(Node* root,int data){
    if(root == NULL){
        return false;
    }

    if(root->data == data){
        return true;
    }
    else if(data > root->data){
        bool res=find(root->right,data);
        if(res){
            return true;
        }
    }
    else{
        bool res = find(root->left,data);
        if(res){
            return true;
        }
    }
    return false;
}

int min(Node* root){
    if(root->left == NULL){
        return root->data;
    }
    
    int res= min(root->left);
    return res;
}

int max(Node* root){
    if(root->right == NULL){
        return root->data;
    }

    int res = max(root->right);
    return res;
}

Node* construct1(vector<int>& pre,vector<int>& in,int preStart,int preEnd,int inStart,int inEnd){

     if(preStart > preEnd || inStart > inEnd){
         return NULL;
     }
     Node* root = new Node(pre[preStart]);

     int lhs=0;
     for(int i=inStart;i<=inEnd;i++){
         if(in[i] == pre[preStart]){
             break;
         }
         else
         lhs++;

     }

     root->left = construct1(pre,in,preStart+1 ,preStart+lhs , inStart,inStart+lhs-1 );
     root->right = construct1(pre,in,preStart+lhs+1 ,preEnd ,inStart+lhs+1 ,inEnd );

     return root;
 }



void ptsp(Node* root1,Node* root2,int tar){
    if(root2 == NULL){
        return;
    }

    int tarFind = tar - root2->data;
    if(tarFind<root2->data){
    
    if(find(root1,tarFind)){
        cout << root1->data << " " << tarFind << endl;
    

    ptsp(root1,root2->left,tar);
    ptsp(root1,root2->right,tar);
    }
    }


}

void fill(Node* root,vector<int>& list){

    if(root == NULL){
        return;
    }

    fill(root->left,list);
    list.push_back(root->data);
    fill(root->right,list);
}

void ptsp1(Node* root,int tar){
    vector<int> list;
    fill(root,list);
    int left=0;
    int right=list.size()-1;
    while(left<right){
        int sum = list[left] + list[right];
        if(sum>tar){
            right--;

        }
        else if(sum<tar){
            left++;
        }
        else{
            cout << list[left] << " " << list[right] << endl;
            left++;
            right--;

        }
    }
   
}


void rwsol(Node* root,int& sum){
    if(root == NULL){
        return;
    }

    int temp=0;
    rwsol(root->right,sum);
    temp=root->data;
    root->data = sum;
    sum+=temp;
    rwsol(root->left,sum);
}

int main(int argc,char** argv){
    int arr[]{20,30,40,50,60,70,80};
    Node* root = construct(arr,0,6);
    display(root);
    cout << find(root,700) << endl;
    cout << min(root) << endl;
    cout << max(root) << endl;
    vector<int> pre{50,20,10,30,25,35,70,60,55,65,80};
    vector<int> in{10,20,25,30,35,50};
    ptsp(root,root,100);
    ptsp1(root,50);
    int sum = 0;
    rwsol(root,sum);
    display(root);
}