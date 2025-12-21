class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>unique_element;
        vector<int>ans;
        for (int i = 0; i < nums1.size(); i++) {
        unique_element.insert(nums1[i]);
    }
     for(int i=0;i<nums2.size();i++){
        if( unique_element.count(nums2[i])){
            ans.push_back(nums2[i]);
            unique_element.erase(nums2[i]); // ⭐ prevents duplicates
        }
     }
     return ans;
    }
};