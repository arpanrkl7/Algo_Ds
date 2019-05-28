#include<iostream>
#include<string>
using namespace std;

class LinkedList{

    private:
    class Node{
        public:
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;
    Node* rdrLeft;
    int size;
    

    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    ~LinkedList(){
        Node* temp=head;
        for(int i=0;i<size;i++){
            head = head->next;
            delete temp;
            temp = head;
            size--;
        }
    }

    void addLast(int data){
        if(size == 0){
            Node* new1=new Node();
            new1->data=data;
            new1->next=NULL;
            head = tail = new1;
            size++;

        }
        else{
        Node* new1 = new Node();
        new1->data = data;
        new1->next = NULL;
        tail->next = new1;
        tail = new1;
        size++;
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

    void addFirst(int data){
        if(size == 0){
            Node* new1=new Node();
            new1->data=data;
            new1->next=NULL;
            head = tail = new1;
            size++;

        }
        else{
            Node* new1 = new Node();
            new1 -> data = data;
            new1 -> next = head;
            head = new1;
            size++;
        }
    }

    Node* getNodeAt(int idx){
        Node* temp=head;
        for(int i=0;i<idx;i++){
            temp=temp->next;
        }
        return temp;

    }

    void addAt(int data,int idx){
        Node* node=getNodeAt(idx-1);
        Node* new1=new Node();
        new1->data=data;
        new1->next=node->next;
        node->next=new1;
        size++;

    }

    int getFirst(){
        return head->data;
    }

    int getLast(){
        return tail->data;
    }

    int getAt(int idx){
        return getNodeAt(idx)->data;
    }

    int removeFirst(){
        Node* temp=head;
        int data=temp->data;
        head=head->next;
        delete temp;
        size--;
        return data;


    }

    int removeLast(){
        Node* first=head;
        Node* second=head->next;
        while(second->next != NULL){
            first=first->next;
            second=second->next;
        }
        first->next = NULL;
        int data=second->data;
        delete second;
        size--;
        return data;

    }

    int removeAt(int idx){
        Node* prev=getNodeAt(idx-1);
        Node* curr=prev->next;
        Node* next=prev->next->next;
        prev->next = next;
        int data=curr->data;
        delete curr;
        size--;
        return data;

    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        if(size == 0){
            return true;
        }
        else
        return false;
    }

    void rdi(){
        int sp=0;
        int ep=size-1;
        while(sp != ep){
            Node* x=getNodeAt(sp);
            Node* y=getNodeAt(ep);
            int temp=x->data;
            x->data = y->data;
            y->data = temp;
            sp++;
            ep--;
        }
    }

    void rpi(){

        Node* prev=NULL;
        Node* curr=head;
        Node* next=curr->next;
        while(next!=NULL){
            curr->next=prev;
            prev=curr;
            curr=next;
            next=curr->next;

        }
        curr->next = prev;
        head=curr;
    }

    void displayReverse(Node* head){
        if(head == NULL){
            return;
        }
        Node* temp=head;
        displayReverse(temp->next);
        cout << temp->data << " ";


    }

    void displayReverse(){
        Node* temp=head;
        displayReverse(temp);
        cout << endl;
    }

    void rpr(Node* head){
        if(head == tail){
            return;
        }
        Node* temp=head;
        rpr(temp->next);
        temp->next->next=temp;

    }

    void rpr(){
        Node* temp=head;
        rpr(temp);
    }

    void rdr(Node* head,int floor){
        if(head == NULL){
            return;
        }
        Node* temp=head;
        rdr(temp->next,floor+1);
        if(floor>=size/2){
        int x=rdrLeft->data;
        rdrLeft->data = temp->data;
        temp->data = x;
        rdrLeft=rdrLeft->next;
        }

    }

    void rdr(){
        Node* temp=head;
        rdrLeft = head;
        rdr(temp,0);
    }

    bool isPalindrome(Node* head,int floor){
        if(head == NULL){
            return true;
        }
        bool value=isPalindrome(head->next,floor+1);
        if(floor>=size/2){
    
            if(value == false){
                return false;
            }
            else if(head->data == rdrLeft->data){
                rdrLeft=rdrLeft->next;
            return true;
            }
            else{
            return false;
            }
        }
        else
        return value;

        
         


    }

    bool isPalindrome(){
        rdrLeft = head;
        isPalindrome(head,0);
    }

    void fold(Node* head,int floor){
        if(head == NULL){
            return;
        }

        Node* temp=head;
        fold(temp->next,floor+1);
        if(floor > size/2){
            temp->next = rdrLeft->next;
            rdrLeft->next = temp;
            rdrLeft= rdrLeft->next->next;
        }



    }

    void fold(){
        Node* temp = head;
        rdrLeft = head;
        fold(temp,0);
        rdrLeft->next = NULL;
    }

    // void unfold(Node* head){
    //     Node* temp=head;
    //     for(int i=0;i<size/2;i++){
    //         Node* first=temp;
    //         Node* second = first->next;
    //         Node* third=first->next->next;
    //         Node* last;
    //         if(i!=0){
    //         last=tail->next;
    //         }
    //         first->next=third;

    //         tail->next = second;
    //         if(i == 0){
    //             second->next = NULL;
    //         }
    //         else
    //         second->next = last;

    //         temp = third;


    //     }
    // }

    // void unfold(){
    //     Node* temp=head;
    //     unfold(temp);
    // }

    void unfold(Node* t1){
        if(t1->next == NULL){
            head = tail = t1;
            return;
        }
        else if(t1->next->next == NULL){
            head = t1;
            tail = t1->next;
        }
        Node* t2=t1->next;
        unfold(t1->next->next);
        t1->next = head;
        head = t1;
        tail -> next = t2;
        tail = t2;
        tail ->next = NULL;

    }

    void unfold(){
        Node* temp=head;
        unfold(temp);
    }


    // void removeDuplicates(Node* head){
    //     Node* temp=head;
    //     Node* temp1=head;
    //     while(temp1->next != NULL){
    //     while(temp1->next !=NULL && (temp1->next->data == temp1->data)){
    //         temp1=temp1->next;
    //     }
    //     temp->next = temp1->next;
    //     temp = temp1 = temp1->next;
    //     }
        
    //    temp->next = NULL;
    // }

    // void removeDuplicates(){
    //     Node* temp=head;
    //     removeDuplicates(temp);
    // }

    void clear(LinkedList* l){
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
    }

    void removeDuplicates(){
        LinkedList nl;

        while(this->size > 0){
            int temp = this->removeFirst();
            if(nl.size == 0 || nl.tail->data != temp){
                nl.addLast(temp);
            }
        }

        this->head = nl.head;
        this->tail = nl.tail;
        this->size = nl.size;

        clear(&nl);
    }
    void kReverse(){
        LinkedList temp;
        LinkedList acc;
        int k=3;
        while(this->size > 0){
            int cout=0;
            while(cout++ < k && this->size > 0){
                int curr=this->removeFirst();
                temp.addFirst(curr);
            }
            if(acc.size == 0){
                acc = temp;
                temp.head = NULL;
                temp.tail = NULL;
                temp.size = 0;
            }
            else{
                acc.tail->next = temp.head;
                acc.tail = temp.tail;
                acc.size=acc.size + temp.size;
                temp.head = NULL;
                temp.tail = NULL;
                temp.size = 0;
            }

        }
        this -> head = acc.head;
        this->tail = acc.tail;
        this->size = acc.size;
        clear(&temp);
        clear(&acc);

        
    }

    void oddEven(){
        LinkedList ol;
        LinkedList el;
        while(this -> size >0){
            int temp = this->removeFirst();
            if(temp%2==0){
                el.addLast(temp);
            }
            else{
                ol.addLast(temp);
            }
        }
        ol.tail->next = el.head;
        ol.tail = el.tail;
        el.head=ol.head;

        this->head = ol.head;
        this->tail = el.tail;
        this->size = ol.size + el.size;

       clear(&ol);
       clear(&el);

    }

    



    
};

int main(int argc,char** argv){
    LinkedList ll;
    ll.addLast(2);
    ll.addLast(7);
    ll.addLast(4);
    ll.addLast(9);
    ll.addLast(3);
   ll.addLast(18);

    // ll.addLast(70);
    ll.display();
    ll.addFirst(6);
    ll.display();
    // ll.addAt(40,3);
    ll.display();
    // cout << ll.getFirst() << endl;
    // cout << ll.getLast() << endl;
    // cout << ll.getAt(3) << endl;
    // // cout << ll.removeFirst() << endl;
    // // cout << ll.removeLast() << endl;
    // // ll.display();
    // // cout << ll.removeAt(3) << endl;
    // // ll.display();
    // cout << ll.getSize() << endl;
    // cout << ll.isEmpty() << endl;
    // ll.rdi();
    // ll.display();
    // ll.rpi();
    // ll.display();
    // ll.displayReverse();
    // ll.rpr();
    // ll.display();
    // ll.rdr();
    ll.display();
    cout << ll.isPalindrome() << endl;
    // ll.fold();
    // ll.display();
    // ll.unfold();
    // ll.display();
    // ll.unfold();
    // ll.display();
    // ll.removeDuplicates();
    // ll.display();
    // ll.oddEven();
    // ll.display();
    ll.kReverse();
    ll.display();


}