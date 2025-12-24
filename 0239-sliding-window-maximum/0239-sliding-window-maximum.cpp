class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        deque<int> dq;

        while (j < nums.size()) {

            // remove all smaller elements from back
            while (!dq.empty() && nums[j] > dq.back()) {
                dq.pop_back();
            }

            // always push current element
            dq.push_back(nums[j]);

            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {

                // front always contains maximum
                ans.push_back(dq.front());

                // remove element going out of window
                if (dq.front() == nums[i]) {
                    dq.pop_front();
                }

                i++;
                j++;
            }
        }
        return ans;
    }
};
