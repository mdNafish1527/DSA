#include <iostream>
#include <stack>
using namespace std;


int main(){
    stack <int> st;
    stack <int> rt;
    // cout << st.size() << endl;
    // st.push(10);
    // cout << st.size() << endl;
    // st.push(20);
    // cout << st.size() << endl;
    // st.push(30);
    // cout << st.size() << endl;
    // st.pop();
    // cout << st.size() << endl;
    // cout << st.top() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    while(st.size() != 0){
        cout << st.top() << endl;
        rt.push(st.top());
        st.pop();
    }
    return 0;
}
