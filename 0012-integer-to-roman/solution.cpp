//Approach 2
//time complexity - O(1) since the algorithm always iterates through a constant number of values (13 in this case).
//O(1) since the amount of extra space used is constant (the size of the storeIntRoman vector, which is also 13 in this case
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[]= {"", "M", "MM", "MMM"};
        
        string Roman =  thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
        return Roman;
    }
};
