class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> maxHeap;

        for (int x : amount) {
            maxHeap.push(x);
        }

        int ans = 0;

        while (maxHeap.top() > 0) {
            int x1 = maxHeap.top() - 1;
            maxHeap.pop();
            int x2 = maxHeap.top() - 1;
            maxHeap.pop();

            maxHeap.push(x1);

            maxHeap.push(x2);
            ans++;
        }

        return ans;
    }
};
