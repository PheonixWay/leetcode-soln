class Solution {
public:
    int palCounter(string & s,int left,int right){
        int count=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
            count+=1;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount=0;
        for(int i=0;i<s.size();i++){
            int oddValue=palCounter(s,i,i);
            int evenValue=palCounter(s,i,i+1);

            totalCount=totalCount+oddValue+evenValue;
        }

        return totalCount;
    }
};