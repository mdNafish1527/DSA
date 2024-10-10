#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this -> val = val;
        this -> next = NULL;
    }
};


Node* makeRev(Node* head){
    if(head == NULL || head -> next == NULL) return head;
    Node* newHead = makeRev(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;


    // if(head == NULL || head -> next == NULL) return head;
    // Node* newHead = makeRev(head -> next);
    // head -> next -> next = head;
    // head -> next = NULL;
    // return newHead;
    // if(head == NULL || head -> next == NULL) return head;
    // Node* ans = makeRev(head -> next);
    // head -> next -> next = head;
    // head -> next = NULL;
    // return ans;
}


void Display(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
    return;
}

void DisplayRev(Node* head){
    if(head == NULL) return;
    DisplayRev(head -> next);
    cout << head -> val << " ";
}

Node* makeRevit(Node* head){
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* agla = cur -> next;
        cur -> next = prev;
        //agla -> next = cur;
        prev = cur;
        cur = agla;
    }
    return prev;
}


int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = e;

    //Display(a);

    // Node* f = makeRev(a);
    // Display(f);
    // DisplayRev(f);
    Node* g = makeRevit(a);
    Display(g);
    return 0;
}
