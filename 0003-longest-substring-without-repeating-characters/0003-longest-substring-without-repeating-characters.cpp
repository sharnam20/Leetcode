class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int maxi=0;
        unordered_map<char,int>mp;
        while(j<s.length()){
             mp[s[j]]++;
            if(mp[s[j]]==1){
               
                maxi=max(maxi,j-i+1);
                j++;
                }
            else if(mp[s[j]]>1){
               while(mp[s[j]]>1){
                mp[s[i]]--;
                 if(mp[s[i]]==0){
                       mp.erase(s[i]);
                     
                    }
                    i++;
               }
               j++;
        }
        }
      return maxi;  
    }
};