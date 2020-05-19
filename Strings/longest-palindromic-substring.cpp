//https://leetcode.com/problems/longest-palindromic-substring/


class Solution {
public:
    string longestPalindrome(string s) {
         int start,end;
         string maxSO = ""; string maxSE="";
         int maxLO = 0,maxLE=0;
        for(int i=0;i<s.size();i++){
            start = i;
            end = i;
            while(start>=0 && end<s.size() && s[start]==s[end]){
            string stro = s.substr(start,end-start+1);
            if(stro.length()>maxLO){
                maxSO = stro;
                maxLO = stro.length();
            }
            start--;
            end++;
            }
            start = i;
            end = i+1;
            while(start>=0 && end<s.size() && s[start]==s[end]){
            string stre = s.substr(start,end-start+1);
            if(stre.length()>maxLE){
                maxSE = stre;
                maxLE = stre.length();
            }
            start--;
            end++;
            }
        }
        if(maxLE>maxLO)
            return maxSE;
        return maxSO;
    }
};