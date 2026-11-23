class ProductOfNumbers {
public:
    vector<long long> pre;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            pre.clear();
            return;
        }
        int n = pre.size();
        if (!pre.empty()) {
            pre.push_back(pre[n - 1] * num);
        }else{
            pre.push_back(num);
        }
    }

    int getProduct(int k) {
        int n = pre.size();
        if( n == k){
            return pre[n-1];
        }

        if (pre.empty() || n - k - 1 < 0) {
            return 0;
        }

        return pre[n - 1] / pre[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */