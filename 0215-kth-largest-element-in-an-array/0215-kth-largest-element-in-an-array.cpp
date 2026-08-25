/*
 * Problem: 215. Kth Largest Element in an Array
 * 
 * Intuition & Approach:
 * We want the Kth largest element. If we maintain a Min-Heap of exact size K, 
 * we can push elements into it one by one. If the heap size exceeds K, we pop 
 * the smallest element (which will always be at the top of the Min-Heap).
 * By the time we finish the array, all the smaller elements will have been kicked out, 
 * leaving EXACTLY the K largest elements in the heap. 
 * The Kth largest element will be sitting right at the top!
 * 
 * Complexity:
 * - Time: O(N log K) where N is array size. Pushing into a heap of size K takes log K time.
 * - Space: O(K) because our VIP room (heap) never holds more than K elements.
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;

        for(int i =0 ; i<nums.size();i++){

            minHeap.push(nums[i]);

            if(minHeap.size()>k){
            minHeap.pop();
            }

        }

        return minHeap.top();
    }
};