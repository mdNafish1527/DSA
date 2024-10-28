#include <iostream>
#include <stack>
using namespace std;

int priority(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else return 0;
}

int solve(int val1, char oper, int val2){
    if(oper == '+') return val1 + val2;
    else if(oper == '-') return val1 - val2;
    else if(oper == '*') return val1 * val2;
    else return val1 / val2;
}

int main(){
    string str = "2+6*4/8-3";

    stack<int> val;
    stack<char> kaam;

    for(int i = 0; i < str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            val.push((int) str[i] - '0');
        }
        else{
            if(kaam.empty() == true) kaam.push(str[i]);
            else if(priority(str[i]) > priority(kaam.top())) kaam.push(str[i]);
            else {
                while(!kaam.empty() && priority(str[i]) <= priority(kaam.top())){
                    char ch2 = kaam.top();
                    kaam.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, ch2, val2);
                    val.push(ans);
                }
                kaam.push(str[i]);
            }
        }
    }

    while(!kaam.empty()){
        char ch2 = kaam.top();
        kaam.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, ch2, val2);
        val.push(ans);
    }

    cout << val.top() << endl;

    return 0;
}
