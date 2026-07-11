class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
      int left = 0, right = arr.size() - 1;
      int mid;
  //main logic is if pair is start from even than its normal if some single elemt arrived after all pair starting to odd index that it
    while (left < right) {
         mid = (left + right) / 2;
        
        //if mid is even than check its next if same menas left side is not have single elemnet
        if(mid%2==0){
           if(arr[mid]==arr[mid+1]){
             //go to right
             left=mid+2;
           }
           else{
            right=mid-1;
           }
        }
        //if mid is on odd than check its prev has same value if yes so again go to right bcz left has no single eelment
        else{
           if(arr[mid]==arr[mid-1]){
             //go to right
             left=mid+1;
           }
           else{
            right=mid-1;
           }
        }
    }
    return arr[left];
    }
};