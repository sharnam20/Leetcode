class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if(t.length()<s.length()){
            return false;
        }
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
            }
            
        }
        if(mp.empty()){
            return true;
        }else{
        return false;}
    }
};