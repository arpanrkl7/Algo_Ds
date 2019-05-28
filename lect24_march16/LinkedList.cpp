#include<iostream>

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

};

int main(int argc,char** argv){
    LinkedList ll;
    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    ll.addLast(40);
    ll.addLast(50);
    ll.display();
    cout << endl;
    cout << ll.getFirst() << endl;
    cout << ll.getLast() << endl;
    ll.addFirst(99);
    ll.display();
    cout << (ll.getNodeAt(2))->data << endl;
    cout << ll.getAt(2) << endl;
    ll.addAt(25,3);
    ll.display();
    ll.removeFirst();
    ll.display();
    ll.removeLast();
    ll.display();
    ll.removeAt(2);
    ll.display();




}

