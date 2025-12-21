class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;   // prefix hashmap: value → index

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            // prefix check (have we seen 'need' before?)
            if (mp.count(need)) {
                return { mp[need], i };
            }

            // store current value as prefix
            mp[nums[i]] = i;
        }

        return {};
    }
};
