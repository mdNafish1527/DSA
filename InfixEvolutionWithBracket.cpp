#include <iostream>
#include <stack>
using namespace std;

int prio(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}

int solve(int val1,char ch,int val2){
    if(ch == '+') return val1 + val2;
    else if(ch == '-') return val1 - val2;
    else if(ch == '*') return val1 * val2;
    else return val1 / val2;
}

int main(){
    cout << (7+9)*4/8-3 << endl;
    stack<int> val;
    stack<char> opr;
    string str = "(7+9)*4/8-3";

    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] >= '0' && str[i] <= '9') val.push((int)(str[i] - '0'));
        else{
            if(opr.empty() || str[i] == '(' || opr.top() == '(') opr.push(str[i]);
            else if(str[i] ==')'){
                while(opr.top() != '('){
                    char ch = opr.top();
                    opr.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,ch,val2);
                    val.push(ans);
                }
                opr.pop();
            }
            else if(prio(str[i]) > prio(opr.top())) opr.push(str[i]);
            else{
                while(opr.empty() == false && prio(opr.top()) >= prio(str[i])){
                    char ch = opr.top();
                    opr.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,ch,val2);
                    val.push(ans);
                }
                opr.push(str[i]);
            }
        }
    }

    while(opr.size() > 0){
        char ch = opr.top();
        opr.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1,ch,val2);
        val.push(ans);
    }

    cout << val.top() << endl;
    return 0;
}
