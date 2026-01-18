/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // 1️⃣ Find Peak Index
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }
        int peak = low;

        // 2️⃣ Binary Search on Left (Ascending)
        int left = 0, right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;
            else if (val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // 3️⃣ Binary Search on Right (Descending)
        left = peak + 1;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;
            else if (val > target)
                left = mid + 1;   // reverse comparison
            else
                right = mid - 1;
        }

        return -1;
    }
};
