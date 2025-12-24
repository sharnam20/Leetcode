class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0;
        int j=0;
        int k=p.length();
        vector<int>ans;
        unordered_map<char,int>s1;
         unordered_map<char,int>p1;
         for(int m=0;m<k;m++){
            p1[p[m]]++;
         }

        while(j<s.length()){
              s1[s[j]]++;                
            
             if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
               if(s1==p1){
                ans.push_back(i);
               }
               s1[s[i]]--;
// most imp bcz in both map equal when char and key same so when char freq is 0than we remove char from that map
               if (s1[s[i]] == 0) {
                s1.erase(s[i]); 
                 }
               i++,j++;
        }
    }
    return ans;
    }
};