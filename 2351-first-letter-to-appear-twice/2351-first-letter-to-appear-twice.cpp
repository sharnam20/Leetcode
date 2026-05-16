class Solution {
public:
    char repeatedCharacter(string s) {
       char ch='#';
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                ch=s[i];
                break;
            }
        }
        return ch;
    }
};