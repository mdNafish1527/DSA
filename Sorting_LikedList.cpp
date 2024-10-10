
#include <iostream>
using namespace std;

class Node{
public:
    int val;
    int rank;
    Node* next;

    Node(int val, int rank){
        this->val = val;
        this->rank = rank;
        this->next = NULL;
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

    void addHead(int val, int rank){
        Node* newNode = new Node(val, rank);
        if(size == 0){
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void Display(Node* head){
        Node* temp = head;
        while(temp){
            cout << "Value: " << temp->val << ", Rank: " << temp->rank << endl;
            temp = temp->next;
        }
        cout << "Size is " << size << endl << endl;
    }

    Node* merge(Node* a, Node* b){
        Node* final = new Node(-1, -1);
        Node* final_ans = final;
        while(a && b){
            if(a->rank <= b->rank){
                final->next = a;
                a = a->next;
            } else {
                final->next = b;
                b = b->next;
            }
            final = final->next;
        }

        // Attach the remaining nodes from either list
        if(a) final->next = a;
        if(b) final->next = b;

        return final_ans->next;
    }

    Node* sort(Node* c){
        if(c == NULL || c->next == NULL) return c;
        Node* slow = c;
        Node* fast = c;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* k1 = slow->next;
        Node* k2 = c;

        slow->next = NULL;
        k1 = sort(k1);
        k2 = sort(k2);
        return merge(k1, k2);
    }
};

int main(){
    LinkedList ll;
    ll.addHead(10, 4);
    ll.addHead(9, 5);
    ll.addHead(4, 2);
    ll.addHead(6, 3);
    ll.addHead(5, 1);
    
    cout << "Before Sorting:" << endl;
    ll.Display(ll.head);
    
    ll.head = ll.sort(ll.head);
    
    cout << "After Sorting:" << endl;
    ll.Display(ll.head);

    return 0;
}
