class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();

        // find first index
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        int first = start;

        // find last index
        start = 0; end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        int last = end;

        // collect indices
        for (int i = first; i <= last; i++) {
            if (i >= 0 && i < n && nums[i] == target)
                ans.push_back(i);
        }

        return ans;
    }
};
