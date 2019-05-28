#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<list>
using namespace std;

class Node
{   public:
    int data;
    vector<Node*> children;
    Node(int data){
        this->data = data;
    }
};

Node* construct(vector<int>& dlist){
    Node* root;
    vector<Node*> mlist;
    for(int i=0;i<dlist.size();i++){
        if(dlist[i] == -1){
            mlist.pop_back();
        }
        else{
            Node* mn = new Node(dlist[i]);
            if(mlist.size() == 0){
                root = mn;
            }
            else{
                Node* top=mlist.back();
                top->children.push_back(mn);
            }
            mlist.push_back(mn);


        }

    }
    return root;
}

void display(Node* root){

    cout << root->data << "-> ";
    for(int i=0;i<root->children.size();i++){
        cout << root->children[i]->data << ",";
    }
    cout << ".";
    cout << endl;
    for(int i=0;i<root->children.size();i++){
        display(root->children[i]);
    }

}

int size(Node* root){

    int sizeTillNow = 0;
    for(int i=0;i<root->children.size();i++){
        sizeTillNow+=size(root->children[i]);
    }
    return sizeTillNow+1;
}

int max(Node* root){

    int maxTillnow=root->data;
    for(int i=0;i<root->children.size();i++){
        int currentMax=max(root->children[i]);
        if(currentMax>maxTillnow){
            maxTillnow = currentMax;
        }
    }
    return maxTillnow;

}

int height(Node* root){

    int globalHeight=0;
    for(int i=0;i<root->children.size();i++){
        int currentHeight = height(root->children[i]);
        if(currentHeight>globalHeight){
            globalHeight = currentHeight;
        }


    }
    return globalHeight+1;
}

bool find(Node* root,int dtf){

    if(root->data == dtf){
        return true;
    }

    for(int i=0;i<root->children.size();i++){
        bool locResult=find(root->children[i],dtf);
        if(locResult == true){
            return true;
        }
    }
    return false;
}

vector<int>* n2rpath(Node* root,int dtf){
    if(root->data == dtf){
        vector<int>* mres = new vector<int>();
        mres->push_back(root->data);
        return mres;
    }

    for(int i=0;i<root->children.size();i++){
        vector<int>* locResult = n2rpath(root->children[i], dtf);
        if(locResult != NULL){
            locResult->push_back(root->data);
            return locResult;
        }

    }
}

int lca(Node* root,int d1,int d2){

    vector<int>* path1=n2rpath(root,d1);
    vector<int>* path2=n2rpath(root,d2);

    int i=path1->size() - 1;
    int j=path2->size() - 1;
    int temp;
    while(i>=0 && j>=0 && (*path1)[i] == (*path2)[j]){
        temp=(*path1)[i];
        i--;
        j--;

    }
    return temp;
}

int distance(Node* root,int d1,int d2){

    vector<int>* path1=n2rpath(root,d1);
    vector<int>* path2=n2rpath(root,d2);

    int i = path1->size()-1;
    int j = path2->size()-1;

    while(i>=0 && j>=0 && (*path1)[i] == (*path2)[j]){
        i--;
        j--;
    }
    return i+j+2+1;


}

void mirror(Node* root){
    if(root->children.size()>0){
    int left = 0;
    int right = root->children.size()-1;
    while(left<right){
    Node* temp = root->children[left];
    root->children[left] = root->children[right];
    root->children[right] = temp;
    left++;
    right--;
    }
    }

    for(int i=0;i<root->children.size();i++){
        mirror(root->children[i]);
    }
}

void ceilnfloor(Node* root,int& sz,int& ht,int& mn,int& mx,int& ceil,int& floor,int data,int depth){
    sz++;
    ht=depth>ht?depth:ht;
    mn=root->data<mn?root->data:mn;
    mx=root->data>mx?root->data:mx;
    ceil=root->data > data && root->data<ceil ? root->data : ceil;
    floor=root->data < data && root->data>floor ? root->data : floor;

    for(int i=0;i<root->children.size();i++){
        ceilnfloor(root->children[i],sz,ht,mn,mx,ceil,floor,data,depth+1);
    }


}

void predessornsuccessor(Node* root,int& predessor,int& status,int& succesor,int& data1){
    // good trick
    if(status == 0){
        if(root->data != data1){
            predessor = root->data;
        }
        else{
            status = 1;
        }
    }
    else if(status == 1){
            succesor = root->data;
            status++;
        }
    


    for(int i=0;i<root->children.size();i++){
        predessornsuccessor(root->children[i],predessor,status,succesor,data1);
    }
}

