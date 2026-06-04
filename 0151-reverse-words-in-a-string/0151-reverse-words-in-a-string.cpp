class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        //we splite reverse string word in space 
        for(int i=0;i<s.length();i++){
            string word="";
            while(i<s.length() && s[i]!=' '){
               word=word+s[i];
               i++;
            }
            reverse(word.begin(),word.end());
            if(word.empty()){
                continue;
            }
             if (!ans.empty())
                ans += " ";

            ans += word;
        }
        return ans;
    }
};