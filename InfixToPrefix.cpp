#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2;
}


int main(){
    string str = "2+6*4/8-3";
    stack<string> val;
    stack<char> opr;

    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            val.push(to_string(str[i]));
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
                    ans.push_back(ch);
                    ans += b;
                    ans += a;
                    val.push(ans);
                }
                opr.pop();
            }
            else{
                if(priority(str[i]) > priority(opr.top())){
                    opr.push(str[i]);
                }
                else{
                    while(opr.size() && priority(opr.top()) >= priority(str[i])){
                        char ch = opr.top();
                        opr.pop();
                        string ans = "";
                        string a = val.top();
                        val.pop();
                        string b = val.top();
                        val.pop();
                        ans.push_back(ch);
                        ans += b;
                        ans += a;
                        val.push(ans);
                    }
                    opr.push(str[i]);
                }
            }
        }
    }

    while(!opr.empty()){
        char ch = opr.top();
        opr.pop();
        string ans = "";
        string a = val.top();
        val.pop();
        string b = val.top();
        val.pop();
        ans.push_back(ch);
        ans += b;
        ans += a;
        val.push(ans);
    }

    cout << val.top() << endl;
    return 0;
}
