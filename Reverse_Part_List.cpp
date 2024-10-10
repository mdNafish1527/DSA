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


class LinkedList{
public:
    Node* head;
    int size;

    LinkedList(){
        head = NULL;
        size = 0;
    }

    void addHead(int val){
        Node* newNode = new Node(val);
        if(size == 0){
            head = newNode;
            size++;
        }
        else{
            newNode -> next = head;
            head = newNode;
            size++;
        }
        return;
    }

    void Display(Node* head){
        Node* temp = head;
        while(temp){
            cout << temp -> val << "  ";
            temp = temp -> next;
        }
        cout << endl << endl << endl;
        return;
    }

    Node* rev(Node* head){
        if(head == NULL || head -> next == NULL) return head;
        Node* newhead = rev(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return newhead;
    }

    void revSize(int left,int right){
        if(left == right) return;
        Node* a = NULL,*b = NULL,*c = NULL,*d = NULL,*temp = head;
        int count = 1;

        while(temp){
            if(count == left - 1) a = temp;
            if(count == left) b = temp;
            if(count == right) c = temp;
            if(count == right + 1) d = temp;
            count++;
            temp = temp -> next;
        }

        if(a) a -> next = NULL;
        c -> next = NULL;
        c = rev(b);
        if(a) a -> next = c;
        b -> next = d;
        if(a) head = a;
        else head = c;
        return;
    }
};

int main(){
    LinkedList ll;
    ll.addHead(4);
    ll.addHead(3);
    ll.addHead(2);
    ll.addHead(1);
    ll.addHead(5);
    ll.addHead(6);

    ll.Display(ll.head);
    ll.revSize(2,5);
    ll.Display(ll.head);

    return 0;
}
