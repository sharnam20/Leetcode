class Solution {
public:
   int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;   // difference can't be negative

    sort(nums.begin(), nums.end());

    int i = 0, j = 1;
    int count = 0;

    while (j < nums.size()) {
        int diff = nums[j] - nums[i];

        if (diff == k) {
            count++;

            // skip duplicates for uniqueness
            int left = nums[i];
            int right = nums[j];

            while (i < nums.size() && nums[i] == left) i++;
            while (j < nums.size() && nums[j] == right) j++;
        }
        else if (diff > k) {
            i++;
        }
        else {
            j++;
        }

        if (i == j) j++;
    }
    return count;
}
};
