class Solution {
public:
    bool isSubstract(int i, string s, char ch){
        for(int k = i+1; k < s.size(); k++){
            if(s[k] == ch){
                return true;
            }
        }
        return false;
    }
    int romanToInt(string s) {
        int number = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            switch(s[i]){
                case 'I':
                    if( isSubstract(i, s, 'V') || isSubstract(i,s,'X')){
                        number -= 1;
                    }else{
                        number += 1;
                    }
                    break;
                case 'V':
                    number += 5;
                    break;
                case 'X':
                    if( isSubstract(i, s, 'L') || isSubstract(i,s,'C')){
                        number -= 10;
                    }else{
                        number += 10;
                    }
                    break;
                case 'L':
                    number += 50;
                    break;
                
                case 'C':
                    if( isSubstract(i, s, 'D') || isSubstract(i,s,'M')){
                        number -= 100;
                    }else{
                        number += 100;
                    }
                    break;
                case 'D':
                    number += 500;
                    break;
                case 'M':
                    number += 1000;
                    break;
                          
            }
        }
        return number;
    }
};
