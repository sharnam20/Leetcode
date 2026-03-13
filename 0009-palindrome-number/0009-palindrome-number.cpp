class Solution {
public:
    bool isPalindrome(int x) {
        long  result=0;
        int origin=x;
        
      if(x<0)
      {
        return false;
      }
      while(x>0){
           int result1=x%10;

         result = result*10+result1;
           
           x=x/10;
      }
        return result==origin;
       
        
    }
};