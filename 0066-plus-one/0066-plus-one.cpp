class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int i= d.size()-1;
        int carry = 1;
        while(i>=0){
            if(d[i]+carry > 9){
                d[i]=0;
                i--;
            }else{
                d[i]=d[i]+1;
                return d;
            }
        }
        if(d[0]==0){
            d.insert(d.begin() , 1);
        }
        return d;
    }
};