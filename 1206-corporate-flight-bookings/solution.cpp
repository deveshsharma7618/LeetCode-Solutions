class Solution {
public:

    void add_val(vector<int>& x, int v, int l, int r){
       
       x[l] += v;
       if(r + 1 < x.size()){
           x[r+1] -= v;
       }
       
    }    

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> temp(n,0);
        
        for(int i=0;i<bookings.size();i++){
            add_val(temp, bookings[i][2], bookings[i][0]-1, bookings[i][1]-1);
        }
        
        for(int i=1;i<n;i++){
            temp[i] += temp[i-1];
        }
        
        return temp;
    }
};
