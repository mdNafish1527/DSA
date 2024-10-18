#include <iostream>
using namespace std;

class Stack{
private:
    int idx;
    int ar[5];

public:
    Stack(){
        idx = -1;
    }

    void push(int ele){
        if(idx == 4){
            cout << "Overflow" << endl;
            return;
        }
        idx++;
        ar[idx] = ele;
    }

    void pop(){
        if(idx == -1){
            cout << "Underflow" << endl;
            return;
        }
        idx--;
        return;
    }

    int top(){
        return ar[idx];
    }

    int size(){
        return idx + 1;
    }
};
