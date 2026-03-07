class Solution {
public:
    pair<int,int> is_fixed_decimal(long long denominator){
        int count_5 = 0, count_2 = 0;
        while(denominator % 5 == 0){
            count_5++;
            denominator /= 5;
        }
        while(denominator % 2 == 0){
            count_2++;
            denominator /= 2;
        }
        if(denominator != 1){ // other prime factors remain
            return {0,0};
        }
        return {count_5, count_2};
    }

    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string ans = "";

        // Handle sign
        if((numerator < 0) ^ (denominator < 0)){
            ans += "-";
        }

        // Convert to positive long long
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        long long integer_part = num / den;
        ans += to_string(integer_part);

        long long remainder = num % den;
        if(remainder == 0) return ans; // no fractional part

        ans += ".";

        pair<int,int> x = is_fixed_decimal(den);

        if(x.first == 0 && x.second == 0){
            // repeating decimal case
            unordered_map<long long,int> seen;
            string frac = "";
            int pos = 0;
            while(remainder && !seen.count(remainder)){
                seen[remainder] = pos++;
                remainder *= 10;
                frac += to_string(remainder / den);
                remainder %= den;
            }
            if(remainder){ // repeating cycle found
                int start = seen[remainder];
                ans += frac.substr(0,start) + "(" + frac.substr(start) + ")";
            } else {
                ans += frac;
            }
        } else {
            // terminating decimal case
            while(remainder){
                remainder *= 10;
                ans += to_string(remainder / den);
                remainder %= den;
            }
        }

        return ans;
    }
};
