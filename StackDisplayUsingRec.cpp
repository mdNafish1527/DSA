#include <iostream>
#include <stack>
using namespace std;

void Display(stack<int>& s){
    if(s.size() == 0) return;
    cout << s.top() << endl;
    s.pop();
    Display(s);
}


int main(){
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    Display(s);
 