void predessornsuccesor2ndStyle(Node* root,int key,int& prev,int& curr,int& pred,int& succ){

    
    prev = curr;
    curr = root->data;
    if(curr == key)
    {
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

    floor=root->data < data && root->data>floor ? root->data : floor;

    for(int i=0;i<root->children.size();i++){
        floorkthLargest(root->children[i],floor,data);
    }

}

int kthLargest(Node* root, int k)
{
    int data = INT_MAX;
    int myFloor1 = INT_MIN;
    for(int i=0;i<k;i++){
    floorkthLargest(root,myFloor1,data);
    data = myFloor1;
    myFloor1 = INT_MIN;
    }
    return data;

}

void levelOrder(Node* root){

    list<Node*> myList;
    myList.push_back(root);
    while(myList.size() > 0){
        Node* node = myList.front();
        myList.pop_front();
        cout << node->data << " ";

        for(int i=0;i<node->children.size();i++){
            myList.push_back(node->children[i]);
        }

    }
    cout << endl;
}

void levelOrderlw(Node* root){

    list<Node*>* queue1 = new list<Node*>();
    list<Node*>* queue2 = new list<Node*>();
    queue1->push_back(root);
    while(queue1->size() >0){
        Node* get=queue1->front();
        queue1->pop_front();
        cout << get->data << " ";

        for(int i=0;i<get->children.size();i++){
            queue2->push_back(get->children[i]);
        }

        if(queue1->size() == 0){
            delete queue1;
            queue1 = queue2;
            queue2 = new list<Node*>();
            cout << endl;
        }
    }

    delete queue1;
    delete queue2;
    

}

void levelOrderZigZag(Node* root){

    list<Node*>* queue1 =  new list<Node*>();
    list<Node*>* stack = new list<Node*>();
    queue1->push_back(root);
    bool ltr = true;

    while(queue1->size() > 0){
        Node* get = queue1->front();
        queue1->pop_front();
        cout << get->data << " ";
        if(ltr){
        for(int i=0;i<get->children.size();i++){

                stack->push_front(get->children[i]);
            
        }
        }
        else{
            for(int i=get->children.size()-1;i>=0;i--){

                stack->push_front(get->children[i]);
            
        }

        }
        if(queue1->size() == 0){
        ltr = !ltr;
        delete queue1;
        queue1 = stack;
        stack = new list<Node*>();
        cout << endl;
        }
    }

    delete queue1;
    delete stack;
}

class EHelper{
    public:
    Node* node;
    int state;

    EHelper(Node* node,int state){
        this->node = node;
        this->state = state;
    }
};

void EulerPrint(Node* root){

    list<EHelper*>* stack = new list<EHelper*>();
    EHelper* node = new EHelper(root,0);
    stack->push_back(node);

    while(stack->size() > 0){

        EHelper* base = stack->back();

        if(base->state == 0){
            cout << base->node->data << " " << "pre" << endl;
            base->state++;
        }
        else if(base->state >=1 && base->state<=base->node->children.size()){
            if(base->state == 1){
            EHelper* node1 = new EHelper(base->node->children[base->state-1],0);
            stack->push_back(node1);
            base->state++;
            }
            else if(base->state>=2){
                cout << base->node->data << " " << "in" << to_string(base->state-1) << endl;
                EHelper* node1 = new EHelper(base->node->children[base->state-1],0);
                stack->push_back(node1);
                base->state++;
            }


        }
        else if(base->state == base->node->children.size()+1){
            cout << base->node->data << " " << "post" << endl;
            base->state++;

        }
        else{
            stack->pop_back();


        }
    }



}

class KpcNode{
    public:
    string ques;
    string ans;
    KpcNode(string ques,string ans){
        this->ques = ques;
        this->ans = ans;
    }
};

void kpcPrint(string ques){
    string arr[]{"","abc","def","ghi","jk","lmno"};
    list<KpcNode*> queue;;
    KpcNode* nn = new KpcNode(ques,"");
    queue.push_back(nn);


    while(queue.size()>0){
        KpcNode* cn = queue.front();
        queue.pop_front();
        if(cn->ques.size() == 0){
            cout << cn->ans << endl;
        }
        else{
        string q = arr[cn->ques[0]-48];
        for(int i=0;i<q.size();i++){
            string newques = cn->ques.substr(1);
            string newans = cn->ans+q[i];
            KpcNode* kpc = new KpcNode(newques,newans);
            queue.push_back(kpc);
        }
        }

    }

}

int main(int argc,char** argv){
        vector<int> dList{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
        Node* root = construct(dList);
        display(root);
        cout << size(root) << endl;
        cout << max(root) << endl;
        cout << height(root) << endl;
        cout << find(root,110) << endl;
        vector<int>* result = n2rpath(root,110);
        for(int i=0;i<result->size();i++){
            cout << (*result)[i] << " ";
        }
        cout << endl;
        cout << lca(root,70,120) << endl;
        cout << distance(root,50,60) << endl;
       // mirror(root);
        display(root);
        int sz=0;
        int ht=0;
        int mn=INT_MAX;
        int mx=INT_MIN;
        int myCeil=INT_MAX;
        int myFloor=INT_MIN;
        ceilnfloor(root,sz,ht,mn,mx,myCeil,myFloor,35,0);
        cout << sz << " " << ht << " " << mn << " " << mx << endl;
        cout << myCeil << " " << myFloor << " " << endl;
        int predessor = 0;
        int succesor = 0;
        int status = 0;
        int data1=90;
        predessornsuccessor(root,predessor,status,succesor,data1);
        cout << predessor << " " << succesor << endl;
        int prev = 0;
        int curr = 0;
        predessornsuccesor2ndStyle(root,data1,prev,curr,predessor,succesor);
        cout << predessor << " " << succesor << endl;
        cout << kthLargest(root,5) << endl;

        levelOrder(root);
        levelOrderlw(root);
        levelOrderZigZag(root);
        EulerPrint(root);
        cout << endl;
        kpcPrint("543");
}