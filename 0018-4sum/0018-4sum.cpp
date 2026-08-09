class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> result;
        int n=nums.size();

        if(nums.size()<4) return result;


        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){

            if(i>0 && nums[i]==nums[i-1]) continue;

            // OPTIMIZATION 1: Too Big (Early Exit)
            // If the current number + the 3 smallest remaining numbers > target, 
            // then any other combination will also be too big. Stop the loop.
            long long min_sum_i = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if (min_sum_i > target) break;
            
            // OPTIMIZATION 2: Too Small (Skip Forward)
            // If the current number + the 3 largest numbers in the array < target,
            // then the current number is too small to work. Skip to the next 'i'.
            long long max_sum_i = (long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
            if (max_sum_i < target) continue;


            for(int j=i+1;j<n-2;j++){

                int left=j+1;
                int right=n-1;

                if(j>i+1 && nums[j]==nums[j-1]) continue;

                // OPTIMIZATION 3: Too Big for 'j'
                long long min_sum_j = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if (min_sum_j > target) break;
                
                // OPTIMIZATION 4: Too Small for 'j'
                long long max_sum_j = (long long)nums[i] + nums[j] + nums[n-1] + nums[n-2];
                if (max_sum_j < target) continue;

                

                while(left<right){
                    long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;

                        while(left<right && nums[left]==nums[left-1]) left++;
                        while(left<right && nums[right]==nums[right+1]) right--;
                    }else if(sum>target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }

        return result;
    }
};