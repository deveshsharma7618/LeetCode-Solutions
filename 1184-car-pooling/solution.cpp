class Solution {
public:
    
    void add_val(vector<int>& x, int v, int l, int r){
       
       x[l] += v;
       if(r + 1 < x.size()){
           x[r+1] -= v;
       }
       
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> temp(1001, 0);
        for(int i=0;i<trips.size();i++){
            add_val(temp, trips[i][0], trips[i][1], trips[i][2]-1);
        }
        
        if (temp[0] > capacity)
            return false;
            
        for(int i=1;i<1001;i++){
            temp[i] += temp[i-1];
            if(temp[i] > capacity){
                return false;
            }
            
        }
        return true;
    }
};
