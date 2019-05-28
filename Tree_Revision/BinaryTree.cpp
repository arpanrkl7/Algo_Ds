#include<iostream>
#include<vector>
#include<list>
#include<climits>
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

Node* construct(vector<int>& dlist){

    Node* root = NULL;
    list<Node*>* nlist = new list<Node*>();
    for(int i=0;i<dlist.size();i++){
        if(dlist[i] == -1){
            nlist->pop_back();
        }
        else{
        Node* nn = new Node(dlist[i]);
        if(nlist->size()==0){
            root = nn;
            nlist->push_back(nn);

        }
        else{
            Node* back = nlist->back();
            if(back->left == NULL){
                back->left = nn;
            }
            else{
                back->right = nn;
            }
            nlist->push_back(nn);
        }
        }

    }

    return root;
}

void display(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left!=NULL){
        cout << root->left->data << "->";
    }
    else{
        cout << ".->";
    }
    cout << " " << root->data << " ";
    if(root->right!=NULL){
        cout << "<-" << root->right->data << endl;
    }
    else{
        cout << "<-." << endl;
    }
    
    display(root->left);
    display(root->right); 
   
}

int size(Node* root){
    if(root == NULL){
        return 0;
    }
    int localSize=0;

    localSize+=size(root->left);
    localSize+=size(root->right);
    return localSize+1;
}

int max1(Node* root){
    if(root == NULL){
        return 0;
    }

    int localMaxl = 0;
    int localMaxr = 0;
    localMaxl = max1(root->left);
    localMaxr = max1(root->right);
    return max(root->data,max(localMaxl,localMaxr));
    
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }


    int localHeightl=height(root->left);
    int localHeightr=height(root->right);
    return localHeightl>localHeightr?localHeightl+1:localHeightr+1;
    
}

bool find(Node* root,int data){
    if(root == NULL){
        return false;
    }

    if(root->data == data){
        return true;
    }

    bool res = find(root->left,data);
    if(res == true){
        return true;
    }
    res = find(root->right,data);
    if(res == true){
        return true;
    }

    return false;
}

vector<int>* n2rpath(Node* root,int dtf){
    if(root == NULL){
        return NULL;
    }

    if(root->data == dtf){
        vector<int>* bres=new vector<int>();
        bres->push_back(root->data);
        return bres;
    }

    vector<int>* lres = n2rpath(root->left,dtf);
    if(lres != NULL){
        lres->push_back(root->data);
        return lres;
    }
    vector<int>* rres = n2rpath(root->right,dtf);
    if(rres != NULL){
        rres->push_back(root->data);
        return rres;
    }


}

vector<Node*>* n2rpathModified(Node* root,int dtf){

    if(root == NULL){
        return NULL;
    }

    if(root->data == dtf){
        vector<Node*>* bres=new vector<Node*>();
        bres->push_back(root);
        return bres;
    }

    vector<Node*>* lres = n2rpathModified(root->left,dtf);
    if(lres != NULL){
        lres->push_back(root);
        return lres;
    }
    vector<Node*>* rres = n2rpathModified(root->right,dtf);
    if(rres != NULL){
        rres->push_back(root);
        return rres;
    }




}

void kDown(Node* root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
    }


    kDown(root->left,k-1);
    kDown(root->right,k-1);

}

void kDownModified(Node* root,int k,Node* reject){

     if(root == NULL || root == reject){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
    }


    kDownModified(root->left,k-1,reject);
    kDownModified(root->right,k-1,reject);

}

void kFar(Node* root,int data,int k){
    
    vector<Node*>* path = n2rpathModified(root,data);
    
    for(int i=0;i<path->size();i++){
        if(i == 0){
            kDownModified((*path)[i],k-i,NULL);
        }
        else{
            kDownModified((*path)[i],k-i,(*path)[i-1]);
        }
        
    }

}

void removeLeaves(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
        root->left = NULL;

    }
    if(root->right != NULL && root->right->left == NULL && root->right->right == NULL){
        root->right = NULL;

    }

    removeLeaves(root->left);
    removeLeaves(root->right);


}

Node* removeLeaves2(Node* root){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        return NULL;
    }

    root->left = removeLeaves2(root->left);
    root->right = removeLeaves2(root->right);

    return root;
}

void psc(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right!=NULL){
        cout << root->right->data << " ";
    }
    else if(root->left!= NULL && root->right == NULL){
        cout << root->left->data << " ";
    }

    psc(root->left);
    psc(root->right);
}

void rlp(Node* root,int low,int high,int sum,string res){
    if(root == NULL){
        if(sum>=low && sum<=high){
            cout << res << endl;
        }
        return;
    }

    rlp(root->left,low,high,sum+root->data,res+to_string(root->data)+" ");
    if(root->right!=NULL){
    rlp(root->right,low,high,sum+root->data,res+to_string(root->data)+" ");
    }
}

