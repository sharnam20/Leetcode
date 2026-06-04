class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //s[i]=key,t[i]=value
        unordered_map<char,char>mp;
        unordered_set<char>usedcharaters;
        for(int i=0;i<s.length();i++){
            //if currunt elemnt alredy become key previous
            if(mp.find(s[i])!=mp.end()){
                //we check if that previous key ->value and cirrunt value is same or diffrent
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                //we cheack that currunt  value has some key or not 
                if(usedcharaters.count(t[i])){
                    return false;
                }
                mp[s[i]]=t[i];
                usedcharaters.insert(t[i]);
            }
        }
        return true;
    }
};