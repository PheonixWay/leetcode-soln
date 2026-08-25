class SmallestInfiniteSet {
public:
    int current_min; 
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> present_in_heap; 

    SmallestInfiniteSet() {
        current_min = 1;
    }
    
    int popSmallest() {

        if (!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            present_in_heap.erase(smallest);
            return smallest;
        }

        int smallest = current_min;
        current_min++;
        return smallest;

    }
    
    void addBack(int num) {
        if (num < current_min && present_in_heap.find(num) == present_in_heap.end()) {
            minHeap.push(num);
            present_in_heap.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */