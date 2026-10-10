class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        bool isNegative = num < 0;
        int n = abs(num);

        string result="";

        while(n>0){
            
            int remainder=n%7;

            result+=to_string(remainder);

            n/=7;

        }

        if (isNegative) {
            result += "-";
        }

        reverse(result.begin(),result.end());

        return result;
    }
};