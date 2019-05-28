#include<iostream>
#include<string>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void display(Node* node){
    for(Node* temp=node;temp != NULL;temp = temp->next){
        cout << temp->data << " ";
    }
    cout << endl;

}

void rLoop(Node* slow,Node* fast){

    Node* temp=fast;
    while(slow != fast){
        slow = slow->next;
        temp = fast;
        fast = fast->next;
    }
    temp->next = NULL;


}

bool darLoop(Node* node){
    Node* slow=node;
    Node* fast=node;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            rLoop(node,fast);
            return true;
        }

    }
    return false;

}

int main(int argc,char** argv){

    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);
    Node n6(60);
    Node n7(70);
    Node n8(80);
    Node n9(90);
    Node n10(100);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    n9.next = &n10;
    n10.next = &n5;

    bool loop = darLoop(&n1);
    cout << loop << endl;
    display(&n1);

}

