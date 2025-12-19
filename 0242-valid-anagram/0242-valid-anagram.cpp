class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> mp;

        // store all characters of s
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        // decrease count using t
        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]--;
            if (mp[t[i]] < 0)
                return false;
        }

        return true;
    }
};
