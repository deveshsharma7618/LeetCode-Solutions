
// Define your custom structure
struct Pair {
    int onesCount; // We will use this field for the min-heap ordering
    int i;
};

// Create a custom comparator struct (functor)
struct ComparePair {
    // Returns true if 'a' has a lower priority than 'b' for a max-heap,
    // so reverse the logic (> instead of <) to make it a min-heap.
    bool operator()(const Pair& a, const Pair& b) {
        if(a.onesCount == b.onesCount){
            return a.i > b.i;
        }
        return a.onesCount > b.onesCount;
    }
};

class Solution {
public:
    int countOnes(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                count++;
            }
        }
        return count;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<Pair, vector<Pair>, ComparePair> minHeap;
        for (int i = 0; i < mat.size(); i++) {
            int onesCount = countOnes(mat[i]);
            minHeap.push({onesCount, i});
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(minHeap.top().i);
            minHeap.pop();
        }

        return ans;
    }
};
