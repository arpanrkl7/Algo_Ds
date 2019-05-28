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
        Node* temp=head;
        rdrLeft = head;
        isPalindrome(temp,0);
    }

    void fold(Node* head,int floor){
        if(head == NULL){
            return;
        }

        Node* temp=head;
        fold(temp->next,floor+1);
        if(floor >= size/2){
            temp->next = rdrLeft->next;
            rdrLeft->next = temp;
            rdrLeft= rdrLeft->next->next;
        }



    }

    void fold(){
        Node* temp = head;
        rdrLeft = head;
        fold(temp,0);
        // if(rdrLeft->next->next->next = rdrLeft){
        //     rdrLeft->next->next = NULL;
        // }
        // else
        tail = rdrLeft;
        rdrLeft->next = NULL;
    }

    // void unfold(Node* head){
    //     Node* temp=head;
    //     for(int i=0;i<size/2;i++){
    //         Node* first=temp;
    //         Node* second = first->next;
    //         Node* third=first->next->next;
    //         Node* last=tail->next;
    //         first->next=third;
    //         tail->next = second;
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
            return;

        }
        Node* t2=t1->next;
        unfold(t1->next->next);
        t1->next = head;
        head = t1;
        tail->next = t2;
        tail = t2;
        tail -> next = NULL;



    }

    void unfold(){
        Node* temp = head;
        rdrLeft = head;
        unfold(temp);
    }

    void clear(LinkedList* ml){
        ml->head = NULL;
        ml->tail = NULL;
        ml->size = 0;
    }

    void removeDuplicates(){
        LinkedList ml;
        while(this->size!=0){
        int first=this->removeFirst();
        if(ml.size == 0 || first != ml.tail->data){
            ml.addLast(first);
        }
        }
        this->head = ml.head;
        this->tail = ml.tail;
        this->size = ml.size;

        clear(&ml);
        
    }

    void oddEven(){
        LinkedList ol;
        LinkedList el;

        while(this->size > 0){
            int first = this->removeFirst();
            if(first % 2 == 0){
                el.addLast(first);
            }
            else
            ol.addLast(first);
        }
        if(ol.size == 0){
        this->head = el.head;
        this->tail = el.tail;
        this->size = el.size;

        }
        else if(el.size == 0){
        this->head = ol.head;
        this->tail = ol.tail;
        this->size = ol.size;
        }
        else{
        ol.tail->next=el.head;
        ol.tail = el.tail;

        this->head = ol.head;
        this->tail = ol.tail;
        this->size = ol.size + el.size;
        }
        
        clear(&ol);
        clear(&el);
    }

    void kReverse(){
        LinkedList temp;
        LinkedList acc;
        while(this->size >0){
            int k=3;
            while(k-->0 && this->size >0){
                int first = this->removeFirst();
                temp.addFirst(first);

            }
            if(acc.size == 0){
                acc = temp;
            }
            else{
                acc.tail->next = temp.head;
                acc.tail = temp.tail;
                acc.size+=temp.size;
            }
            temp.head = NULL;
            temp.tail = NULL;
            temp.size = 0;
        }
        this->head = acc.head;
        this->tail = acc.tail;
        this->size = acc.size;

       // clear(&temp);
        clear(&acc);
    }

    int kthFromLast(int k){

        Node* slow=head;
        Node* fast=head;

        for(int i=0;i<k-1;i++){
            fast = fast->next;
        }
        while(fast->next !=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        return slow->data;
    }

    Node* midNode(Node* sp,Node* ep){

        Node* slow = sp;
        Node* fast = sp;

        while(fast->next!=ep && fast!=ep){
            slow=slow->next;
            fast = fast->next->next;
        }

        return slow;

    }

    int midElement(){
        // Node* first=head;
        // Node* last=tail;
        Node* res=midNode(this->head,this->tail);
        return res->data;

    }

    void mergeTwoSortedList(LinkedList& ll1,LinkedList& ll2){
        Node* flist=ll1.head;
        Node* slist=ll2.head;

        while(flist != NULL && slist!=NULL){
        if(flist->data < slist->data){
            this->addLast(flist->data);
            flist=flist->next;
        }
        else if(flist->data > slist->data){
            this->addLast(slist->data);
            slist=slist->next;
        }

        else{
            this->addLast(flist->data);
            this->addLast(slist->data);
            slist=slist->next;
            flist=flist->next;

        }
        }

        while(flist!=NULL){
            this->addLast(flist->data);
            flist=flist->next;
        }

        while(slist!=NULL){
            this->addLast(slist->data);
            slist = slist->next;
        }

    }

    LinkedList* mergeSort(Node* sp,Node* ep){

        if(sp == ep){
            LinkedList* mlist=new LinkedList();
            mlist->addLast(sp->data);
            return mlist;
        }

        Node* mid=midNode(sp,ep);
        LinkedList* fshalf=mergeSort(sp,mid);
        LinkedList* shalf=mergeSort(mid->next,ep);
        LinkedList* mr=new LinkedList();
        mr->mergeTwoSortedList(*fshalf,*shalf);
        return mr;



    }

    LinkedList* mergeSort(){
        LinkedList* mres=mergeSort(this->head,this->tail);
        return mres;

    }
};

int main(int argc,char** argv){
    LinkedList ll;
    ll.addLast(20);
    ll.addLast(30);
    ll.addLast(40);
    ll.addLast(50);
    ll.addLast(60);
    ll.addLast(70);
    ll.display();
    ll.addFirst(10);
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
    ll.fold();
    // ll.addLast(-60);
    ll.display();
    ll.unfold();
    // ll.addFirst(-20);
    // ll.addLast(-60);
    ll.display();
    ll.removeDuplicates();
    // ll.addLast(70);
    ll.display();
    ll.oddEven();
    ll.display();
    ll.kReverse();
    ll.display();

    cout << ll.kthFromLast(7) << endl;
    cout << ll.midElement() << endl;

    LinkedList ll1,ll2;
    ll1.addLast(10);
    ll1.addLast(20);
    ll1.addLast(30);
    ll1.addLast(40);
    ll1.addLast(50);

    ll2.addLast(5);
    ll2.addLast(7);
    ll2.addLast(9);
    ll2.addLast(11);
    ll2.addLast(25);
    ll2.addLast(28);

    LinkedList ll3;
    ll3.mergeTwoSortedList(ll1,ll2);
    ll3.display();

    LinkedList ll4;
    ll4.addLast(77);
    ll4.addLast(67);
    ll4.addLast(87);
    ll4.addLast(97);
    ll4.addLast(17);
    LinkedList* result=ll4.mergeSort();
    result->display();



}