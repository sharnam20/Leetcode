class Solution {
public:

    // ✅ Boolean feasibility function
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;   // flowers used once
                }
            } else {
                flowers = 0;       // adjacency breaks
            }
        }
        return bouquets >= m;
    }

    // ✅ Main function
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;   // try earlier day
            } else {
                low = mid + 1;    // need more days
            }
        }
        return ans;
    }
};