Node* construct1(vector<int>& pre,vector<int>& in,int preStart,int preEnd,int inStart,int inEnd){

    if(preStart>preEnd || inStart>inEnd){
        return NULL;
    }
    Node* nn = new Node(pre[preStart]);
    int i = 0;
    
     for(int ii=inStart;ii<=inEnd;ii++){
         if(in[ii] == pre[preStart]){
             break;
         }
         else
         i++;

     }

    nn->left = construct1(pre,in,preStart+1,preStart+i,inStart,inStart+i-1);
    nn->right = construct1(pre,in,preStart+i+1,preEnd,inStart+i+1,inEnd);

    return nn;
    
}

Node* construct2(vector<int>& post,vector<int>& in,int postStart,int postEnd,int inStart,int inEnd){
    if(postStart>postEnd || inStart>inEnd){
        return NULL;
    }
    Node* root = new Node(post[postEnd]);
    int lhs =0;
    for(int i = inStart;i<=inEnd;i++){
        if(post[postEnd] == in[i]){
            break;
        }
        else
        lhs++;
    }

    root->left = construct2(post,in,postStart,postStart+lhs-1,inStart,inStart+lhs-1);
    root->right = construct2(post,in,postStart+lhs,postEnd-1,inStart+lhs+1,inEnd);
    return root;
}

Node* construct3(vector<int>& pre,vector<int>& post,int preStart,int preEnd,int postStart,int postEnd){

    if(preStart>preEnd || postStart>postEnd){
        return NULL;
    }
    if(preStart == preEnd){
    Node* node = new Node(pre[preStart]);
    return node;
    }
    Node* root = new Node(pre[preStart]);
    int lhs = 0;
    for(int i =postStart;i<postEnd;i++){
        if(pre[preStart+1] == post[i]){ 
            break;
        }
        else
        lhs++;
    }

    root->left = construct3(pre,post,preStart+1,preStart+1+lhs,postStart,postStart+lhs);
    root->right = construct3(pre,post,preStart+lhs+2,preEnd,postStart+lhs+1,postEnd-1);
    return root;
}

Node* construct4(vector<int>& da,vector<int>& pa){
    Node* arr[100]{NULL};
    for(int i=0;i<da.size();i++){
        
        arr[da[i]] = new Node(da[i]);
    }
    Node* root = NULL;
    for(int i=0;i<pa.size();i++){
        if(pa[i] == -1){
            root = arr[da[i]];

        }
        else{
            Node* nn = arr[pa[i]];
            if(nn->left == NULL){
                nn->left = arr[da[i]];
            }
            else{
                nn->right = arr[da[i]];
            }
        }
    }

    return root;
}

int diameter1(Node* root){
    
    if(root == NULL){
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter1(root->left);
    int rdiameter = diameter1(root->right);

    return max((lheight+rheight+1),max(ldiameter,rdiameter));


}

class DiaHelper{
    public:
    int height = 0;
    int diameter = 0;
};

DiaHelper* diameter2(Node* root){
    if(root == NULL){
        DiaHelper* bres = new DiaHelper();
        bres->height = 0;
        bres->diameter = 0;
        return bres;
    }

    DiaHelper* left = diameter2(root->left);
    DiaHelper* right = diameter2(root->right);
    DiaHelper* mn = new DiaHelper();
    mn->diameter = max(left->height + right->height + 1 , max(left->diameter,right->diameter));
    mn->height = left->height + right->height + 1;
    return mn;
}

bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    bool lres = isBalanced(root->left);
    bool rres = isBalanced(root->right);
    
    int diff = lHeight - rHeight;
    if(diff>=-1 && diff<=1 && lres && rres){
        return true;
    }
    else
    return false;
}

class Pair{
    public:
    bool balance;
    int lHeight = 0;
    int rHeight = 0;
};
// not efficient
Pair* isBalanced2(Node* root){
    if(root == NULL){
        Pair* bPair = new Pair();
        bPair->balance = true;
        bPair->lHeight = 0;
        bPair->rHeight = 0;
        return bPair;
    }

    Pair* lPair = isBalanced2(root->left);
    Pair* rPair = isBalanced2(root->right);
    Pair* np = new Pair();
    int lh = max(lPair->lHeight,lPair->rHeight)+1;
    int rh = max(rPair->lHeight,lPair->rHeight)+1;
    int h = max(lh,rh)+1;
    np->balance = lPair->balance && rPair->balance && (h>=-1 && h<=1);
    np->lHeight = max(lPair->lHeight,lPair->rHeight)+1;
    np->rHeight = max(rPair->lHeight,rPair->rHeight)+1;
    return np;

}

// class Bst{
//     public:
//     bool isb;
//     int max;
//     int min;
// };

// Bst* isBst(Node* root){
//     if(root == NULL){
//         Bst* bres = new Bst();
//         bres->isb = true;
//         bres->max = INT_MIN;
//         bres->min = INT_MAX;
//         return bres;
//     }
    
