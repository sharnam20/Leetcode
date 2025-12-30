class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        vector<int> ans(n);
        int idx = n - 1;

        while (l <= r) {
            int leftSq = nums[l] * nums[l];
            int rightSq = nums[r] * nums[r];

            if (leftSq > rightSq) {
                ans[idx] = leftSq;
                l++;
            } else {
                ans[idx] = rightSq;
                r--;
            }
            idx--;
        }

        return ans;
    }
};
