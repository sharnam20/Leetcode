class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char,int> t1, s1;
        for(char c : t) t1[c]++;

        int i = 0, j = 0;
        int matched = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        while(j < s.size()){

            s1[s[j]]++;

            // only count match if character exists in t
            if(t1.count(s[j]) && s1[s[j]] == t1[s[j]])
                matched++;

            // shrink window once fully matched
            while(matched == (int)t1.size()){
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    startIndex = i;
                }

                // shrinking logic
                if(t1.count(s[i]) && s1[s[i]] == t1[s[i]])
                    matched--;

                s1[s[i]]--;
                i++;
            }

            j++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIndex, minLen);
    }
};