//     Bst* lres = isBst(root->left);
//     Bst* rres = isBst(root->right);
//     Bst* nn = new Bst();
//     nn->isb = lres->isb && rres->isb && (root->data > lres->max && root->data < rres->min);
//     nn->max = max(root->data,max(lres->max,rres->max));
//     nn->min = min(root->data,min(lres->min,rres->min));
//     return nn;
// }

class Bst{
    public:
    bool isb;
    int min;
    int max;
    int size;
    Node* lbstroot;

};

Bst* largestBst(Node* root){
    if(root == NULL){
        Bst* bres = new Bst();
        bres->isb = true;
        bres->min = INT_MAX;
        bres->max = INT_MIN;
        bres->size = 0;
        bres->lbstroot = 0;
        return bres;
    }

    Bst* left = largestBst(root->left);
    Bst* right = largestBst(root->right);
    Bst* nn = new Bst();
    nn->isb = left->isb && right->isb && root->data > left->max && root->data < right->min;
    nn->min = min(root->data,min(left->min,right->min));
    nn->max = max(root->data,max(left->max,right->max));
    if(nn->isb){
        nn->lbstroot = root;
        nn->size = left->size + right->size + 1;

    }
    else{
        if(left->size > right->size){
            nn->lbstroot = left->lbstroot;
            nn->size = left->size;
        }
        else{
            nn->lbstroot = right->lbstroot;
            nn->size = right->size;
        }
    }
    return nn;
}









 
int main(int argc,char** argv){

    // vector<int> dlist{50,25,12,-1,37,30,-1,40,-1,-1,-1,75,62,60,-1,70,-1,-1,87,-1,-1,-1};
    // Node* root = construct(dlist);
    // display(root);
    // cout << size(root) << endl;
    // cout << max1(root) << endl;
    // cout << height(root) << endl;
    // cout << find(root,700) << endl;
    // vector<int>* result = n2rpath(root,87);
    // for(int i=0;i<result->size();i++){
    //     cout << (*result)[i] << " ";
    // }
    // cout << endl;
    // kDown(root,1);
    // cout << endl;
    vector<int> dlist2{1,2,4,-1,5,6,8,20,22,-1,-1,21,-1,-1,9,12,14,-1,15,18,-1,19,-1,-1,-1,13,-1,-1,-1,7,10,-1,11,16,-1,17,-1,-1,-1,-1,-1,3,-1,-1};
    Node* root2 = construct(dlist2);

    // kFar(root2,9,3);
    // cout << endl;
    // // removeLeaves(root2);
    // // display(root2);
    // psc(root2);
    // cout << endl;
    // rlp(root2,26,100,0,"");
    // Node* ans = removeLeaves2(root);
    // display(ans);

    vector<int> pre{50,25,12,10,37,30,75,62,87,90};
    vector<int> in{10,12,25,30,37,50,62,75,87,90};
    vector<int> post{10,12,30,37,25,62,90,87,75,50};
    Node* res = construct1(pre,in,0,pre.size()-1,0,in.size()-1);
    // display(res);
    // cout << endl;
    // Node* res1 = construct2(post,in,0,post.size()-1,0,in.size()-1);
    // display(res1);
    // cout << endl;
    // // vector<int> pre{50,25,12,37,75,62,60,70,87};
    // // vector<int> post{12,37,25,60,70,62,87,75,50};
    // // Node* res = construct3(pre,post,0,pre.size()-1,0,post.size()-1);
    // // display(res);
    // // cout << endl;
    vector<int> da{30,40,37,50,25,75,62,87,12};
    vector<int> pa{37,37,25,-1,50,50,75,75,25};
    Node* res1 = construct4(da,pa);
    // // // // display(res1);
    // // // cout << endl;
    // // // cout << diameter1(root2);
    // // // cout << endl;
    // // DiaHelper* res = diameter2(res1);
    // cout << res->diameter << endl;
    // cout << isBalanced(res) << endl;
    // Pair* res2 = isBalanced2(res);
    // int diff = res2->lHeight - res2->rHeight;
    // if(diff>=-1 && diff<=1 && res2->balance){
    //     cout << "true" << endl;
    // }
    // else
    // cout << "false" << endl;
    // vector<int> dList{50,25,12,-1,37,30,-1,40,-1,-1,-1,75,62,-1,87,-1,-1,-1};
    // Node* root = construct(dList);

    // Bst* res2 = isBst(root);
    // cout << res2->isb << endl;

    vector<int> dlist{50,25,12,10,-1,20,16,-1,22,-1,-1,-1,37,24,-1,40,-1,-1,-1,75,62,60,-1,-1,87,-1,-1,-1};
    Node* root = construct(dlist);

    Bst* largestbstres = largestBst(root);
    cout << largestbstres->lbstroot->data << " " << largestbstres->size << endl;

    

}