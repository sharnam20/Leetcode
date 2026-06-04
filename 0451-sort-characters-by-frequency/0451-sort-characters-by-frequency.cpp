class Solution {
public:

    string frequencySort(string s) {

        // Step 1: Count frequency
        unordered_map<char,int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        // Step 2: Copy map into vector
        vector<pair<char,int>> vec;

        for(auto it : mp){
            vec.push_back(it);
        }

        // Step 3: Sort by frequency descending
        sort(vec.begin(), vec.end(),
            [](pair<char,int>& a, pair<char,int>& b){
                return a.second > b.second;
            });

        // Step 4: Build answer
        string ans = "";

        for(auto p : vec){
            ans += string(p.second, p.first);
        }

        return ans;
    }
};
    
