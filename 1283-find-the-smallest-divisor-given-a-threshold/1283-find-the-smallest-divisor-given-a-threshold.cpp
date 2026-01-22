class Solution {
public:

    // ✅ Feasibility function
    bool isPossible(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor; // CEIL division
        }

        return sum <= threshold;
    }

    // ✅ Main function
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, threshold, mid)) {
                ans = mid;          // mid works
                high = mid - 1;     // try smaller divisor
            } else {
                low = mid + 1;      // need larger divisor
            }
        }
        return ans;
    }
};
