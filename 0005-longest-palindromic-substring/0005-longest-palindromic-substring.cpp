class Solution {
public:
    int expandAroundCenter(string s,int left,int right){

        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        return right-left-1;
    }
    string longestPalindrome(string s) {
        
        if(s.size()<=1){
            return s;
        }
        int max_len=0;
        int start=0;

        for(int i=0;i<s.size();i++){

            int odd=expandAroundCenter(s,i,i);
            int even=expandAroundCenter(s,i,i+1);

            int curr_max=max(odd,even);

            if(curr_max>max_len){
                max_len=curr_max;
                start=i-(curr_max-1)/2;
            }

        }

        return s.substr(start,max_len);
    }
};