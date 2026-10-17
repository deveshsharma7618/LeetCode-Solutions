class Solution {
public:
    int minimumSum(int num) {
        int ans;
        priority_queue<int, vector<int>, greater<int>> t;

        while(num){
            t.push(num%10);
            num /= 10;
        }

        int num1 = 0, num2 = 0;
        while(!t.empty()){
            num1 *= 10;
            num1 += t.top();

            t.pop();

            num2 *= 10;
            num2 += t.top();

            t.pop();
        }

        return num1 + num2;
    }
};