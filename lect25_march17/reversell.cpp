#include<iostream>
#include<string>

using namespace std;




class LinkedList{

    private:
    class Node{
        private:
        public:
        int data;
        Node* next;
    };
    int size;
    Node* head;
    Node* tail;
    Node* rdrLeft;

    void displayReverse(Node* node){
        if(node == NULL){
            return;
        }

        displayReverse(node->next);
        cout << node->data << "->";
    }

    void rpr(Node* node){
        if(node == tail){
            return;
        }
        rpr(node->next);
        node->next->next=node;
        
    }

    void rdr(Node* node,int floor){
        if(node == NULL){
            return;
        }

       
        rdr(node->next,floor+1);
        if(floor>=size/2){

        int temp=node->data;
        node->data=rdrLeft->data;
        rdrLeft->data=temp;
        rdrLeft=rdrLeft->next;

        }
        

        



    }

    bool isPalindrome(Node* node,int floor){
        if(node == NULL){
            return false; 
        }

        isPalindrome(node->next,floor+1);
        if(floor>=size/2){
        if(node->data != rdrLeft->data){
            return false;
        }
        else{
            int temp=node->data;
        node->data=rdrLeft->data;
        rdrLeft->data=temp;
        rdrLeft=rdrLeft->next;

        }
        }
                return true;



    }

    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    ~LinkedList(){
        Node* t=head;
        for(int i=0;i<size;i++){
            head = head->next;
            delete t;
            t=head;
        }
    }
    void display(){
        Node* temp=head;
        for(int i=0;i<size;i++){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void addFirst(int data){
        Node* temp=new Node();
        temp ->data=data;
        temp->next=head;
        head=temp;
        size++;
    }
    void handleCase(int data){
        Node* temp = new Node();
        temp->data=data;
        temp->next=NULL;
        head=tail=temp;
        size++; 
    }
    void addLast(int data){

        if(size == 0){
            handleCase(data);
        }
        else{
        //space
        Node* nn = new Node();
        
        //data and next
        nn->data = data;
        nn->next=NULL;
        //connect
        tail->next = nn;
        //summary
        tail = nn;
        size++;
        }
    }
    void addAt(int data,int idx){
        Node* previous=getNodeAt(idx-1);
        Node* next1=getNodeAt(idx);
        Node* temp=new Node();
        temp->data=data;
        previous->next=temp;
        temp->next=next1;
        size++;
    }
    int getFirst(){
        if(size == 0){
            return -1;
        }
        else
        return head->data;
    }
    int getLast(){
        if(size == 0){
            return -1;
        }
        else
        return tail->data;
    }
    int getAt(int idx){
        Node* temp;
        temp=getNodeAt(idx);
        return temp->data;

    }
    Node* getNodeAt(int idx){
        Node* temp=head;
        for(int i=0;i<idx;i++){
            temp = temp->next;
        }
        return temp;

    }
    int removeFirst(){
        Node* temp=head;
        head=head->next;
        delete temp;
        size--;
    }
    int removeLast(){
        Node* prev=head;
        Node* temp=head->next;
        while(temp->next !=NULL){
            prev=prev->next;
            temp=temp->next;
        }
        prev->next=NULL;
        delete temp;
        size--;
    }
    int removeAt(int idx){
        if(idx < 0 || idx>=size){
            return -1;
        }
        else if(idx ==0){
            removeFirst();
        }
        else if(idx == size-1){
            removeLast();
        }
        else{
            Node* previous=getNodeAt(idx-1);
            Node* current=previous->next;
            Node* next1=current->next;
           
           int temp=current->data;
           delete current;
            previous->next=next1;
            size--;
            
            
            return temp;


        }
    }
    
    void reverse(){
        int fp=0;
        int lp=getSize()-1;
    
    while(fp != lp){

        Node* first=getNodeAt(fp);
    Node* last=getNodeAt(lp);
        int temp=first->data;
        first->data=last->data;
        last->data=temp;
        fp++;
        lp--;
    }
    }

    void rpi(){

        Node* prev=NULL;
        Node* curr=head;
        Node* next=curr->next;

        while(curr!=NULL){
            curr->next=prev;
           // next->next=curr;
            prev=curr;
            curr=next;
            if(next!=NULL){
            next=next->next;
            }
        }
        Node* temp=head;
        head=tail;
        tail=temp;
    }

    void displayReverse(){
        Node* curr=head;
        displayReverse(curr);
        cout << endl;
    }

    void rpr(){
        Node* curr=head;
        rpr(curr);
        Node* temp=head;
        head=tail;
        tail=temp;
        tail->next=NULL;
    }

    void rdr(){
        rdrLeft=head;
        rdr(head,0);
    }

    bool isPalindrome(){
        rdrLeft=head;
       return isPalindrome(head,0);
    }


    

};






int main(int argc,char** argv){

    LinkedList ll;
    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    ll.addLast(40);
    ll.addLast(50);
    ll.display();
    ll.reverse();
    ll.display();
    ll.rpi();
    ll.display();
    ll.displayReverse();
    ll.rpr();
    ll.display();
    ll.rdr();
    ll.display();
   cout <<  ll.isPalindrome() << endl;


}

