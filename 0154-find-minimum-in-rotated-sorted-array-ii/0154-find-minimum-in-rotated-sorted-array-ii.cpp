class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {

            // already sorted
            if (arr[start] < arr[end])
                return arr[start];

            int mid = start + (end - start) / 2;

            // duplicate ambiguity case
            if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
                start++;
                end--;
               
            }

            // right half sorted → min is in left
           else  if (arr[mid] <= arr[end]){
                end = mid;}
            else{
                start = mid + 1;
        }

        
    }
    return arr[start];
    }
};
