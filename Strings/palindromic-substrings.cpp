https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0,start,end;
        for(int i=0;i<s.size();i++){
            start = i-1;
            end = i+1;
            while(start>=0 && end<s.size() && s[start]==s[end]){
            count++;
            start--;
            end++;
            }
            start = i;
            end = i+1;
            while(start>=0 && end<s.size() && s[start]==s[end]){
            count++;
            start--;
            end++;
            }
        }
        count += s.size();
        return count;
    }
};