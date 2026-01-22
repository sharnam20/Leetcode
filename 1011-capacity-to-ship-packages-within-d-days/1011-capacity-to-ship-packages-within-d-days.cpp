class Solution {
public:

    // Check if we can ship within given days using this capacity
    bool canShip(vector<int>& weights, int days, int capacity) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (currentLoad + weights[i] <= capacity) {
                currentLoad += weights[i];
            } else {
                dayCount++;              // go to next day
                currentLoad = weights[i];
            }
        }
        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;

        // find low (max element) and high (sum)
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > low) {
                low = weights[i];
            }
            high += weights[i];
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller capacity
            } else {
                low = mid + 1;    // need bigger capacity
            }
        }
        return ans;
    }
};
