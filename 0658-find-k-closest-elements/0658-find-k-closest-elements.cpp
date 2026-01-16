class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();
        int start = 0, end = n - 1;

        // Binary search to find last element <= x
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] <= x)
                start = mid + 1;
            else
                end = mid - 1;
        }

        // Now:
        // end -> index of last element <= x
        int left = end;
        int right = end + 1;

        vector<int> ans;

        // Expand k times
        while (k--) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            }
            else if (right >= n) {
                ans.push_back(arr[left--]);
            }
            else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                ans.push_back(arr[left--]);
            }
            else {
                ans.push_back(arr[right++]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
