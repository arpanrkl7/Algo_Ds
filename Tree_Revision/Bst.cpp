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
    int mid = (low + high) /2;
    Node* nn = new Node(arr[mid]);
    nn->left = construct(arr,low,mid-1);
    nn->right = construct(arr,mid+1,high);
    return nn;


}

bool find(Node* root , int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }

    else if(data<root->data){
        return find(root->left,data);
    }
    else if(data>root->data){
        return find(root->right,data);
    }
}

int min(Node* root){
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    
    int m = min(root->left);
    return m;
}

int max(Node* root){
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int m = max(root->right);
    return m;

}

void ptsp(Node* root,Node* oRoot,int tarSum){
    if(root == NULL){
        return;
    }

    int tarFind = tarSum - root->data;
    if(tarFind<oRoot->data){
    if(find(oRoot,tarFind)){
        cout << root->data << " " << tarFind << endl;
    }
    }
    ptsp(root->left,oRoot,tarSum);
    ptsp(root->right,oRoot,tarSum);


}

void filler(Node* root,vector<int>& list){
    if(root == NULL){
        return;
    }

    filler(root->left,list);
    list.push_back(root->data);
    filler(root->right,list);
}

void filler2(Node* root,int arr[]){
    if(root == NULL){
        return;
    }

    filler2(root->left,arr);
    arr[root->data] = 1;
    filler2(root->right,arr);

}

void filler3(Node* root,int arr[],int tarSum){
    if(root == NULL){
        return;
    }

    filler3(root->left,arr,tarSum);
    int diff = tarSum - root->data;
    arr[root->data] = 0;
    if(arr[diff] == 1){
        cout << root->data << " "  << diff << endl;


    }
    filler3(root->right,arr,tarSum);

}

void rwsol(Node* root,int& sum){
    if(root == NULL){
        return;
    }
   // int temp = 0;
    rwsol(root->right,sum);
    int temp = root->data;
    root->data = sum;
    sum = sum+temp;
    rwsol(root->left,sum);

}



void ptsp2(Node* root,int tarSum){
    vector<int> list;
    filler(root,list);
    int low = 0;
    int high = list.size()-1;
    while(low<high){
        int sum = list[low] + list[high];
        if(sum>tarSum){
            high--;
        }
        else if(sum<tarSum){
            low++;
        }
        else{
            cout << list[low] << " " << list[high] << endl;
            low++;
            high--;
        }
    }
}
// my new method run successfully.
void ptsp3(Node* root,int tarSum){
    int arr[100]{0};
    filler2(root,arr);
    filler3(root,arr,tarSum);
}


int main(int argc,char** argv){
    int arr[]{20,30,40,50,60,70,80};
    int arr1[]{10,20,30,50,60,70,80};
    Node* root = construct(arr,0,6);
    Node* root1 = construct(arr1,0,6);
    // display(root);
    // cout << find(root,80) << endl;
    // cout << min(root) << endl;
    // cout << max(root) << endl;
    // ptsp(root,root,100);
    // ptsp2(root,100);
    // ptsp3(root,100);
    int sum = 0;
    rwsol(root1,sum);
    display(root1);
}