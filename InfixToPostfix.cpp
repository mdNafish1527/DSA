#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}


int main(){
    string str = "(7+9)*4/8-3";
    stack<string> val;
    stack<char> opr;

    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            val.push(to_string(str[i] - '0'));
        }
        else{
            if(opr.empty() || str[i] == '(' || opr.top() == '(') opr.push(str[i]);
            else if(str[i] == ')'){
                while(opr.top() != '('){
                    char ch = opr.top();
                    opr.pop();
                    string a = val.top();
                    val.pop();
                    string b = val.top();
                    val.pop();

                    string ans = "";
                    ans += b;
                    ans += a;
                    ans.push_back(ch);
                    val.push(ans);
                }
                opr.pop();
            }
            else if(priority(str[i]) > priority(opr.top())) opr.push(str[i]);
            else{
                while(opr.size() > 0 && priority(str[i]) <= priority(opr.top())){
                    char ch = opr.top();
                    opr.pop();
                    string a = val.top();
                    val.pop();
                    string b = val.top();
                    val.pop();

                    string ans = "";
                    ans += b;
                    ans += a;
                    ans.push_back(ch);
                    val.push(ans);
                }
                opr.push(str[i]);
            }
        }
    }


    while(opr.size() > 0){
        char ch = opr.top();
        opr.pop();
        string a = val.top();
        val.pop();
        string b = val.top();
        val.pop();

        string ans = "";
        ans += b;
        ans += a;
        ans.push_back(ch);
        val.push(ans);
    }

    cout << val.top() << endl;
    return 0;
}
