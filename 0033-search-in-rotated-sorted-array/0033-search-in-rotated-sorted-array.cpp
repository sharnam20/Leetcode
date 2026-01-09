class Solution {
public:
    int search(std::vector<int>& nums, int target) { 
        int n = nums.size();

        // Step 2: Binary search for target

        int left = 0, right = n - 1, mid;

        while (left <= right) {
            // check sort left or right
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
           if(nums[left]<=nums[mid]){ 
            if(nums[left]<=target && target<=nums[mid]){
                  right=mid-1;
            }else{
                left=mid+1;
            }
           }
           else{
            if(nums[mid]<=target && target<=nums[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
           }
        }
        return -1;
    }

  
};
