#include <iostream>
#include <stack>

using namespace std;

bool isParanthesesBalanced(string s){

    stack<char> stak;
    char x;

    for(int i=0;i<s.length();i++){

        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stak.push(s[i]);
            continue;
           }

        if(stak.empty())
            return false;

        switch(s[i]){

        case ')':
               x = stak.top();
               stak.pop();
               if(x=='{' || x=='['){
                return false;
               }
               break;
        case '}':
               x = stak.top();
               stak.pop();
               if(x=='(' || x=='['){
                return false;
               }
               break;
        case ']':
               x = stak.top();
               stak.pop();
               if(x=='(' || x=='['){
                return false;
               }
               break;
        }
    }

    return (stak.empty());

}

int main(){

string s;
cin >> s;

if(isParanthesesBalanced(s))
    cout << "Balanced" << endl;
else
    cout << "Not Balanced" << endl;

return 0;
}
