class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;  // slow pointer

        for (int j = 0; j < nums.size(); j++) {
            // allow first two elements always
            // after that, allow only if current != element two positions back
            if (i < 2 || nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
