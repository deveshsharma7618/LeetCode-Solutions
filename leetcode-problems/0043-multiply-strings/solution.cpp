class Solution {
public:
    string sum_string(vector<string>& x) {
    string ans = "";
    int max_length = 0;

    for (int i = 0; i < x.size(); i++) {
        max_length = max(max_length, (int)x[i].size());
    }

    int carry = 0;
    for (int i = 0; i < max_length; i++) {
        int sum = carry;

        for (int j = 0; j < x.size(); j++) {
            if (i < x[j].size()) {
                sum += x[j][i] - '0';
            }
        }

        ans += (sum % 10) + '0';
        carry = sum / 10;
    }

    while (carry) {
        ans += (carry % 10) + '0';
        carry /= 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
    string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    if (num1.size() < num2.size()) {
        return multiply(num2, num1);
    }

    int n1 = num1.size();
    int n2 = num2.size();
    int i = n2 - 1;

    vector<string> temp;

    while (i >= 0) {
        int carry = 0;          // FIX 1
        int j = n1 - 1;
        string d = "";

        // shift zeros
        for (int t = 0; t < n2 - i - 1; t++) {
            d += '0';
        }

        int a = num2[i] - '0';

        while (j >= 0) {
            int b = num1[j] - '0';
            int p = a * b + carry;
            d += (p % 10) + '0';
            carry = p / 10;
            j--;
        }

        while (carry != 0) {
            d += (carry % 10) + '0';
            carry /= 10;
        }

        temp.push_back(d);
        i--;
    }

    return sum_string(temp);
    }
};
