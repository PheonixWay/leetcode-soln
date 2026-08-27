class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> pairs(n);

        for(int i=0;i<n;i++){
            pairs[i]={nums2[i],nums1[i]};
        }

        sort(pairs.rbegin(),pairs.rend());

        priority_queue<int,vector<int>,greater<int>> minHeap;
        long long currentSum=0;
        long long maxSum=0;

        for(int i=0;i<n;i++){
            int nums2Value=pairs[i].first;
            int nums1Value=pairs[i].second;

            minHeap.push(nums1Value);
            currentSum+=nums1Value;

            if(minHeap.size() > k) {
                currentSum -= minHeap.top();
                minHeap.pop();               
            }

            if(minHeap.size() == k) {
                maxSum = max(maxSum, currentSum * nums2Value);
            }
        }

        return maxSum;

    }
};