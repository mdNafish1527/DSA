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


int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    a.next = &b;
    b.next = &c;
    c.next = &d;


    Node temp = a;
    while(true){
        cout << temp.val << " ";
        if(temp.next == NULL) break;
        temp = *(temp.next);
    }
    return 0;
}
















// #include <iostream>
// using namespace std;

// class Node{
// public:
//     int val;
//     Node* next;

//     Node(int val){
//          this -> val = val;
//          this -> next = NULL;
//     }
// };


// int main(){
//     // 10 20 30 40
//     // Node a;
//     // a.val = 10;
//     // a.next = &b;

//     // Node b;
//     // b.val = 20;
//     // b.next = &c;

//     // Node c;
//     // c.val = 30;
//     // c.next = &d;

//     // Node d;
//     // d.val = 40;
//     // d.next = NULL;

//     Node a(10);
//     Node b(20);
//     Node c(30);
//     Node d(40);

//     a.next = &b;
//     b.next = &c;
//     c.next = &d;
//     d.next = NULL;

//     //cout << (a.next) -> val;
//     //cout << (*(a.next)).val << endl;
//     // cout << c.val << endl;
//     // cout << ((a.next) -> next) -> val << endl;

//     cout << d.val << endl;
//     cout << (a.next) -> next -> next -> val;



//     // cout << &a << endl;
//     // cout << a.val << endl;
//     // cout << a.next << endl;


//     return 0;
// }
