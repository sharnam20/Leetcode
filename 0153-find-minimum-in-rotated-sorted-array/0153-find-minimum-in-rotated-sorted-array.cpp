class Solution {
public:
    int findMin(vector<int>& arr) {

        int n = arr.size();
        int start = 0, end = n - 1;

        while (start <= end) {

            // already sorted
            if (arr[start] <= arr[end])
                return arr[start];

            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            // minimum element found
            if (arr[mid] < arr[next] && arr[mid] <arr[prev])
                return arr[mid];

            // left half sorted
            if (arr[mid] >= arr[start])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return 0;
    }
};

   