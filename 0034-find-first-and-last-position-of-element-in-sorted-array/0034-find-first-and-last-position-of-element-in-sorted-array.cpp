class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();

        // 🔍 Find first occurrence
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        if (start == n || nums[start] != target)
            return ans;          // target not found

        ans[0] = start;

        // 🔍 Find last occurrence
        start = 0; end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        ans[1] = end;

        return ans;
    }
};
