class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        //here map use for track that subaaray is >=2 length or not
        mp[0] = -1;   // base case

        long long sum = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            int rem = (k == 0) ? sum : sum % k;
            if(rem < 0) rem += k;

            if(mp.find(rem) != mp.end()) {
                if(i - mp[rem] >= 2) {
                    return true;
                }
            } else {
                mp[rem] = i;   // store first occurrence
            }
        }
        return false;
    }
};
