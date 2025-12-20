class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {

        int n = arr.size();
        
        vector<long long> prefix(n);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        unordered_map<int, int> mp;
        mp[0] = 1;   // base case

        int count = 0;

        for(int i = 0; i < n; i++) {
            int rem = prefix[i] % k;
            if(rem < 0) rem += k;  // handle negatives

            if(mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }
};

 