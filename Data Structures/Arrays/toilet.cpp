#include <iostream>
#include <string>

using namespace std;

int main(){

    string s;
    cin >> s;
    int cnt1=0,cnt2=0,cnt3=0;
    if(s[0]==s[1] && s[0]=='U'){
        cnt1 = 0;
        cnt2 = 1;
        cnt3 = 0;
    }
    if(s[0]==s[1] && s[0]=='D'){
        cnt1 = 1;
        cnt2 = 0;
        cnt3 = 0;
    }
    if(s[0]=='U' && s[1]=='D'){
        cnt1 = 2;
        cnt2 = 1;
        cnt3 = 1;
    }
    if(s[0]=='D' && s[1] == 'U'){
        cnt1 = 1;
        cnt2 = 2;
        cnt3 = 1;
    }

    int a=0,b=0,c=0;

    for(int i=2;i<s.length();i++){
        
        if(s[i]=='U')
            a++;
        if(s[i]=='D')
            b++;
        if(s[i]!=s[i-1])
            c++;
    }
    
    cout << cnt1 + (2*b) << endl;
    cout << cnt2 + (2*a) << endl;
    cout << cnt3 + c << endl;

    return 0;
}